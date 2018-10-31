/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/nodes/vk_acquire_swapchain_image_node.h"
#include "OpenGL/backend/vk_swapchain_manager.h"

#ifdef max
    #undef max
#endif

#ifdef min
    #undef min
#endif

OpenGL::VKFrameGraph::GroupNode::~GroupNode()
{
    graph_node_ptrs.clear                     ();
    input_ptrs.clear                          ();
    node_io_ptr_to_group_node_io_ptr_map.clear();
    output_ptrs.clear                         ();
}

void OpenGL::VKFrameGraph::GroupNode::add_io(const OpenGL::NodeIO& in_io,
                                             const bool&           in_is_input)
{
    /* Check if the base object behind the IO is already exposed .. */
    auto& group_node_io_ptrs = (in_is_input) ? input_ptrs
                                             : output_ptrs;

    for (auto& current_group_node_io_ptr : group_node_io_ptrs)
    {
        if (current_group_node_io_ptr->type != in_io.type)
        {
            continue;
        }

        switch (in_io.type)
        {
            case OpenGL::NodeIOType::Buffer:
            {
                /* For transfer ownership purposes, we need to ensure start-end region touched by the group node corresponds
                 * to the whole region accessed by subnodes. */
                current_group_node_io_ptr->buffer_props.start_offset = std::min(current_group_node_io_ptr->buffer_props.start_offset,
                                                                                in_io.buffer_props.start_offset);
                current_group_node_io_ptr->buffer_props.size         = std::max(current_group_node_io_ptr->buffer_props.size,
                                                                                in_io.buffer_props.size);

                goto end;
            }

            case OpenGL::NodeIOType::Image:
            {
                vkgl_not_implemented();

                goto end;
            }

            case OpenGL::NodeIOType::Swapchain_Image:
            {
                /* For transfer ownership purposes, we need to ensure all touched "aspects" of the swapchain image are referenced. */
                current_group_node_io_ptr->swapchain_image_props.aspect |= in_io.swapchain_image_props.aspect;

                goto end;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }

    /* A new IO is needed. */
    group_node_io_ptrs.push_back(
        NodeIOUniquePtr(new NodeIO(in_io),
                        std::default_delete<NodeIO>() )
    );

    vkgl_assert(node_io_ptr_to_group_node_io_ptr_map.find(&in_io) == node_io_ptr_to_group_node_io_ptr_map.end() );
    node_io_ptr_to_group_node_io_ptr_map[&in_io] = group_node_io_ptrs.back().get();
end:
    ;
}

OpenGL::VKFrameGraph::VKFrameGraph(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                                   const OpenGL::IBackend*               in_backend_ptr)
    :m_acquired_swapchain_image_index(UINT32_MAX),
     m_backend_ptr                   (in_backend_ptr),
     m_frontend_ptr                  (in_frontend_ptr),
     m_swapchain_acquire_sem_ptr     (nullptr)
{
    vkgl_assert(in_backend_ptr != nullptr);
}

OpenGL::VKFrameGraph::~VKFrameGraph()
{
    /* Stub */
}

void OpenGL::VKFrameGraph::add_node(OpenGL::VKFrameGraphNodeUniquePtr in_node_ptr)
{
    std::lock_guard<std::mutex> lock(m_general_mutex);

    m_node_ptrs.push_back(
        std::move(in_node_ptr)
    );
}

bool OpenGL::VKFrameGraph::coalesce_to_group_nodes(const std::vector<VKFrameGraphNodeUniquePtr>&                          in_node_ptrs,
                                                   std::vector<GroupNodeUniquePtr>*                                       out_group_nodes_ptr,
                                                   std::unordered_map<const GroupNode*, std::vector<const GroupNode* > >* out_src_dst_group_node_connections_ptr)
{
    auto current_group_node_ptr = GroupNodeUniquePtr(nullptr,
                                                     std::default_delete<GroupNode>() );
    bool result                 = false;

    for (const auto& current_node_ptr : in_node_ptrs)
    {
        const auto                        current_node_info_ptr                       = current_node_ptr->get_info_ptr                 ();
        const bool                        current_node_requires_cpu_side_execution    = current_node_ptr->requires_cpu_side_execution  ();
        const bool                        current_node_requires_gpu_side_execution    = current_node_ptr->requires_gpu_side_execution  ();
        const bool                        current_node_requires_manual_wait_sem_sync  = current_node_ptr->requires_manual_wait_sem_sync();
        const bool                        current_node_supports_1st_level_cmd_buffers = (current_node_requires_gpu_side_execution) ? current_node_ptr->supports_primary_command_buffers()
                                                                                                                                   : false;
        const bool                        current_node_supports_2nd_level_cmd_buffers = (current_node_requires_gpu_side_execution) ? current_node_ptr->supports_secondary_command_buffers()
                                                                                                                                   : false;
        const bool                        current_node_supports_renderpasses          = (current_node_requires_gpu_side_execution) ? current_node_ptr->supports_renderpasses()
                                                                                                                                   : false;
        const Anvil::QueueFamilyFlagBits* current_node_accepted_queue_fams_ptr        = nullptr;
        uint32_t                          current_node_n_accepted_queue_fams          = 0;
        bool                              current_node_supports_compute_queues        = false;
        bool                              current_node_supports_dma_queues            = false;
        bool                              current_node_supports_universal_queues      = false;

        if (current_node_requires_gpu_side_execution)
        {
            current_node_ptr->get_supported_queue_families(&current_node_n_accepted_queue_fams,
                                                           &current_node_accepted_queue_fams_ptr);

            /* Sanity checks */
            vkgl_assert(current_node_supports_1st_level_cmd_buffers || current_node_supports_2nd_level_cmd_buffers);
            vkgl_assert(current_node_n_accepted_queue_fams          != 0);
            vkgl_assert(current_node_accepted_queue_fams_ptr        != nullptr);
        }

        for (uint32_t n_queue_fam = 0;
                      n_queue_fam < current_node_n_accepted_queue_fams;
                    ++n_queue_fam)
        {
            switch (current_node_accepted_queue_fams_ptr[n_queue_fam])
            {
                case Anvil::QueueFamilyFlagBits::COMPUTE_BIT:  current_node_supports_compute_queues   = true; break;
                case Anvil::QueueFamilyFlagBits::DMA_BIT:      current_node_supports_dma_queues       = true; break;
                case Anvil::QueueFamilyFlagBits::GRAPHICS_BIT: current_node_supports_universal_queues = true; break;

                default:
                {
                    vkgl_assert_fail();
                }
            }
        }

        if (current_node_requires_manual_wait_sem_sync)
        {
            /* Manual wait sem sync requirements implies the node needs to be contained within a dedicated group node.
             *
             * This is due to VK requirement where any semaphores we use for a wait op must have already been signalled OR
             * have a pending signal op. This can only be achieved by submitting a signalling cmd buffer prior to letting
             * the node perform its operation */
            if (current_group_node_ptr != nullptr)
            {
                out_group_nodes_ptr->push_back(std::move(current_group_node_ptr) );

                current_group_node_ptr = GroupNodeUniquePtr(nullptr,
                                                            std::default_delete<GroupNode>() );
            }

            current_group_node_ptr.reset(new GroupNode(Anvil::QueueFamilyFlagBits::NONE) );
            vkgl_assert(current_group_node_ptr != nullptr);

            vkgl_assert( current_node_requires_cpu_side_execution);
            vkgl_assert(!current_node_requires_gpu_side_execution);

            for (const auto& current_input : current_node_info_ptr->inputs)
            {
                current_group_node_ptr->input_ptrs.push_back(
                    OpenGL::NodeIOUniquePtr(new OpenGL::NodeIO(current_input),
                                            std::default_delete<OpenGL::NodeIO>() )
                );
            }

            for (const auto& current_output : current_node_info_ptr->outputs)
            {
                current_group_node_ptr->output_ptrs.push_back(
                    OpenGL::NodeIOUniquePtr(new OpenGL::NodeIO(current_output),
                                            std::default_delete<OpenGL::NodeIO>() )
                );
            }

            current_group_node_ptr->graph_node_ptrs.push_back(current_node_ptr.get() );

            out_group_nodes_ptr->push_back(std::move(current_group_node_ptr) );

            continue;
        }
        else
        {
            /* TODO. Requires fence-based resource-level synchronization. */
            vkgl_assert(!current_node_requires_cpu_side_execution);
        }

        /* If no group node is currently being processed, spawn one. */
        if (current_group_node_ptr == nullptr)
        {
            current_group_node_ptr.reset(new GroupNode() );

            vkgl_assert(current_group_node_ptr != nullptr);
        }

        /* Next, we need to decide when it is actually sensible to coalesce input nodes into as single group node.
         * For now, follow the following heuristics:
         *
         * 1. If a node supports DMA queue, make sure to offload the operations there.
         * 2. If a node supports compute queue, make sure to use it.
         * 3. Otherwise, use universal queue.
         *
         * In specific, ignore the preferred order reported by nodes. At least for now.
         *
         * TODO: Once node reshuffling is introduced, this should actually become performant. For now, I'm expecting
         *       this logic to create a flurry of command buffers. Oh well.
         */
        const Anvil::QueueFamilyFlagBits required_queue_family_type = (current_node_supports_dma_queues)       ? Anvil::QueueFamilyFlagBits::DMA_BIT
                                                                    : (current_node_supports_compute_queues)   ? Anvil::QueueFamilyFlagBits::COMPUTE_BIT
                                                                    : (current_node_supports_universal_queues) ? Anvil::QueueFamilyFlagBits::GRAPHICS_BIT
                                                                                                               : Anvil::QueueFamilyFlagBits::NONE;

        vkgl_assert(( current_node_requires_gpu_side_execution && required_queue_family_type != Anvil::QueueFamilyFlagBits::NONE) ||
                    (!current_node_requires_gpu_side_execution && required_queue_family_type == Anvil::QueueFamilyFlagBits::NONE) );

        if (current_group_node_ptr->queue_family == Anvil::QueueFamilyFlagBits::NONE)
        {
            current_group_node_ptr->queue_family = required_queue_family_type;
        }
        else
        if (current_group_node_ptr->queue_family != required_queue_family_type)
        {
            /* Push out currently processed node and spawn a new one. */
            out_group_nodes_ptr->push_back(std::move(current_group_node_ptr) );

            current_group_node_ptr.reset(new GroupNode(required_queue_family_type) );
            vkgl_assert(current_group_node_ptr != nullptr);
        }

        /* This group node can accomodate the new input node. Put it in and merge input node's IOs.. */
        current_group_node_ptr->graph_node_ptrs.push_back(current_node_ptr.get() );

        for (const auto& current_input : current_node_info_ptr->inputs)
        {
            current_group_node_ptr->add_io(current_input,
                                           true /* is_input */);
        }

        for (const auto& current_output : current_node_info_ptr->outputs)
        {
            current_group_node_ptr->add_io(current_output,
                                           false /* is_input */);
        }
    }

    /* Now wire up the group nodes, based on IO information exposed by input nodes ..
     *
     * Let's start from node output<->node input connections. These are per-VK output->input object associations which are going to be
     * used as a basis for forming buffer / image barriers
     */
    {
        struct OutputData
        {
            const OpenGL::NodeIO* group_node_output_ptr;
            const GroupNode*      group_node_ptr;

            OutputData()
                :group_node_output_ptr(nullptr),
                 group_node_ptr       (nullptr)
            {
                /* Stub */
            }

            OutputData(const GroupNode*      in_group_node_ptr,
                       const OpenGL::NodeIO* in_group_node_output_ptr)
                :group_node_output_ptr(in_group_node_output_ptr),
                 group_node_ptr       (in_group_node_ptr)
            {
                /* Stub */
            }
        };

        OutputData                                  last_swapchain_output_data;
        std::unordered_map<const void*, OutputData> object_ptr_to_last_output_data_map;

        for (auto& current_group_node_ptr : *out_group_nodes_ptr)
        {
            /* Only parse inputs if at least one output has already been processed */
            if (last_swapchain_output_data.group_node_ptr != nullptr ||
                object_ptr_to_last_output_data_map.size() != 0)
            {
                uint32_t n_dst_group_node_input = 0;

                for (const auto& current_group_node_input_ptr : current_group_node_ptr->input_ptrs)
                {
                    switch (current_group_node_input_ptr->type)
                    {
                        case OpenGL::NodeIOType::Buffer:
                        {
                            auto object_ptr_map_iterator = object_ptr_to_last_output_data_map.find(current_group_node_input_ptr->buffer_reference_ptr->get_payload().buffer_ptr);

                            if (object_ptr_map_iterator                        != object_ptr_to_last_output_data_map.end() &&
                                object_ptr_map_iterator->second.group_node_ptr != current_group_node_ptr.get            () )
                            {
                                /* Object reuse - add a connection */
                                auto dst_group_node_ptr    = current_group_node_ptr.get();
                                auto src_group_node_ptr    = object_ptr_map_iterator->second.group_node_ptr;
                                auto src_group_node_io_ptr = object_ptr_map_iterator->second.group_node_output_ptr;
                                auto new_connection_ptr    = GroupNodeConnectionInfoUniquePtr(nullptr,
                                                                                              std::default_delete<GroupNodeConnectionInfo>() );

                                new_connection_ptr.reset(
                                    new GroupNodeConnectionInfo(src_group_node_ptr,
                                                                src_group_node_io_ptr,
                                                                n_dst_group_node_input)
                                );

                                /* Also cache the general src->dst node connection. Avoid caching duplicate entries  */
                                if (std::find((*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].begin(),
                                              (*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].end(),
                                              dst_group_node_ptr) == (*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].end() )
                                {
                                    (*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].push_back(dst_group_node_ptr);
                                }
                            }

                            break;
                        }

                        case OpenGL::NodeIOType::Swapchain_Image:
                        {
                            if (last_swapchain_output_data.group_node_ptr != current_group_node_ptr.get() )
                            {
                                /* Object reuse - add a connection */
                                auto dst_group_node_ptr    = current_group_node_ptr.get();
                                auto src_group_node_ptr    = last_swapchain_output_data.group_node_ptr;
                                auto src_group_node_io_ptr = last_swapchain_output_data.group_node_output_ptr;
                                auto new_connection_ptr    = GroupNodeConnectionInfoUniquePtr(nullptr,
                                                                                              std::default_delete<GroupNodeConnectionInfo>() );

                                new_connection_ptr.reset(
                                    new GroupNodeConnectionInfo(src_group_node_ptr,
                                                                src_group_node_io_ptr,
                                                                n_dst_group_node_input)
                                );

                                /* Also cache the general src->dst node connection. Avoid caching duplicate entries  */
                                if (std::find((*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].begin(),
                                              (*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].end(),
                                              dst_group_node_ptr) == (*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].end() )
                                {
                                    (*out_src_dst_group_node_connections_ptr)[src_group_node_ptr].push_back(dst_group_node_ptr);
                                }
                            }

                            break;
                        }

                        default:
                        {
                            vkgl_assert_fail();
                        }
                    }

                    ++n_dst_group_node_input;
                }
            }

            /* Move on to outputs */
            for (const auto& current_group_node_output_ptr : current_group_node_ptr->output_ptrs)
            {
                switch (current_group_node_output_ptr->type)
                {
                    case OpenGL::NodeIOType::Buffer:
                    {
                        /* Update the map */
                        #ifdef _DEBUG
                        {
                            auto map_iterator = object_ptr_to_last_output_data_map.find(current_group_node_output_ptr->buffer_reference_ptr->get_payload().buffer_ptr);

                            if (map_iterator != object_ptr_to_last_output_data_map.end() )
                            {
                                /* Sanity check: Only one output pointing to a specific buffer instance should be assigned per node */
                                vkgl_assert(map_iterator->second.group_node_ptr != current_group_node_ptr.get() );
                            }
                        }
                        #endif

                        object_ptr_to_last_output_data_map[current_group_node_output_ptr->buffer_reference_ptr->get_payload().buffer_ptr] = OutputData(current_group_node_ptr.get       (),
                                                                                                                                                       current_group_node_output_ptr.get() );

                        break;
                    }

                    case OpenGL::NodeIOType::Swapchain_Image:
                    {
                        /* Update the user data object */
                        #ifdef _DEBUG
                        {
                            /* Sanity check: Only one swapchain image output should be assigned per node */
                            vkgl_assert(last_swapchain_output_data.group_node_ptr != current_group_node_ptr.get() );
                        }

                        #endif

                        last_swapchain_output_data = OutputData(current_group_node_ptr.get        (),
                                                                current_group_node_output_ptr.get() );

                        break;
                    }

                    default:
                    {
                        vkgl_assert_fail();
                    }
                }
            }
        }
    }

    result = true;
end:
    return result;
}

OpenGL::VKFrameGraphUniquePtr OpenGL::VKFrameGraph::create(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                                                           const OpenGL::IBackend*               in_backend_ptr)
{
    OpenGL::VKFrameGraphUniquePtr result_ptr(nullptr,
                                             [](OpenGL::VKFrameGraph* in_ptr){ delete in_ptr; });

    result_ptr.reset(
        new OpenGL::VKFrameGraph(in_frontend_ptr,
                                 in_backend_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    if (result_ptr != nullptr)
    {
        /* Nothing to do for now. */
    }

    return result_ptr;
}

void OpenGL::VKFrameGraph::execute(const bool& in_block_until_finished)
{
    /* NOTE: This function must NEVER be called from app's rendering thread. */
    std::lock_guard<std::mutex>     execute_lock(m_execute_mutex);

    std::unordered_map<const GroupNode*, std::vector<const GroupNode*> > group_node_connections;
    std::vector<GroupNodeUniquePtr>                                      group_node_ptrs;
    decltype(m_node_ptrs)                                                node_ptrs;

    /* Cache node data, so that apps can continue rendering subsequent frames while we do the GL->VK conversion */
    {
        std::lock_guard<std::mutex> node_lock(m_general_mutex);

        if (m_node_ptrs.size() == 0)
        {
            goto end;
        }

        node_ptrs = std::move(m_node_ptrs);
    }

    /* NOTE: This is an extremely naive implementation. Once more complex examples are proven to work
     *       and a better understanding of actual architectural requirements is made, this code is expected
     *       to be rewritten (possibly many times).
     *
     *       Things which are already planned to be taken into account:
     *
     *       - Command buffer reuse.
     *       - Multi-threading             (CPU prepasses should be executed as thread pool jobs, layout/pipeline objects
     *                                      should be created using multiple threads, etc.)
     *       - Node reshuffling+clustering (as an example, transfer operations touching the same image should be clustered
     *                                      and submitted to a sDMA queue if only feasible).
     *
     *       For now, the goal is to get to a point where simple example apps work. This will give us a starting point,
     *       where we can compare performance of different architectures.
     *
     * TODO: This function should not block backend's main thread. The reason is there's technically no reason to block
     *       GL API calls to keep coming in into the backend layer while we convert accumulated nodes into an actual stream
     *       of VK commands. Instead, we should - at the very least - move this work chunk to one of the backend's worker threads
     *       and ensure subsequent executions are not scheduled for GPU execution BEFORE this execute() call finishes (mind the wait-after-signal
     *       requirement in core VK!). However, doing so paves way for very subtle yet disastrous errors related to multithreading, so
     *       this work needs to be postponed after we have a functional prototype of the frame graph available.
     */

    /* 0. If NO swapchain is acquired at any point in the graph and currently processed node claims it needs one, prepend
     *    the node with acquire node.
     *
     *    NOTE: Present operations are explicit in (W)GL but there is no equivalent of frame acquisition in GL, which is why
     *          we need this step.
     **/
    if (!inject_swapchain_acquire_nodes(node_ptrs) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* 1. Execute CPU prepasses for nodes which require doing so. */
    if (!execute_cpu_prepass(node_ptrs) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* 2. Determine which nodes can be squashed into a single command buffer.
     *
     *    First input occurence for each unique buffer range / image subresource should be exposed as an input of the group node.
     *    Last output occurence for each unique buffer range / image subresource should be exposed as an output of the group node.
     *
     *    Then, convert the "sequential" input call representation into a DAG where each node is a group node obtained in step 2.
     **/
    if (!coalesce_to_group_nodes(node_ptrs,
                                &group_node_ptrs,
                                &group_node_connections) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* 3. Record command buffers for group nodes. Make sure to inject the required barriers accordingly using DAG info
     *    prepared in previous step.
     */

    /* 4. Schedule command buffer submissions. */

    /* 5. Update layout, ownership, etc. information for buffer ranges and image subresources touched by the submissions. */

    /* 6. If this was requested, wait for the GPU-side operations to finish before leaving. */

    vkgl_not_implemented();

end:
    group_node_ptrs.clear       ();
    group_node_connections.clear();
    node_ptrs.clear             ();
}

bool OpenGL::VKFrameGraph::execute_cpu_prepass(const std::vector<VKFrameGraphNodeUniquePtr>& in_node_ptrs)
{
    for (auto& current_node_ptr : in_node_ptrs)
    {
        if (current_node_ptr->requires_cpu_prepass() )
        {
            current_node_ptr->do_cpu_prepass(this);
        }
    }

    return true;
}

uint32_t OpenGL::VKFrameGraph::get_acquired_swapchain_image_index() const
{
    vkgl_assert(m_acquired_swapchain_image_index != UINT32_MAX);

    return m_acquired_swapchain_image_index;
}

Anvil::Semaphore* OpenGL::VKFrameGraph::get_swapchain_image_acquired_sem() const
{
    vkgl_assert(m_swapchain_acquire_sem_ptr != nullptr);

    return m_swapchain_acquire_sem_ptr;
}

bool OpenGL::VKFrameGraph::get_wait_sems(uint32_t*                         out_n_wait_sems_ptr,
                                         Anvil::Semaphore**                out_wait_sems_ptr_ptr,
                                         const Anvil::PipelineStageFlags** out_wait_sem_stage_masks_ptr)
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::VKFrameGraph::inject_swapchain_acquire_nodes(std::vector<VKFrameGraphNodeUniquePtr>& inout_node_ptrs)
{
    bool     is_swapchain_image_acquired = (m_acquired_swapchain_image_index != UINT32_MAX);
    uint32_t n_nodes                     = static_cast<uint32_t>(inout_node_ptrs.size() );
    bool     result                      = false;

    for (uint32_t n_current_node = 0;
                  n_current_node < n_nodes;
                ++n_current_node)
    {
        auto&      current_node_ptr      = inout_node_ptrs.at            (n_current_node);
        const auto current_node_info_ptr = current_node_ptr->get_info_ptr();
        const auto current_node_type     = current_node_ptr->get_type    ();
        bool       needs_swapchain_image = false;

        vkgl_assert(current_node_type != FrameGraphNodeType::Acquire_Swapchain_Image);

        if (current_node_type == FrameGraphNodeType::Present_Swapchain_Image)
        {
            vkgl_assert(is_swapchain_image_acquired);

            is_swapchain_image_acquired = false;
        }
        else
        {
            for (const auto& current_input : current_node_info_ptr->inputs)
            {
                if (current_input.type == NodeIOType::Swapchain_Image)
                {
                    needs_swapchain_image = true;

                    break;
                }
            }

            if (!needs_swapchain_image)
            {
                for (const auto& current_output : current_node_info_ptr->outputs)
                {
                    if (current_output.type == NodeIOType::Swapchain_Image)
                    {
                        needs_swapchain_image = true;

                        break;
                    }
                }
            }

            if ( needs_swapchain_image       &&
                !is_swapchain_image_acquired)
            {
                auto swapchain_manager_ptr = m_backend_ptr->get_swapchain_manager_ptr      ();
                auto new_acquire_node_ptr  = OpenGL::VKNodes::AcquireSwapchainImage::create(m_frontend_ptr,
                                                                                            m_backend_ptr,
                                                                                            swapchain_manager_ptr->acquire_swapchain(swapchain_manager_ptr->get_tot_time_marker() ));

                inout_node_ptrs.insert(inout_node_ptrs.begin() + n_current_node,
                                       std::move(new_acquire_node_ptr) );

                is_swapchain_image_acquired = true;
            }
        }
    }

    result = true;
    return result;
}

void OpenGL::VKFrameGraph::on_buffer_deleted(Anvil::Buffer* in_buffer_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKFrameGraph::on_image_deleted(Anvil::Image* in_image_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKFrameGraph::set_acquired_swapchain_image_index(const uint32_t& in_index)
{
    vkgl_assert(in_index                         >= 0                                                                    &&
                in_index                         <  m_backend_ptr->get_swapchain_manager_ptr()->get_n_swapchain_images() );
    vkgl_assert(m_acquired_swapchain_image_index == UINT32_MAX);

    m_acquired_swapchain_image_index = in_index;
}

void OpenGL::VKFrameGraph::set_swapchain_image_acquired_sem(Anvil::Semaphore* in_sem_ptr)
{
    vkgl_assert(in_sem_ptr                  != nullptr);
    vkgl_assert(m_swapchain_acquire_sem_ptr == nullptr);

    m_swapchain_acquire_sem_ptr = in_sem_ptr;
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/fence_create_info.h"
#include "Anvil/include/misc/semaphore_create_info.h"
#include "Anvil/include/wrappers/command_buffer.h"
#include "Anvil/include/wrappers/command_pool.h"
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/fence.h"
#include "Anvil/include/wrappers/queue.h"
#include "Anvil/include/wrappers/semaphore.h"
#include "Anvil/include/wrappers/swapchain.h"
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
                /* Last graph node accessing the image has the ultimate take on swapchain image properties that subsequent group node should use.l */
                current_group_node_io_ptr->swapchain_image_props = in_io.swapchain_image_props;

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

            current_group_node_ptr.reset(new GroupNode(Anvil::QueueFamilyType::UNDEFINED) );
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
        const Anvil::QueueFamilyType required_queue_family_type = (current_node_supports_dma_queues)       ? Anvil::QueueFamilyType::TRANSFER
                                                                : (current_node_supports_compute_queues)   ? Anvil::QueueFamilyType::COMPUTE
                                                                : (current_node_supports_universal_queues) ? Anvil::QueueFamilyType::UNIVERSAL
                                                                                                           : Anvil::QueueFamilyType::UNDEFINED;

        vkgl_assert(( current_node_requires_gpu_side_execution && required_queue_family_type != Anvil::QueueFamilyType::UNDEFINED) ||
                    (!current_node_requires_gpu_side_execution && required_queue_family_type == Anvil::QueueFamilyType::UNDEFINED) );

        if (current_group_node_ptr->queue_family == Anvil::QueueFamilyType::UNDEFINED)
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

        for (uint32_t n_current_group_node = 0;
                      n_current_group_node < static_cast<uint32_t>(out_group_nodes_ptr->size() );
                    ++n_current_group_node)
        {
            auto& current_group_node_ptr = out_group_nodes_ptr->at(n_current_group_node);

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
                                auto new_connection_ptr    = GroupNodeConnectionInfoUniquePtr(nullptr,
                                                                                              std::default_delete<GroupNodeConnectionInfo>() );

                                {
                                    auto new_connection_ptr    = GroupNodeConnectionInfoUniquePtr(nullptr,
                                                                                              std::default_delete<GroupNodeConnectionInfo>() );
                                    auto src_group_node_io_ptr = object_ptr_map_iterator->second.group_node_output_ptr;

                                    new_connection_ptr.reset(
                                        new GroupNodeConnectionInfo(src_group_node_ptr,
                                                                    src_group_node_io_ptr,
                                                                    n_current_group_node,
                                                                    n_dst_group_node_input)
                                    );

                                    dst_group_node_ptr->incoming_connections_ptr.push_back(std::move(new_connection_ptr) );
                                }

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

                                {
                                    auto dst_group_node_io_ptr = dst_group_node_ptr->input_ptrs.at(n_dst_group_node_input).get();
                                    auto new_connection_ptr    = GroupNodeConnectionInfoUniquePtr(nullptr,
                                                                                                  std::default_delete<GroupNodeConnectionInfo>() );
                                    auto src_group_node_io_ptr = last_swapchain_output_data.group_node_output_ptr;

                                    new_connection_ptr.reset(
                                        new GroupNodeConnectionInfo(src_group_node_ptr,
                                                                    src_group_node_io_ptr,
                                                                    n_current_group_node,
                                                                    n_dst_group_node_input)
                                    );

                                    dst_group_node_ptr->incoming_connections_ptr.push_back(std::move(new_connection_ptr) );
                                }

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
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

bool OpenGL::VKFrameGraph::do_group_nodes_encapsulate_swapchain_acquire_present_command_stream(const std::vector<GroupNodeUniquePtr>& in_group_nodes_ptr) const
{
    bool     is_acquire_node_first = false;
    bool     is_present_node_last  = false;
    uint32_t n_acquire_nodes       = 0;
    uint32_t n_present_nodes       = 0;

    for (const auto& current_group_node_ptr : in_group_nodes_ptr)
    {
        for (const auto& current_graph_node_ptr : current_group_node_ptr->graph_node_ptrs)
        {
            switch (current_graph_node_ptr->get_type() )
            {
                case OpenGL::FrameGraphNodeType::Acquire_Swapchain_Image:
                {
                    if (n_acquire_nodes == 0)
                    {
                        is_acquire_node_first = (n_present_nodes == 0);
                    }

                    ++n_acquire_nodes;
                    is_present_node_last = false;

                    break;
                }

                case OpenGL::FrameGraphNodeType::Present_Swapchain_Image:
                {
                    is_present_node_last  = true;
                    ++n_present_nodes;

                    break;
                }

                default:
                {
                    /* Don't care */
                }
            }
        }
    }

    return (is_acquire_node_first                &&
            is_present_node_last                 &&
            (n_acquire_nodes == n_present_nodes) );
}

void OpenGL::VKFrameGraph::execute(const bool& in_block_until_finished)
{
    /* NOTE: This function must NEVER be called from app's rendering thread. */
    std::lock_guard<std::mutex> execute_lock(m_execute_mutex);

    std::vector<CommandBufferSubmissionUniquePtr>                        command_buffer_submissions;
    auto                                                                 device_ptr                 = m_backend_ptr->get_device_ptr();
    std::unordered_map<const GroupNode*, std::vector<const GroupNode*> > group_node_connections;
    std::vector<GroupNodeUniquePtr>                                      group_node_ptrs;
    decltype(m_node_ptrs)                                                node_ptrs;
    Anvil::FenceUniquePtr                                                wait_fence_ptr;

    /* Cache node data, so that apps can continue rendering subsequent frames while we do the GL->VK conversion */
    {
        std::lock_guard<std::mutex> node_lock(m_general_mutex);

        if (m_node_ptrs.size() == 0)
        {
            goto end;
        }

        node_ptrs = std::move(m_node_ptrs);
    }

    /* NOTE: This is an extremely simplified PoC implementation. Once more complex examples are proven to work
     *       and a better understanding of actual architectural requirements is made, this code is expected
     *       to be rewritten (possibly many times).
     *
     *       Things which are already planned to be taken into account:
     *
     *       - Command buffer reuse.
     *       - Multi-threading                              (CPU prepasses should be executed as thread pool jobs, layout/pipeline objects
     *                                                       should be created using multiple threads, etc.)
     *       - Node reshuffling+clustering                  (as an example, transfer operations touching the same image should be clustered
     *                                                       and submitted to a sDMA queue if only feasible).
     *       - Switch from STL to something more performant
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

    /* 0. If NO swapchain is acquired at any point in the graph and any of the scheduled nodes claims it needs one, prepend
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
    if (!record_command_buffers(group_node_ptrs,
                                group_node_connections,
                               &command_buffer_submissions) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* 4. Schedule command buffer submissions. */
    if (in_block_until_finished)
    {
        auto fence_create_info_ptr = Anvil::FenceCreateInfo::create(device_ptr,
                                                                    false); /* in_create_signalled */

        wait_fence_ptr = Anvil::Fence::create(std::move(fence_create_info_ptr) );
        vkgl_assert(wait_fence_ptr != nullptr);
    }

    if (!submit_command_buffers(command_buffer_submissions,
                                wait_fence_ptr.get() ) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* 5. Update layout, ownership, etc. information for buffer ranges and image subresources touched by the submissions. */
    vkgl_not_implemented();

    /* 6. If this was requested, wait for the GPU-side operations to finish before leaving. */
    if (wait_fence_ptr != nullptr)
    {
        VkResult result_vk = Anvil::Vulkan::vkWaitForFences(device_ptr->get_device_vk(),
                                                            1, /* fenceCount */
                                                            wait_fence_ptr->get_fence_ptr(),
                                                            VK_TRUE,
                                                            UINT64_MAX);

        vkgl_assert(result_vk == VK_SUCCESS);
    }

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

bool OpenGL::VKFrameGraph::init()
{
    bool result = false;

    if (!init_per_object_data() )
    {
        vkgl_assert_fail();

        goto end;
    }

    if (!init_queue_rings() )
    {
        vkgl_assert_fail();

        goto end;
    }

    result = true;
end:
    return result;
}

bool OpenGL::VKFrameGraph::init_per_object_data()
{
    bool result                = false;
    auto swapchain_manager_ptr = m_backend_ptr->get_swapchain_manager_ptr();

    vkgl_assert(swapchain_manager_ptr != nullptr);

    /* Initialize per-aspect data for swapchain images */
    m_swapchain_image_data.resize(swapchain_manager_ptr->get_n_swapchain_images() );

    /* All done */
    result = true;
end:
    return result;
}

bool OpenGL::VKFrameGraph::init_queue_rings()
{
    auto device_ptr = m_backend_ptr->get_device_ptr();
    bool result     = false;

    for (auto current_queue_family_type = Anvil::QueueFamilyType::FIRST;
              current_queue_family_type < Anvil::QueueFamilyType::COUNT;
              current_queue_family_type = static_cast<Anvil::QueueFamilyType>(static_cast<uint32_t>(current_queue_family_type) + 1))
    {
        const auto         n_current_queue_fam_queues = device_ptr->get_n_queues(current_queue_family_type);
        QueueRingUniquePtr queue_ring_ptr;
        auto               queue_vec                  = std::vector<Anvil::Queue*>(n_current_queue_fam_queues);

        if (n_current_queue_fam_queues == 0)
        {
            continue;
        }

        for (uint32_t n_current_queue_fam_queue = 0;
                      n_current_queue_fam_queue < n_current_queue_fam_queues;
                    ++n_current_queue_fam_queue)
        {
            auto queue_raw_ptr = device_ptr->get_queue(current_queue_family_type,
                                                       n_current_queue_fam_queue);

            vkgl_assert(queue_raw_ptr != nullptr);

            queue_vec.at(n_current_queue_fam_queue) = queue_raw_ptr;
        }

        queue_ring_ptr.reset(new QueueRing(n_current_queue_fam_queues,
                                           queue_vec.data() ) );

        if (queue_ring_ptr == nullptr)
        {
            vkgl_assert(queue_ring_ptr != nullptr);

            goto end;
        }

        m_queue_ring_ptr_per_queue_fam[current_queue_family_type] = std::move(queue_ring_ptr);
    }

    result = true;
end:
    return result;
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

void OpenGL::VKFrameGraph::process_swapchain_image_node_input(std::vector<Anvil::ImageBarrier>& inout_image_barriers,
                                                              const NodeIO*                     in_input_ptr,
                                                              const Anvil::Queue*               in_opt_queue_ptr,
                                                              const Anvil::AccessFlags&         in_access_mask_for_color_aspect,
                                                              const Anvil::AccessFlags&         in_access_mask_for_ds_aspects)
{
    auto swapchain_manager_ptr = m_backend_ptr->get_swapchain_manager_ptr();

    vkgl_assert(m_acquired_swapchain_image_index != UINT32_MAX);

    auto&      current_swapchain_image_props = m_swapchain_image_data.at(m_acquired_swapchain_image_index);
    const bool color_image_layouts_match     = in_input_ptr->swapchain_image_props.color_image_layout == current_swapchain_image_props.color_aspect_layout;
    const bool ds_image_layouts_match        = in_input_ptr->swapchain_image_props.ds_image_layout    == current_swapchain_image_props.ds_aspect_layout;
    const bool queue_fams_match              = (in_opt_queue_ptr != nullptr) ? (in_opt_queue_ptr->get_queue_family_index() == current_swapchain_image_props.owning_queue_family_index)
                                                                             : true; //< presentation engine does not require ownership transfer prior to presenting.

    if (!color_image_layouts_match ||
        !ds_image_layouts_match    ||
        !queue_fams_match)
    {
        const auto dst_queue_family_index = (queue_fams_match) ? VK_QUEUE_FAMILY_IGNORED
                                                               : in_opt_queue_ptr->get_queue_family_index();
        const auto src_queue_family_index = (queue_fams_match) ? VK_QUEUE_FAMILY_IGNORED
                                                               : current_swapchain_image_props.owning_queue_family_index;

        for (uint32_t n_iteration = 0;
                      n_iteration < 2; /* color, ds */
                    ++n_iteration)
        {
            const bool is_color_iteration = (n_iteration == 0);
            auto       image_ptr          = (is_color_iteration) ? in_input_ptr->swapchain_reference_ptr->get_payload().swapchain_ptr->get_image(m_acquired_swapchain_image_index)
                                                                 : swapchain_manager_ptr->get_ds_image                                          (in_input_ptr->swapchain_reference_ptr->get_payload().time_marker,
                                                                                                                                                 m_acquired_swapchain_image_index);
            const bool layouts_match      = (is_color_iteration) ? color_image_layouts_match
                                                                 : ds_image_layouts_match;

            if (is_color_iteration && ((in_input_ptr->swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::COLOR_BIT) == 0))
            {
                continue;
            }

            if ( (!is_color_iteration)                                                                                   &&
                (((in_input_ptr->swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::DEPTH_BIT)   == 0)  &&
                 ((in_input_ptr->swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::STENCIL_BIT) == 0)) )
            {
                continue;
            }

            if ((image_ptr != nullptr) &&
                (!layouts_match        ||
                 !queue_fams_match) )
            {
                const auto         old_layout          = (is_color_iteration) ? current_swapchain_image_props.color_aspect_layout
                                                                              : current_swapchain_image_props.ds_aspect_layout;
                const auto         new_layout          = (is_color_iteration) ? in_input_ptr->swapchain_image_props.color_image_layout
                                                                              : in_input_ptr->swapchain_image_props.ds_image_layout;
                const auto         src_access_mask     = (is_color_iteration) ? in_access_mask_for_color_aspect
                                                                              : in_access_mask_for_ds_aspects;
                auto               subresource_range   = image_ptr->get_subresource_range();

                /* Cache the image memory barrier */
                {
                    auto image_barrier = Anvil::ImageBarrier(src_access_mask,
                                                             in_input_ptr->swapchain_image_props.access, /* in_destination_access_mask */
                                                             old_layout,
                                                             new_layout,
                                                             src_queue_family_index,
                                                             dst_queue_family_index,
                                                             image_ptr,
                                                             subresource_range);

                    inout_image_barriers.push_back(std::move(image_barrier) );
                }

                /* Update local swapchain image state */
                if (in_opt_queue_ptr != nullptr)
                {
                    current_swapchain_image_props.owning_queue_family_index = in_opt_queue_ptr->get_queue_family_index();
                }

                if (is_color_iteration)
                {
                    current_swapchain_image_props.color_aspect_layout = new_layout;
                }
                else
                {
                    current_swapchain_image_props.ds_aspect_layout = new_layout;
                }
            }
        }
    }
}

bool OpenGL::VKFrameGraph::record_command_buffers(const std::vector<GroupNodeUniquePtr>&                                       in_group_nodes_ptr,
                                                  const std::unordered_map<const GroupNode*, std::vector<const GroupNode* > >& in_src_dst_group_node_connections_ptr,
                                                  std::vector<CommandBufferSubmissionUniquePtr>*                               out_cmd_buffer_submissions_ptr)
{
    typedef struct BarrierData
    {
        Anvil::PipelineStageFlags dst_pipeline_stages;
        Anvil::PipelineStageFlags src_pipeline_stages;

        std::vector<Anvil::ImageBarrier> image_barriers;

        BarrierData()
            :dst_pipeline_stages(Anvil::PipelineStageFlagBits::NONE),
             src_pipeline_stages(Anvil::PipelineStageFlagBits::NONE)
        {
            /* Stub */
        }
    } BarrierData;

    auto const device_ptr                             = m_backend_ptr->get_device_ptr();
    auto       graph_node_pre_barriers_per_group_node = std::vector<BarrierData>(in_group_nodes_ptr.size() );
    bool       result                                 = false;
    auto const swapchain_manager_ptr                  = m_backend_ptr->get_swapchain_manager_ptr();

    vkgl_assert(out_cmd_buffer_submissions_ptr         != nullptr);
    vkgl_assert(out_cmd_buffer_submissions_ptr->size() == 0);

    for (uint32_t n_current_group_node = 0;
                  n_current_group_node < in_group_nodes_ptr.size();
                ++n_current_group_node)
    {
        /* Each group node is built of multiple "regular" nodes. Command stream generated by executing these nodes in order
         * defines what group node's command buffer does.
         *
         * Sounds simple?
         *
         * Regular nodes may use objects for various purposes, which implies we need to take care of layout transitions and
         * memory barriers in here. Group nodes may use different queue families, meaning we also need to handle ownership transfers,
         * every time a resource being accessed by the node was used on a different queue family by the preceding node.
         */

        /* TODO: Command buffer reuse. This means both caching cmd buffers in VKGL-level cmd buffer pool, as well as attempting to record
         *       command buffers in a way which would allow for their reuse across frames.
         **/

        /* TODO: Leverage secondary command buffer wherever feasible (ie. where chances of cross-frame reuse are substantial). */
        Anvil::PrimaryCommandBufferUniquePtr cmd_buffer_ptr;
        const auto&                          current_group_node_ptr          = in_group_nodes_ptr.at(n_current_group_node);
        auto                                 current_group_node_queue_family = current_group_node_ptr->queue_family;
        CommandBufferSubmissionUniquePtr     current_submission_ptr          = CommandBufferSubmissionUniquePtr(nullptr,
                                                                                                                std::default_delete<CommandBufferSubmission>() );
        BarrierData                          group_node_pre_barriers;

        /* 0. Determine which queue family this cmd buffer submission is being created for:
         *
         * a) Queue family is defined as anything != UNDEFINED under group_node::queue_family - straightforward.
         * b) Queue family is defined as UNDEFINED             under group_node::queue_family - two subcases:

         * b.1) Group node has no inputs and outputs          - no need for a queue
         * b.2) Group node has at least 1 input and/or output - need to use a queue coming from previous node's queue family (repeat the algo from the start using the new start queue fam value);
          *                                                     If unavailable, use universal queue fam.
         */
        {
            uint32_t temp_group_node_index = n_current_group_node;
            auto     temp_group_node_ptr   = in_group_nodes_ptr.at(temp_group_node_index).get();

            while (current_group_node_queue_family == Anvil::QueueFamilyType::UNDEFINED) /* a) */
            {
                if (temp_group_node_ptr->input_ptrs.size () == 0 &&
                    temp_group_node_ptr->output_ptrs.size() == 0)
                {
                    /* b.1) */
                    break;
                }

                if (temp_group_node_index == 0)
                {
                    current_group_node_queue_family = Anvil::QueueFamilyType::UNIVERSAL;

                    break;
                }

                temp_group_node_index           --;
                temp_group_node_ptr   = in_group_nodes_ptr.at(temp_group_node_index).get();

                current_group_node_queue_family = temp_group_node_ptr->queue_family;
            }
        }

        /* 1. Create a new cmd buffer submission */
        {
            Anvil::Queue* queue_ptr = nullptr;

            if (current_group_node_queue_family != Anvil::QueueFamilyType::UNDEFINED)
            {
                queue_ptr = m_queue_ring_ptr_per_queue_fam.at(current_group_node_queue_family)->get_queue_ptr();
                vkgl_assert(queue_ptr != nullptr);
            }

            current_submission_ptr.reset(new CommandBufferSubmission(queue_ptr) );
            vkgl_assert(current_submission_ptr != nullptr);

            current_group_node_ptr->parent_submission_ptr = current_submission_ptr.get();
        }

        /* 2. Create a cmd buffer we're going to record commands to for this group node.
         *
         * NOTE/TODO: This assumes we're NOT going to record 2nd-level cmd buffers. That's true FOR NOW, and will change in the future.
         */
        if (current_group_node_queue_family != Anvil::QueueFamilyType::UNDEFINED)
        {
            auto cmd_pool_ptr = device_ptr->get_command_pool_for_queue_family_index(current_submission_ptr->queue_ptr->get_queue_family_index() );

            cmd_buffer_ptr = cmd_pool_ptr->alloc_primary_level_command_buffer();
            vkgl_assert(cmd_buffer_ptr != nullptr);

            if (!cmd_buffer_ptr->start_recording(true,    /* in_one_time_submit          */
                                                 false) ) /* in_simultaneous_use_allowed */
            {
                vkgl_assert_fail();

                goto end;
            }
        }

        /* 3. Determine what barriers need to injected at the beginning of group node's command buffer.
         *
         *    While we iterate over group node-level inputs and outputs, also fill out dst & src pipeline stage masks.
         */
        for (uint32_t n_current_input = 0;
                      n_current_input < static_cast<uint32_t>(current_group_node_ptr->input_ptrs.size() );
                    ++n_current_input)
        {
            const auto&                  current_input_ptr = current_group_node_ptr->input_ptrs.at(n_current_input);
            Anvil::PipelineStageFlagBits wait_dst_stages   = Anvil::PipelineStageFlagBits::NONE;

            switch (current_input_ptr->type)
            {
                case OpenGL::NodeIOType::Buffer:
                {
                    vkgl_not_implemented();

                    break;
                }

                case OpenGL::NodeIOType::Image:
                {
                    vkgl_not_implemented();

                    break;
                }

                case OpenGL::NodeIOType::Swapchain_Image:
                {
                    /* Source access mask is determined by:
                     *
                     * 1) If there are incoming connections: ORing all access flags defined for connections where outputs of group nodes touching the swapcain image
                     *    are connected to the processed input.
                     * 2) If no incoming connections are defined: Assuming no access flags are required (ie. acquisition happened)
                     *
                     * TODO: 2) breaks if frame graph does not encapsulate both acquire and present nodes for the same swapchain image !!
                     *         (ie. acquire, draw draw draw, flush, draw draw draw, present). NEEDS MORE THOUGHT.
                     */
                    Anvil::AccessFlags color_src_access_mask = Anvil::AccessFlagBits::NONE;
                    Anvil::AccessFlags ds_src_access_mask    = Anvil::AccessFlagBits::NONE;

                    {
                        auto               color_image_ptr               = current_input_ptr->swapchain_reference_ptr->get_payload().swapchain_ptr->get_image(m_acquired_swapchain_image_index);
                        auto               color_image_subresource_range = color_image_ptr->get_subresource_range                                            ();
                        auto               ds_image_ptr                  = swapchain_manager_ptr->get_ds_image(current_input_ptr->swapchain_reference_ptr->get_payload().time_marker,
                                                                                                               m_acquired_swapchain_image_index);
                        auto               ds_image_subresource_range    = ds_image_ptr->get_subresource_range();
                        Anvil::AccessFlags src_access_mask               = Anvil::AccessFlagBits::NONE;

                        vkgl_assert(do_group_nodes_encapsulate_swapchain_acquire_present_command_stream(in_group_nodes_ptr) ); //< TODO: Protect against problem described for 2)

                        for (const auto& current_incoming_connection_ptr : current_group_node_ptr->incoming_connections_ptr)
                        {
                            if (current_incoming_connection_ptr->n_dst_group_node_input == n_current_input)
                            {
                                const auto src_access = current_incoming_connection_ptr->src_group_node_io_ptr->swapchain_image_props.access;

                                vkgl_assert(current_incoming_connection_ptr->src_group_node_io_ptr->type == OpenGL::NodeIOType::Swapchain_Image);

                                src_access_mask                             |= current_incoming_connection_ptr->src_group_node_io_ptr->swapchain_image_props.access;
                                group_node_pre_barriers.src_pipeline_stages |= current_incoming_connection_ptr->src_group_node_io_ptr->swapchain_image_props.pipeline_stages;
                            }
                        }

                        /* NOTE: Access mask needs to be split correctly between color & DS images the default FB is built of. */
                        split_access_mask_to_color_and_ds_access_masks(src_access_mask,
                                                                      &color_src_access_mask,
                                                                      &ds_src_access_mask);
                    }

                    /* Create & append the image memory barriers.. */
                    process_swapchain_image_node_input(group_node_pre_barriers.image_barriers,
                                                       current_input_ptr.get(),
                                                       current_submission_ptr->queue_ptr,
                                                       color_src_access_mask,
                                                       ds_src_access_mask);

                    group_node_pre_barriers.dst_pipeline_stages |= current_input_ptr->swapchain_image_props.pipeline_stages;

                    if (current_input_ptr->opt_post_sync_semaphore_ptr != nullptr)
                    {
                        /* NOTE: In all likelihood, we are processing the very first node which processes a swapchain image that has been acquired by source node. */

                        /* TODO: Not optimal. We should be able to use more optimal stage mask for cases where a corresponding present node is included in the set of group nodes we
                         *       have been asked to create command buffer submissions for.
                         */
                        wait_dst_stages = Anvil::PipelineStageFlagBits::ALL_COMMANDS_BIT;
                    }

                    break;
                }

                default:
                {
                    vkgl_assert_fail();
                }
            }

            vkgl_assert(current_input_ptr->opt_post_sync_event_ptr == nullptr); /* TODO */
            vkgl_assert(current_input_ptr->opt_post_sync_fence_ptr == nullptr); /* TODO */

            if (current_input_ptr->opt_post_sync_semaphore_ptr != nullptr)
            {
                vkgl_assert(wait_dst_stages != Anvil::PipelineStageFlagBits::NONE);

                current_submission_ptr->wait_dst_stage_masks.push_back(wait_dst_stages);
                current_submission_ptr->wait_semaphore_ptrs.push_back (current_input_ptr->opt_post_sync_semaphore_ptr);

            }
        }

        /* 4. Ditto for situations when we move from node (N-1) to (N), both located within the same group node. */
        {
            for (auto& current_connection_ptr : current_group_node_ptr->incoming_connections_ptr)
            {
                auto&       dst_graph_node_pre_barriers = graph_node_pre_barriers_per_group_node.at(n_current_group_node);
                const auto& dst_io_ptr                  = current_group_node_ptr->input_ptrs.at    (current_connection_ptr->n_dst_group_node_input).get();
                const auto& src_io_ptr                  = current_connection_ptr->src_group_node_io_ptr;

                /* NOTE: Ignore events/fences/sems requested for node IOs. These should've been handled in previous step. */
                vkgl_assert(src_io_ptr       != dst_io_ptr);
                vkgl_assert(src_io_ptr->type == dst_io_ptr->type);

                switch (dst_io_ptr->type)
                {
                    case OpenGL::NodeIOType::Buffer:
                    {
                        vkgl_not_implemented();

                        continue;
                    }

                    case OpenGL::NodeIOType::Image:
                    {
                        vkgl_not_implemented();

                        continue;
                    }

                    case OpenGL::NodeIOType::Swapchain_Image:
                    {
                        const auto         dst_access_mask       = src_io_ptr->swapchain_image_props.access;
                        Anvil::AccessFlags dst_access_mask_color = Anvil::AccessFlagBits::NONE;
                        Anvil::AccessFlags dst_access_mask_ds    = Anvil::AccessFlagBits::NONE;

                        split_access_mask_to_color_and_ds_access_masks(dst_access_mask,
                                                                      &dst_access_mask_color,
                                                                      &dst_access_mask_ds);

                        /* Create & append the image memory barriers.. */
                        process_swapchain_image_node_input(dst_graph_node_pre_barriers.image_barriers,
                                                           dst_io_ptr,
                                                           current_submission_ptr->queue_ptr,
                                                           dst_access_mask_color,
                                                           dst_access_mask_ds);

                        dst_graph_node_pre_barriers.dst_pipeline_stages |= dst_io_ptr->swapchain_image_props.pipeline_stages;
                        dst_graph_node_pre_barriers.src_pipeline_stages |= src_io_ptr->swapchain_image_props.pipeline_stages;

                        break;
                    }

                    default:
                    {
                        vkgl_assert_fail();

                        goto end;
                    }
                }
            }
        }

        /* 4. Fill out group node-level command buffer by executing GPU-side node commands.
         *
         *    NOTE: Regular nodes may use the same resources. Make sure to inject memory barriers in-between the nodes wherever appropriate.
         *          Image memory barriers may be necessary if nodes require non-matching layouts for overlapping subresource ranges
         */
        vkgl_assert(current_group_node_ptr->graph_node_ptrs.size() > 0);

        /* 4a. Inject pre-barriers (acquire barriers, image layout transitions) as necessary */
        {
            cmd_buffer_ptr->record_pipeline_barrier(group_node_pre_barriers.src_pipeline_stages,
                                                    group_node_pre_barriers.dst_pipeline_stages,
                                                    Anvil::DependencyFlagBits::NONE,
                                                    0,       /* in_memory_barrier_count        - TODO */
                                                    nullptr, /* in_memory_barriers_ptr         - TODO */
                                                    0,       /* in_buffer_memory_barrier_count - TODO */
                                                    nullptr, /* in_buffer_memory_barriers_ptr  - TODO */
                                                    static_cast<uint32_t>(group_node_pre_barriers.image_barriers.size() ),
                                                    (group_node_pre_barriers.image_barriers.size() > 0) ? &group_node_pre_barriers.image_barriers.at(0) : nullptr);
        }

        /* 4b. Record node-specific commands */
        {
            const auto& current_node_pre_barriers = graph_node_pre_barriers_per_group_node.at (n_current_group_node);

            for (uint32_t n_current_node = 0;
                          n_current_node < static_cast<uint32_t>(current_group_node_ptr->graph_node_ptrs.size() );
                        ++n_current_node)
            {
                const auto& current_node_ptr = current_group_node_ptr->graph_node_ptrs.at(n_current_node);

                if (current_node_pre_barriers.image_barriers.size() > 0)
                {
                    cmd_buffer_ptr->record_pipeline_barrier(current_node_pre_barriers.src_pipeline_stages,
                                                            current_node_pre_barriers.dst_pipeline_stages,
                                                            Anvil::DependencyFlagBits::NONE,
                                                            0,       /* in_memory_barrier_count        - TODO */
                                                            nullptr, /* in_memory_barriers_ptr         - TODO */
                                                            0,       /* in_buffer_memory_barrier_count - TODO */
                                                            nullptr, /* in_buffer_memory_barriers_ptr  - TODO */
                                                            static_cast<uint32_t>(current_node_pre_barriers.image_barriers.size() ),
                                                            (current_node_pre_barriers.image_barriers.size() > 0) ? &current_node_pre_barriers.image_barriers.at(0) : nullptr);
                }

                if (current_node_ptr->requires_gpu_side_execution() )
                {
                    current_node_ptr->record_commands(cmd_buffer_ptr.get(),
                                                      false, /* in_inside_renderpass - TODO */
                                                      this   /* in_graph_callback_ptr       */);
                }
                else
                if (current_node_ptr->requires_cpu_side_execution() )
                {
                    /* TODO: Fence-based CPU/GPU synchro */
                    vkgl_assert(current_node_ptr->requires_manual_wait_sem_sync() );

                    /* NOTE: Actual execution is done at submission time */
                }
            }
        }

        /* 5. Stash the submission and move on. */
        if (current_group_node_queue_family != Anvil::QueueFamilyType::UNDEFINED)
        {
            if (!cmd_buffer_ptr->stop_recording() )
            {
                vkgl_assert_fail();

                goto end;
            }
        }

        out_cmd_buffer_submissions_ptr->push_back(
            std::move(current_submission_ptr)
        );
    }

    /* 6. Determine wait and signal semaphores that need to be used for the submission */
    {
        /* NOTE: Each command buffer submission owns exactly one group node. */
        for (auto& current_connection_ptr : in_src_dst_group_node_connections_ptr)
        {
            auto  src_group_node_ptr  = current_connection_ptr.first;
            auto& dst_group_node_ptrs = current_connection_ptr.second;

            for (auto& current_dst_group_node_ptr : dst_group_node_ptrs)
            {
                auto                      sem_create_info_ptr = Anvil::SemaphoreCreateInfo::create(device_ptr);
                Anvil::SemaphoreUniquePtr sem_ptr             = Anvil::Semaphore::create          (std::move(sem_create_info_ptr) );

                current_dst_group_node_ptr->parent_submission_ptr->wait_semaphore_ptrs.push_back(sem_ptr.get() );
                src_group_node_ptr->parent_submission_ptr->signal_semaphore_ptrs.push_back      (sem_ptr.get() );
                src_group_node_ptr->parent_submission_ptr->owned_semaphore_ptrs.push_back       (std::move  (sem_ptr) );
            }
        }
    }

    result = true;
end:
    return result;
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

void OpenGL::VKFrameGraph::split_access_mask_to_color_and_ds_access_masks(const Anvil::AccessFlags& in_access_mask,
                                                                          Anvil::AccessFlags*       out_color_aspect_access_mask_ptr,
                                                                          Anvil::AccessFlags*       out_ds_aspects_access_mask_ptr) const
{
    Anvil::AccessFlags color_src_access_mask = in_access_mask & ~(Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_READ_BIT | Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_WRITE_BIT);
    Anvil::AccessFlags ds_src_access_mask    = in_access_mask & ~(Anvil::AccessFlagBits::COLOR_ATTACHMENT_READ_BIT         | Anvil::AccessFlagBits::COLOR_ATTACHMENT_WRITE_BIT);

    if ((in_access_mask & Anvil::AccessFlagBits::COLOR_ATTACHMENT_READ_BIT) != 0)
    {
        ds_src_access_mask |= Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_READ_BIT;
    }
    if ((in_access_mask & Anvil::AccessFlagBits::COLOR_ATTACHMENT_WRITE_BIT) != 0)
    {
        ds_src_access_mask |= Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
    }

    if ((in_access_mask & Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_READ_BIT) != 0)
    {
        color_src_access_mask |= Anvil::AccessFlagBits::COLOR_ATTACHMENT_READ_BIT;
    }
    if ((in_access_mask & Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_WRITE_BIT) != 0)
    {
        color_src_access_mask |= Anvil::AccessFlagBits::COLOR_ATTACHMENT_WRITE_BIT;
    }

    *out_color_aspect_access_mask_ptr = color_src_access_mask;
    *out_ds_aspects_access_mask_ptr   = ds_src_access_mask;
}

bool OpenGL::VKFrameGraph::submit_command_buffers(const std::vector<CommandBufferSubmissionUniquePtr>& in_cmd_buffer_submissions_ptr,
                                                  Anvil::Fence*                                        in_opt_wait_fence_ptr)
{
    bool result = false;

    for (const auto& current_submission_ptr : in_cmd_buffer_submissions_ptr)
    {
        vkgl_not_implemented();
    }

end:
    return result;
}

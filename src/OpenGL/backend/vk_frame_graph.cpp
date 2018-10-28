/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/nodes/vk_acquire_swapchain_image_node.h"
#include "OpenGL/backend/vk_swapchain_manager.h"

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
    std::lock_guard<std::mutex> execute_lock(m_execute_mutex);
    decltype(m_node_ptrs)       node_ptrs;

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
     *    Take cached layout, ownership, etc. information from previous runs into account here, too.
     */

    /* 3. Convert the "sequential" input call representation into a DAG where each node is a group node obtained in step 2.
     *
     *    Connections should be made on a per-subresource basis. This is needed for correct barrier sync performed
     *    at next step.
     **/

    /* 4. Record command buffers for group nodes. Make sure to inject the required barriers accordingly using DAG info
     *    prepared in previous step.
     */

    /* 5. Schedule command buffer submissions. */

    /* 6. Update layout, ownership, etc. information for buffer ranges and image subresources touched by the submissions. */

    /* 7. If this was requested, wait for the GPU-side operations to finish before leaving. */

    vkgl_not_implemented();

end:
    node_ptrs.clear();
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

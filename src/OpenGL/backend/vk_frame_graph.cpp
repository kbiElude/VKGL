/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_frame_graph.h"
#include "OpenGL/backend/vk_swapchain_manager.h"

OpenGL::VKFrameGraph::VKFrameGraph(const OpenGL::IBackend* in_backend_ptr)
    :m_acquired_swapchain_image_index(UINT32_MAX),
     m_backend_ptr                   (in_backend_ptr),
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
    /* todo */

    m_node_ptrs.push_back(
        std::move(in_node_ptr)
    );
}

void OpenGL::VKFrameGraph::clear()
{
    /* todo */

    m_node_ptrs.clear();
}

OpenGL::VKFrameGraphUniquePtr OpenGL::VKFrameGraph::create(const OpenGL::IBackend* in_backend_ptr)
{
    OpenGL::VKFrameGraphUniquePtr result_ptr(nullptr,
                                             [](OpenGL::VKFrameGraph* in_ptr){ delete in_ptr; });

    result_ptr.reset(
        new OpenGL::VKFrameGraph(in_backend_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    if (result_ptr != nullptr)
    {
        /* Nothing to do for now. */
    }

    return result_ptr;
}

void OpenGL::VKFrameGraph::execute()
{
    vkgl_not_implemented();
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

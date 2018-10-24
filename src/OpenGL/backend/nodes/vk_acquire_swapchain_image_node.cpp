/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/semaphore.h"
#include "Anvil/include/wrappers/swapchain.h"
#include "Common/macros.h"
#include "OpenGL/backend/vk_utils.h"
#include "OpenGL/backend/nodes/vk_acquire_swapchain_image_node.h"


OpenGL::VKNodes::AcquireSwapchainImage::AcquireSwapchainImage(const IContextObjectManagers*         in_frontend_ptr,
                                                              IBackend*                             in_backend_ptr,
                                                              OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr)
    :m_backend_ptr            (in_backend_ptr),
     m_frontend_ptr           (in_frontend_ptr),
     m_swapchain_reference_ptr(std::move(in_swapchain_reference_ptr) )
{
    vkgl_assert(m_backend_ptr             != nullptr);
    vkgl_assert(m_frontend_ptr            != nullptr);
    vkgl_assert(m_swapchain_reference_ptr != nullptr);

    m_info_ptr.reset(
        new OpenGL::VKFrameGraphNodeInfo()
    );
    vkgl_assert(m_info_ptr != nullptr);

    m_info_ptr->outputs.resize(1);
}

OpenGL::VKNodes::AcquireSwapchainImage::~AcquireSwapchainImage()
{
     /* Stub */
}

OpenGL::VKFrameGraphNodeUniquePtr OpenGL::VKNodes::AcquireSwapchainImage::create(const IContextObjectManagers*         in_frontend_ptr,
                                                                                 IBackend*                             in_backend_ptr,
                                                                                 OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr)
{
    OpenGL::VKFrameGraphNodeUniquePtr result_ptr(nullptr,
                                                 std::default_delete<OpenGL::IVKFrameGraphNode>() );

    result_ptr.reset(
        new OpenGL::VKNodes::AcquireSwapchainImage(in_frontend_ptr,
                                                   in_backend_ptr,
                                                   std::move(in_swapchain_reference_ptr) )
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::VKNodes::AcquireSwapchainImage::do_cpu_prepass(IVKFrameGraphNodeCallback* in_callback_ptr)
{
    Anvil::SemaphoreUniquePtr frame_acquire_sem_ptr;
    uint32_t                  swapchain_frame_index    = UINT32_MAX;
    Anvil::ImageView*         swapchain_image_view_ptr = nullptr;
    auto                      swapchain_manager_ptr    = m_backend_ptr->get_swapchain_manager_ptr();
    Anvil::Swapchain*         swapchain_ptr            = m_swapchain_reference_ptr->get_payload().swapchain_ptr;

    vkgl_assert(swapchain_ptr != nullptr);

    /* Perform the requested operation */
    frame_acquire_sem_ptr = swapchain_manager_ptr->pop_frame_acquisition_semaphore(m_swapchain_reference_ptr->get_payload().time_marker);
    vkgl_assert(frame_acquire_sem_ptr != nullptr);

    swapchain_frame_index = swapchain_ptr->acquire_image(frame_acquire_sem_ptr.get() );
    vkgl_assert(swapchain_frame_index != UINT32_MAX);

    swapchain_image_view_ptr = swapchain_ptr->get_image_view(swapchain_frame_index);
    vkgl_assert(swapchain_image_view_ptr != nullptr);

    /* Cache the allotted image view + acquire sem for later usage by subsequent nodes */
    {
        auto& swapchain_node_output = m_info_ptr->outputs.at(0);

        vkgl_assert(m_frame_acquire_sem_ptr == nullptr);
        m_frame_acquire_sem_ptr = std::move(frame_acquire_sem_ptr);

        m_info_ptr->outputs.at(0) = OpenGL::NodeIO(m_swapchain_reference_ptr.get(),
                                                   Anvil::ImageAspectFlagBits::COLOR_BIT | Anvil::ImageAspectFlagBits::DEPTH_BIT | Anvil::ImageAspectFlagBits::STENCIL_BIT,
                                                   Anvil::ImageLayout::UNDEFINED,
                                                   Anvil::PipelineStageFlagBits::ALL_COMMANDS_BIT,
                                                   Anvil::AccessFlagBits::NONE);

        m_info_ptr->opt_post_sync_semaphore_ptr = m_frame_acquire_sem_ptr.get();

        in_callback_ptr->set_acquired_swapchain_image_index(swapchain_frame_index);
        in_callback_ptr->set_swapchain_image_acquired_sem  (m_frame_acquire_sem_ptr.get() );
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/semaphore.h"
#include "Anvil/include/wrappers/swapchain.h"
#include "Common/macros.h"
#include "OpenGL/backend/vk_swapchain_manager.h"
#include "OpenGL/backend/vk_utils.h"
#include "OpenGL/backend/nodes/vk_present_swapchain_image_node.h"


OpenGL::VKNodes::PresentSwapchainImage::PresentSwapchainImage(const IContextObjectManagers*         in_frontend_ptr,
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

    m_info_ptr->inputs.resize(1);

    m_info_ptr->inputs.at(0) = OpenGL::NodeIO(m_swapchain_reference_ptr.get(),
                                              Anvil::ImageAspectFlagBits::COLOR_BIT,
                                              Anvil::ImageLayout::PRESENT_SRC_KHR,
                                              Anvil::ImageLayout::UNKNOWN,                      //< don't care
                                              Anvil::PipelineStageFlagBits::BOTTOM_OF_PIPE_BIT,
                                              Anvil::AccessFlagBits::NONE,
                                              UINT32_MAX);                                      //< in_fs_output_location - don't care
}

OpenGL::VKNodes::PresentSwapchainImage::~PresentSwapchainImage()
{
     m_swapchain_reference_ptr.reset();
}

OpenGL::VKFrameGraphNodeUniquePtr OpenGL::VKNodes::PresentSwapchainImage::create(const IContextObjectManagers*         in_frontend_ptr,
                                                                                 IBackend*                             in_backend_ptr,
                                                                                 OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr)
{
    OpenGL::VKFrameGraphNodeUniquePtr result_ptr(nullptr,
                                                 std::default_delete<OpenGL::IVKFrameGraphNode>() );

    result_ptr.reset(
        new OpenGL::VKNodes::PresentSwapchainImage(in_frontend_ptr,
                                                   in_backend_ptr,
                                                   std::move(in_swapchain_reference_ptr) )
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::VKNodes::PresentSwapchainImage::execute_cpu_side(IVKFrameGraphNodeCallback* in_callback_ptr)
{
    auto                               device_ptr               = m_backend_ptr->get_device_ptr();
    uint32_t                           n_wait_sems              = 0;
    Anvil::SwapchainOperationErrorCode present_result           = Anvil::SwapchainOperationErrorCode::DEVICE_LOST;
    auto                               swapchain_manager_ptr    = m_backend_ptr->get_swapchain_manager_ptr();
    auto                               swapchain_ptr            = m_swapchain_reference_ptr->get_payload().swapchain_ptr;
    auto                               queue_ptr                = swapchain_manager_ptr->get_presentable_queue(m_swapchain_reference_ptr->get_payload().time_marker);
    Anvil::Semaphore**                 wait_sem_ptr_ptr         = nullptr;
    const Anvil::PipelineStageFlags*   wait_sem_stage_masks_ptr = nullptr;

    vkgl_assert(queue_ptr != nullptr);

    /* Retrieve wait semaphores we need to wait upon prior to submitting a presentation request */
    if (!in_callback_ptr->get_wait_sems(&n_wait_sems,
                                        &wait_sem_ptr_ptr,
                                        &wait_sem_stage_masks_ptr) )
    {
        vkgl_assert_fail();
    }

    vkgl_assert(n_wait_sems > 0);

    if (!queue_ptr->present(swapchain_ptr,
                            in_callback_ptr->get_acquired_swapchain_image_index(),
                            n_wait_sems,
                            wait_sem_ptr_ptr,
                           &present_result) )
    {
        vkgl_assert(present_result != Anvil::SwapchainOperationErrorCode::SUCCESS)

        swapchain_manager_ptr->recreate_swapchain(true /* in_defer_till_acquisition */);
    }

    /* Mark the swapchain image as presented */
    in_callback_ptr->set_acquired_swapchain_image_index(UINT32_MAX);
    in_callback_ptr->set_swapchain_image_acquired_sem  (nullptr);
}

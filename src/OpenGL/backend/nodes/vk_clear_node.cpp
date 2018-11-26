/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/command_buffer.h"
#include "Anvil/include/wrappers/semaphore.h"
#include "Anvil/include/wrappers/swapchain.h"
#include "Common/macros.h"
#include "OpenGL/backend/vk_utils.h"
#include "OpenGL/backend/nodes/vk_clear_node.h"
#include "OpenGL/frontend/gl_framebuffer_manager.h"
#include "OpenGL/frontend/gl_state_manager.h"


OpenGL::VKNodes::Clear::Clear(const IContextObjectManagers*            in_frontend_ptr,
                              IBackend*                                in_backend_ptr,
                              OpenGL::GLContextStateReferenceUniquePtr in_context_state_ptr,
                              OpenGL::VKSwapchainReferenceUniquePtr    in_swapchain_reference_ptr,
                              const OpenGL::ClearBufferBits&           in_buffers_to_clear)
    :m_backend_ptr              (in_backend_ptr),
     m_buffers_to_clear         (in_buffers_to_clear),
     m_context_state_ptr        (std::move(in_context_state_ptr) ),
     m_frontend_ptr             (in_frontend_ptr),
     m_swapchain_reference_ptr  (std::move(in_swapchain_reference_ptr) )
{
    vkgl_assert(m_backend_ptr             != nullptr);
    vkgl_assert(m_context_state_ptr       != nullptr);
    vkgl_assert(m_frontend_ptr            != nullptr);
    vkgl_assert(m_swapchain_reference_ptr != nullptr);

    init_info();
}

OpenGL::VKNodes::Clear::~Clear()
{
    m_swapchain_reference_ptr.reset();
     /* Stub */
}

OpenGL::VKFrameGraphNodeUniquePtr OpenGL::VKNodes::Clear::create(const IContextObjectManagers*            in_frontend_ptr,
                                                                 IBackend*                                in_backend_ptr,
                                                                 OpenGL::GLContextStateReferenceUniquePtr in_context_state_ptr,
                                                                 OpenGL::VKSwapchainReferenceUniquePtr    in_swapchain_reference_ptr,
                                                                 const OpenGL::ClearBufferBits&           in_buffers_to_clear)
{
    OpenGL::VKFrameGraphNodeUniquePtr result_ptr(nullptr,
                                                 std::default_delete<OpenGL::IVKFrameGraphNode>() );

    result_ptr.reset(
        new OpenGL::VKNodes::Clear(in_frontend_ptr,
                                   in_backend_ptr,
                                   std::move(in_context_state_ptr),
                                   std::move(in_swapchain_reference_ptr),
                                   in_buffers_to_clear)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::VKNodes::Clear::init_info()
{
    /* NOTE: This function is called from app's rendering thread. */
    auto       fb_manager_ptr     = m_frontend_ptr->get_framebuffer_manager_ptr();
    auto       state_manager_ptr  = m_frontend_ptr->get_state_manager_ptr      ();

    const auto context_state_ptr  = state_manager_ptr->get_state         (m_context_state_ptr->get_payload().time_marker);
    const auto fb_state_ptr       = fb_manager_ptr->get_framebuffer_state(context_state_ptr->draw_framebuffer_reference_ptr->get_payload().id,
                                                                         &context_state_ptr->draw_framebuffer_reference_ptr->get_payload().time_marker);

    vkgl_assert(context_state_ptr != nullptr);
    vkgl_assert(fb_state_ptr      != nullptr);

    /* Set up the info struct */
    m_info_ptr.reset(
        new OpenGL::VKFrameGraphNodeInfo()
    );
    vkgl_assert(m_info_ptr != nullptr);

    /* NOTE: Enabled scissor test means the clear op needs to be:
     *
     * 1) Either handled via a clear load op with viewport set appropriately at RP level,
     * 2) or via a scaled blit.
     *
     * TODO: We don't support either at the moment.
     */
    if (context_state_ptr->is_scissor_test_enabled)
    {
        /* If this blows up, expect corruption */
        vkgl_not_implemented();
    }

    /* TODO: Color writemasks further limit which channels should be cleared. This would again require a RP. */
    for (uint32_t n_draw_buffer = 0;
                  n_draw_buffer < static_cast<uint32_t>(fb_state_ptr->draw_buffer_per_color_output.size() );
                ++n_draw_buffer)
    {
        const auto& current_draw_buffer = fb_state_ptr->draw_buffer_per_color_output.at(n_draw_buffer);

        if (current_draw_buffer >= OpenGL::DrawBuffer::Color_Attachment0 &&
            current_draw_buffer >= OpenGL::DrawBuffer::Color_Attachment7)
        {
            const uint32_t n_color_attachment = static_cast<uint32_t>(current_draw_buffer) - static_cast<uint32_t>(OpenGL::DrawBuffer::Color_Attachment0);

            /* If this blows up, expect corruption (checks if all components have been enabled for writing) for particular draw buffer. */
            vkgl_assert((context_state_ptr->color_writemask_for_draw_buffers >> (n_color_attachment * 4 /* bits */) & ((1 << 4) - 1)) == (1 << 4) - 1);
        }
        else
        {
            vkgl_assert(current_draw_buffer == OpenGL::DrawBuffer::None ||
                        current_draw_buffer == OpenGL::DrawBuffer::Back);
        }
    }

    if (m_buffers_to_clear & OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_COLOR)
    {
        for (uint32_t n_draw_buffer = 0;
                      n_draw_buffer < static_cast<uint32_t>(fb_state_ptr->draw_buffer_per_color_output.size() );
                    ++n_draw_buffer)
        {
            const auto& current_draw_buffer = fb_state_ptr->draw_buffer_per_color_output.at(n_draw_buffer);

            switch (current_draw_buffer)
            {
                case OpenGL::DrawBuffer::Back:
                {
                    auto new_node_io = OpenGL::NodeIO(m_swapchain_reference_ptr.get(),
                                                      Anvil::ImageAspectFlagBits::COLOR_BIT,
                                                      Anvil::ImageLayout::TRANSFER_DST_OPTIMAL,
                                                      Anvil::ImageLayout::UNKNOWN,
                                                      Anvil::PipelineStageFlagBits::TRANSFER_BIT,
                                                      Anvil::AccessFlagBits::TRANSFER_WRITE_BIT,
                                                      UINT32_MAX); //< in_fs_output_location - irrelevant

                    m_info_ptr->inputs.push_back(new_node_io);

                    break;
                }

                case OpenGL::DrawBuffer::Color_Attachment0:
                case OpenGL::DrawBuffer::Color_Attachment1:
                case OpenGL::DrawBuffer::Color_Attachment2:
                case OpenGL::DrawBuffer::Color_Attachment3:
                case OpenGL::DrawBuffer::Color_Attachment4:
                case OpenGL::DrawBuffer::Color_Attachment5:
                case OpenGL::DrawBuffer::Color_Attachment6:
                case OpenGL::DrawBuffer::Color_Attachment7:
                {
                    /* TODO: We don't have backend-side image & image view manager available yet */
                    vkgl_not_implemented();

                    break;
                }

                case OpenGL::DrawBuffer::None:
                {
                    continue;
                }

                default:
                {
                    vkgl_assert_fail();
                }
            }
        }
    }

    if (m_buffers_to_clear & OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_DEPTH)
    {
        /* TODO */
        if (fb_state_ptr->depth_attachment.type == OpenGL::FramebufferAttachmentObjectType::Framebuffer_Default)
        {
            auto new_node_io = OpenGL::NodeIO(m_swapchain_reference_ptr.get(),
                                              Anvil::ImageAspectFlagBits::DEPTH_BIT,
                                              Anvil::ImageLayout::UNKNOWN,
                                              Anvil::ImageLayout::TRANSFER_DST_OPTIMAL,
                                              Anvil::PipelineStageFlagBits::TRANSFER_BIT,
                                              Anvil::AccessFlagBits::TRANSFER_WRITE_BIT,
                                              UINT32_MAX); //< in_fs_output_location - irrelevant
        }
        else
        {
            vkgl_not_implemented();
        }
    }

    if (m_buffers_to_clear & OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_STENCIL)
    {
        /* TODO */
        if (fb_state_ptr->stencil_attachment.type == OpenGL::FramebufferAttachmentObjectType::Framebuffer_Default)
        {
            auto new_node_io = OpenGL::NodeIO(m_swapchain_reference_ptr.get(),
                                              Anvil::ImageAspectFlagBits::STENCIL_BIT,
                                              Anvil::ImageLayout::UNKNOWN,
                                              Anvil::ImageLayout::TRANSFER_DST_OPTIMAL,
                                              Anvil::PipelineStageFlagBits::TRANSFER_BIT,
                                              Anvil::AccessFlagBits::TRANSFER_WRITE_BIT,
                                              UINT32_MAX); //< in_fs_output_location - irrelevant
        }
        else
        {
            vkgl_not_implemented();
        }
    }

    /* Any image we modify must be exposed as both input and output. This is to avoid RaW, WaW and WaR conditions. */
    m_info_ptr->outputs = m_info_ptr->inputs;
}

void OpenGL::VKNodes::Clear::get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                                          const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const
{
    static const Anvil::QueueFamilyFlagBits supported_queue_fams[] =
    {
        Anvil::QueueFamilyFlagBits::COMPUTE_BIT,
        Anvil::QueueFamilyFlagBits::GRAPHICS_BIT,
    };

    *out_n_queue_fams_ptr   = sizeof(supported_queue_fams) / sizeof(supported_queue_fams[0]);
    *out_queue_fams_ptr_ptr = supported_queue_fams;
}

void OpenGL::VKNodes::Clear::record_commands(Anvil::CommandBufferBase*  in_cmd_buffer_ptr,
                                             const bool&                in_inside_renderpass,
                                             IVKFrameGraphNodeCallback* in_graph_callback_ptr) const
{
    // TODO: GL clear commands are affected by scissor + draw buffer settings!
    auto       state_manager_ptr = m_frontend_ptr->get_state_manager_ptr();
    const auto state_ptr         = state_manager_ptr->get_state         (m_context_state_ptr->get_payload().time_marker);

    /* TODO */
    vkgl_assert(!in_inside_renderpass);

    for (auto& current_output : m_info_ptr->outputs)
    {
        switch (current_output.type)
        {
            case OpenGL::NodeIOType::Swapchain_Image:
            {
                Anvil::ImageSubresourceRange subresource_range;
                const auto                   swapchain_image_index = in_graph_callback_ptr->get_acquired_swapchain_image_index();
                auto                         swapchain_ptr         = m_swapchain_reference_ptr->get_payload().swapchain_ptr;
                const auto                   image_ptr             = swapchain_ptr->get_image(swapchain_image_index);

                vkgl_assert(image_ptr != nullptr);

                /* Prepare subresource range struct.
                 *
                 * Default FB is a simple single-mip 2D image, so not much rocket science here
                 */
                subresource_range.aspect_mask      = current_output.swapchain_image_props.aspects_touched;
                subresource_range.base_array_layer = 0;
                subresource_range.base_mip_level   = 0;
                subresource_range.layer_count      = 1;
                subresource_range.level_count      = 1;

                if ((current_output.swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::COLOR_BIT) != 0)
                {
                    VkClearColorValue clear_color_value;

                    /* Prepare clear color struct.. */
                    static_assert(sizeof(clear_color_value.float32) == sizeof(state_ptr->color_clear_value), "Clear color sizes must match");

                    memcpy(clear_color_value.float32,
                           state_ptr->color_clear_value,
                           sizeof(clear_color_value.float32));

                    in_cmd_buffer_ptr->record_clear_color_image(image_ptr,
                                                                Anvil::ImageLayout::TRANSFER_DST_OPTIMAL,
                                                               &clear_color_value,
                                                                1, /* in_range_count */
                                                               &subresource_range);
                }

                if ((current_output.swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::DEPTH_BIT)   != 0 ||
                    (current_output.swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::STENCIL_BIT) != 0)
                {
                    VkClearDepthStencilValue clear_ds_value;

                    if ((current_output.swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::DEPTH_BIT) != 0)
                    {
                        clear_ds_value.depth = static_cast<float>(state_ptr->depth_clear_value);
                    }

                    if ((current_output.swapchain_image_props.aspects_touched & Anvil::ImageAspectFlagBits::STENCIL_BIT) != 0)
                    {
                        clear_ds_value.stencil = state_ptr->stencil_clear_value;
                    }

                    in_cmd_buffer_ptr->record_clear_depth_stencil_image(image_ptr,
                                                                        Anvil::ImageLayout::TRANSFER_DST_OPTIMAL,
                                                                       &clear_ds_value,
                                                                        1, /* in_range_count */
                                                                       &subresource_range);
                }

                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}
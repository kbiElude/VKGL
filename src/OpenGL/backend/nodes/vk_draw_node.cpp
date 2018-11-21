/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/swapchain.h"
#include "OpenGL/backend/nodes/vk_draw_node.h"
#include "OpenGL/backend/vk_buffer_manager.h"
#include "OpenGL/frontend/gl_framebuffer_manager.h"
#include "OpenGL/frontend/gl_state_manager.h"
#include "OpenGL/frontend/gl_vao_manager.h"
#include "OpenGL/types.h"
#include "OpenGL/utils_enum.h"

OpenGL::VKNodes::Draw::Draw(const IContextObjectManagers*            in_frontend_ptr,
                            OpenGL::IBackend*                        in_backend_ptr,
                            OpenGL::GLContextStateReferenceUniquePtr in_frontend_context_state_reference_ptr)
    :m_backend_ptr                         (in_backend_ptr),
     m_frontend_context_state_reference_ptr(std::move(in_frontend_context_state_reference_ptr) ),
     m_frontend_ptr                        (in_frontend_ptr)
{
    m_info_ptr.reset(new OpenGL::VKFrameGraphNodeInfo() );
    vkgl_assert(m_info_ptr != nullptr);
}

OpenGL::VKNodes::Draw::~Draw()
{
    /* Stub */
}

OpenGL::VKFrameGraphNodeUniquePtr OpenGL::VKNodes::Draw::create_arrays(const IContextObjectManagers*            in_frontend_ptr,
                                                                       IBackend*                                in_backend_ptr,
                                                                       OpenGL::GLContextStateReferenceUniquePtr in_frontend_context_state_reference_ptr,
                                                                       const GLint&                             in_first,
                                                                       const GLsizei&                           in_count,
                                                                       const OpenGL::DrawCallMode&              in_mode)
{
    OpenGL::VKFrameGraphNodeUniquePtr result_ptr(nullptr,
                                                 std::default_delete<OpenGL::IVKFrameGraphNode>() );

    result_ptr.reset(new OpenGL::VKNodes::Draw(in_frontend_ptr,
                                               in_backend_ptr,
                                               std::move(in_frontend_context_state_reference_ptr)) );
    vkgl_assert(result_ptr != nullptr);

    {
        auto new_node_ptr = dynamic_cast<OpenGL::VKNodes::Draw*>(result_ptr.get() );

        new_node_ptr->m_args.count = in_count;
        new_node_ptr->m_args.first = in_first;
        new_node_ptr->m_args.mode  = in_mode;
    }

    return result_ptr;
}

void OpenGL::VKNodes::Draw::do_cpu_prepass(IVKFrameGraphNodeCallback* in_callback_ptr)
{
    const auto acquired_swapchain_image_index = in_callback_ptr->get_acquired_swapchain_image_index();
    auto       backend_buffer_manager_ptr     = m_backend_ptr->get_buffer_manager_ptr              ();
    auto       backend_swapchain_manager_ptr  = m_backend_ptr->get_swapchain_manager_ptr           ();
    const auto context_state_ptr              = m_frontend_ptr->get_state_manager_ptr              ()->get_state(m_frontend_context_state_reference_ptr->get_payload().time_marker);
    auto       frontend_fb_manager_ptr        = m_frontend_ptr->get_framebuffer_manager_ptr        ();
    auto       frontend_vao_manager_ptr       = m_frontend_ptr->get_vao_manager_ptr                ();

    vkgl_assert(context_state_ptr != nullptr);

    /* Initialize the info structure:
     *
     * 1. Expose as inputs any buffers the draw call uses for vertex array fetches. */
    {
        const OpenGL::VertexArrayObjectState* vao_state_ptr = nullptr;

        frontend_vao_manager_ptr->get_vao_state_ptr(context_state_ptr->vao_reference_ptr->get_payload().id,
                                                   &context_state_ptr->vao_reference_ptr->get_payload().time_marker,
                                                   &vao_state_ptr);
        vkgl_assert(vao_state_ptr != nullptr);

        for (const auto& current_vaa : vao_state_ptr->vertex_attribute_arrays)
        {
            VKBufferReferenceUniquePtr backend_buffer_reference_ptr;
            const auto&                frontend_buffer_reference_ptr = current_vaa.buffer_binding_ptr;

            backend_buffer_reference_ptr = backend_buffer_manager_ptr->acquire_object(frontend_buffer_reference_ptr->get_payload().id,
                                                                                      frontend_buffer_reference_ptr->get_payload().object_creation_time,
                                                                                      frontend_buffer_reference_ptr->get_payload().time_marker);
            vkgl_assert(backend_buffer_reference_ptr != nullptr);

            m_info_ptr->inputs.push_back(
                OpenGL::NodeIO(backend_buffer_reference_ptr.get(),
                               reinterpret_cast<VkDeviceSize>(current_vaa.pointer), /* in_start_offset */
                               OpenGL::Utils::get_n_bytes_for_vertex_attribute_array_type(current_vaa.type) * current_vaa.stride,
                               Anvil::PipelineStageFlagBits::VERTEX_INPUT_BIT,
                               Anvil::AccessFlagBits::VERTEX_ATTRIBUTE_READ_BIT)
            );

            m_owned_buffer_reference_ptrs.push_back(std::move(backend_buffer_reference_ptr) );
        }
    }

    /* 2. Expose any render-targets we modify with the draw call as outputs. They also need to be marked as inputs,
     *    if they need to be read back from prior to being modified (ie. blending is on, etc.)
     */
    {
        auto fb_state_ptr   = frontend_fb_manager_ptr->get_framebuffer_state(context_state_ptr->draw_framebuffer_reference_ptr->get_payload().id,
                                                                            &context_state_ptr->draw_framebuffer_reference_ptr->get_payload().time_marker);
        bool uses_swapchain = false;

        vkgl_assert(fb_state_ptr != nullptr);


        for (const auto& current_draw_buffer : fb_state_ptr->draw_buffer_per_color_output)
        {
            if (current_draw_buffer == OpenGL::DrawBuffer::None)
            {
                continue;
            }

            switch (current_draw_buffer)
            {
                case OpenGL::DrawBuffer::Back:
                {
                    vkgl_assert(acquired_swapchain_image_index != UINT32_MAX);

                    if (m_owned_swapchain_reference_ptr == nullptr)
                    {
                        /* TODO: We should NOT be using ToT time marker here! */
                        m_owned_swapchain_reference_ptr = backend_swapchain_manager_ptr->acquire_swapchain(backend_swapchain_manager_ptr->get_tot_time_marker() );
                        vkgl_assert(m_owned_swapchain_reference_ptr == nullptr);
                    }

                    uses_swapchain = true;

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
                    vkgl_not_implemented();

                    break;
                }

                default:
                {
                    vkgl_assert_fail();

                    continue;
                }
            }
        }

        if (uses_swapchain)
        {
            const bool uses_color_reads    = (context_state_ptr->is_blend_enabled              ||
                                              context_state_ptr->is_color_logic_op_enabled);
            const bool uses_color_writes   = ((context_state_ptr->color_writemask_for_draw_buffers) != 0);
            const bool uses_depth_reads    = (context_state_ptr->is_depth_test_enabled);
            const bool uses_depth_writes   = (context_state_ptr->is_depth_test_enabled         &&
                                              context_state_ptr->depth_writemask);
            const bool uses_stencil_reads  = (context_state_ptr->is_stencil_test_enabled);
            const bool uses_stencil_writes = (context_state_ptr->is_stencil_test_enabled       &&
                                              (context_state_ptr->stencil_writemask_back  != 0 ||
                                               context_state_ptr->stencil_writemask_front != 0));

            const auto ds_layout = ( uses_depth_writes &&  uses_stencil_writes) ? Anvil::ImageLayout::DEPTH_STENCIL_ATTACHMENT_OPTIMAL
                                 : ( uses_depth_writes && !uses_stencil_writes) ? Anvil::ImageLayout::DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL
                                 : (!uses_depth_writes &&  uses_stencil_writes) ? Anvil::ImageLayout::DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL
                                 : ( uses_depth_reads  ||  uses_stencil_reads)  ? Anvil::ImageLayout::DEPTH_STENCIL_READ_ONLY_OPTIMAL
                                                                                : Anvil::ImageLayout::UNKNOWN;

            const Anvil::PipelineStageFlags pipeline_stages  = (Anvil::PipelineStageFlagBits::COLOR_ATTACHMENT_OUTPUT_BIT)                                                                 |
                                                               ((uses_depth_writes  || uses_stencil_writes) ? Anvil::PipelineStageFlagBits::EARLY_FRAGMENT_TESTS_BIT | Anvil::PipelineStageFlagBits::LATE_FRAGMENT_TESTS_BIT
                                                                                                            : Anvil::PipelineStageFlagBits::NONE);
            const auto                      access_mask      = ((uses_color_reads)                          ? Anvil::AccessFlagBits::COLOR_ATTACHMENT_READ_BIT          : Anvil::AccessFlagBits::NONE)      |
                                                                                                             (Anvil::AccessFlagBits::COLOR_ATTACHMENT_WRITE_BIT)                                            |
                                                               ((uses_depth_reads   || uses_stencil_reads)  ? Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_READ_BIT  : Anvil::AccessFlagBits::NONE)      |
                                                               ((uses_depth_writes  || uses_stencil_writes) ? Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_WRITE_BIT : Anvil::AccessFlagBits::NONE);
            const Anvil::ImageAspectFlags   aspects_accessed = ((uses_color_reads)                          ? Anvil::ImageAspectFlagBits::COLOR_BIT                     : Anvil::ImageAspectFlagBits::NONE) |
                                                               ((uses_depth_reads   || uses_depth_writes)   ? Anvil::ImageAspectFlagBits::DEPTH_BIT                     : Anvil::ImageAspectFlagBits::NONE) |
                                                               ((uses_stencil_reads || uses_stencil_writes) ? Anvil::ImageAspectFlagBits::STENCIL_BIT                   : Anvil::ImageAspectFlagBits::NONE);

            auto new_node_io = OpenGL::NodeIO(m_owned_swapchain_reference_ptr.get(),
                                              aspects_accessed,
                                              Anvil::ImageLayout::COLOR_ATTACHMENT_OPTIMAL, /* in_color_image_layout */
                                              ds_layout,
                                              pipeline_stages,
                                              access_mask);

            m_info_ptr->inputs.push_back(new_node_io);

            if (uses_color_writes)
            {
                m_info_ptr->outputs.push_back(new_node_io);
            }
        }
    }

    /* TODO: Buffer support, texture support .. */

    /* 3. Fetch the GFX pipeline instance we're going to use for the draw call. */
    {
        vkgl_not_implemented();
    }

    /* TODO: Descriptor sets .. */
}

void OpenGL::VKNodes::Draw::record_commands(Anvil::CommandBufferBase*  in_cmd_buffer_ptr,
                                            const bool&                in_inside_renderpass,
                                            IVKFrameGraphNodeCallback* in_graph_callback_ptr) const
{
}

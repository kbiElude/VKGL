/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/buffer_create_info.h"
#include "Anvil/include/wrappers/buffer.h"
#include "Anvil/include/wrappers/command_buffer.h"
#include "Anvil/include/wrappers/memory_block.h"
#include "Anvil/include/wrappers/swapchain.h"
#include "OpenGL/backend/nodes/vk_draw_node.h"
#include "OpenGL/backend/vk_buffer_manager.h"
#include "OpenGL/backend/vk_gfx_pipeline_manager.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "OpenGL/frontend/gl_framebuffer_manager.h"
#include "OpenGL/frontend/gl_program_manager.h"
#include "OpenGL/frontend/gl_state_manager.h"
#include "OpenGL/frontend/gl_vao_manager.h"
#include "OpenGL/types.h"
#include "OpenGL/utils_enum.h"

OpenGL::VKNodes::Draw::Draw(const DrawType&                                  in_type,
                            const IContextObjectManagers*                    in_frontend_ptr,
                            OpenGL::IBackend*                                in_backend_ptr,
                            OpenGL::GLContextStateReferenceUniquePtr         in_frontend_context_state_reference_ptr,
                            OpenGL::GLContextStateBindingReferencesUniquePtr in_frontend_context_state_binding_references_ptr)
    :m_backend_ptr                                  (in_backend_ptr),
     m_frontend_context_state_binding_references_ptr(std::move(in_frontend_context_state_binding_references_ptr) ),
     m_frontend_context_state_reference_ptr         (std::move(in_frontend_context_state_reference_ptr) ),
     m_frontend_ptr                                 (in_frontend_ptr),
     m_type                                         (in_type)
{
    m_info_ptr.reset(new OpenGL::VKFrameGraphNodeInfo() );
    vkgl_assert(m_info_ptr != nullptr);

    m_frontend_context_state_ptr = m_frontend_ptr->get_state_manager_ptr()->get_state(m_frontend_context_state_reference_ptr->get_payload().time_marker);
    vkgl_assert(m_frontend_context_state_ptr != nullptr);
}

OpenGL::VKNodes::Draw::~Draw()
{
    /* Stub */
}

OpenGL::VKFrameGraphNodeUniquePtr OpenGL::VKNodes::Draw::create(const DrawType&                                  in_type,
                                                                const IContextObjectManagers*                    in_frontend_ptr,
                                                                IBackend*                                        in_backend_ptr,
                                                                OpenGL::GLContextStateReferenceUniquePtr         in_frontend_context_state_reference_ptr,
                                                                OpenGL::GLContextStateBindingReferencesUniquePtr in_frontend_context_state_binding_references_ptr,
                                                                const GLint&                                     in_first,
                                                                const GLsizei&                                   in_count,
                                                                const OpenGL::DrawCallMode&                      in_mode,
                                                                const OpenGL::DrawCallIndexType&                 in_opt_index_data_type,
                                                                const GLuint&                                    in_opt_index_buffer_offset)
{
    OpenGL::VKFrameGraphNodeUniquePtr result_ptr(nullptr,
                                                 std::default_delete<OpenGL::IVKFrameGraphNode>() );

    result_ptr.reset(new OpenGL::VKNodes::Draw(in_type,
                                               in_frontend_ptr,
                                               in_backend_ptr,
                                               std::move(in_frontend_context_state_reference_ptr),
                                               std::move(in_frontend_context_state_binding_references_ptr) ) );
    vkgl_assert(result_ptr != nullptr);

    {
        auto new_node_ptr = dynamic_cast<OpenGL::VKNodes::Draw*>(result_ptr.get() );

        if (in_type == DrawType::Indexed)
        {
            vkgl_assert(in_opt_index_data_type == OpenGL::DrawCallIndexType::Unsigned_Int    || //< todo: Add support for U8 indices.
                        in_opt_index_data_type == OpenGL::DrawCallIndexType::Unsigned_Short);
        }

        new_node_ptr->m_args.count               = in_count;
        new_node_ptr->m_args.first               = in_first;
        new_node_ptr->m_args.index_buffer_offset = in_opt_index_buffer_offset;
        new_node_ptr->m_args.index_data_type     = in_opt_index_data_type;
        new_node_ptr->m_args.mode                = in_mode;
    }

    return result_ptr;
}

void OpenGL::VKNodes::Draw::do_cpu_prepass(IVKFrameGraphNodeCallback* in_callback_ptr)
{
    const auto                            acquired_swapchain_image_index   = in_callback_ptr->get_acquired_swapchain_image_index();
    auto                                  backend_buffer_manager_ptr       = m_backend_ptr->get_buffer_manager_ptr              ();
    auto                                  backend_gfx_pipeline_manager_ptr = m_backend_ptr->get_gfx_pipeline_manager_ptr        ();
    auto                                  frontend_buffer_manager_ptr      = m_frontend_ptr->get_buffer_manager_ptr             ();
    auto                                  frontend_fb_manager_ptr          = m_frontend_ptr->get_framebuffer_manager_ptr        ();
    auto                                  frontend_vao_manager_ptr         = m_frontend_ptr->get_vao_manager_ptr                ();
    const OpenGL::VertexArrayObjectState* frontend_vao_state_ptr           = nullptr;

    vkgl_assert(m_frontend_context_state_ptr != nullptr);

    frontend_vao_manager_ptr->get_vao_state_ptr(m_frontend_context_state_binding_references_ptr->vao_reference_ptr->get_payload().id,
                                               &m_frontend_context_state_binding_references_ptr->vao_reference_ptr->get_payload().time_marker,
                                               &frontend_vao_state_ptr);
    vkgl_assert(frontend_vao_state_ptr != nullptr);

    /* Initialize the info structure:
     *
     * 1a. Expose as inputs any buffers the draw call uses for vertex array fetches. */
    {

        for (const auto& current_vaa : frontend_vao_state_ptr->vertex_attribute_arrays)
        {
            VKBufferReferenceUniquePtr backend_buffer_reference_ptr;
            const auto&                frontend_buffer_reference_ptr = current_vaa.buffer_binding_ptr;

            if (frontend_buffer_reference_ptr == nullptr)
            {
                continue;
            }

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

    /* 1b. Same goes for index buffers */
    if (m_type == DrawType::Indexed)
    {
        auto        backend_index_buffer_reference_ptr  = backend_buffer_manager_ptr->acquire_object           (frontend_vao_state_ptr->element_array_buffer_binding_ptr->get_payload().id,
                                                                                                                frontend_vao_state_ptr->element_array_buffer_binding_ptr->get_payload().object_creation_time,
                                                                                                                frontend_vao_state_ptr->element_array_buffer_binding_ptr->get_payload().time_marker);
        const auto  index_size                         = OpenGL::Utils::get_draw_call_index_type_size_per_index(m_args.index_data_type);
        const auto  index_buffer_binding_size          = m_args.count * index_size;

        vkgl_assert(backend_index_buffer_reference_ptr != nullptr);

        m_info_ptr->inputs.push_back(
            OpenGL::NodeIO(backend_index_buffer_reference_ptr.get(),
                           m_args.index_buffer_offset,
                           index_buffer_binding_size,
                           Anvil::PipelineStageFlagBits::VERTEX_INPUT_BIT,
                           Anvil::AccessFlagBits::INDEX_READ_BIT)
        );

        m_index_buffer_reference_ptr = std::move(backend_index_buffer_reference_ptr);
    }

    /* 2. Expose any render-targets we modify with the draw call as outputs. They also need to be marked as inputs,
     *    if they need to be read back from prior to being modified (ie. blending is on, etc.)
     */
    {
        auto           fb_state_ptr              = frontend_fb_manager_ptr->get_framebuffer_state(m_frontend_context_state_ptr->draw_framebuffer_proxy_reference_ptr->get_payload().id,
                                                                                                 &m_frontend_context_state_ptr->draw_framebuffer_proxy_reference_ptr->get_payload().time_marker);
        const uint32_t n_draw_buffers            = static_cast<uint32_t>(fb_state_ptr->draw_buffer_per_color_output.size() );
        uint32_t       swapchain_output_location = UINT32_MAX;

        vkgl_assert(fb_state_ptr != nullptr);

        for (uint32_t n_draw_buffer = 0;
                      n_draw_buffer < n_draw_buffers;
                    ++n_draw_buffer)
        {
            const auto& current_draw_buffer = fb_state_ptr->draw_buffer_per_color_output.at(n_draw_buffer);

            if (current_draw_buffer == OpenGL::DrawBuffer::None)
            {
                continue;
            }

            switch (current_draw_buffer)
            {
                case OpenGL::DrawBuffer::Back:
                {
                    vkgl_assert(acquired_swapchain_image_index != UINT32_MAX);

                    swapchain_output_location = n_draw_buffer;
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

        if (swapchain_output_location != UINT32_MAX)
        {
            const bool uses_color_reads    =  (m_frontend_context_state_ptr->is_blend_enabled              ||
                                               m_frontend_context_state_ptr->is_color_logic_op_enabled);
            const bool uses_color_writes   = ((m_frontend_context_state_ptr->color_writemask_for_draw_buffers) != 0);
            const bool uses_depth_reads    =  (m_frontend_context_state_ptr->is_depth_test_enabled);
            const bool uses_depth_writes   =  (m_frontend_context_state_ptr->is_depth_test_enabled         &&
                                               m_frontend_context_state_ptr->depth_writemask);
            const bool uses_stencil_reads  =  (m_frontend_context_state_ptr->is_stencil_test_enabled);
            const bool uses_stencil_writes =  (m_frontend_context_state_ptr->is_stencil_test_enabled       &&
                                              (m_frontend_context_state_ptr->stencil_writemask_back  != 0 ||
                                               m_frontend_context_state_ptr->stencil_writemask_front != 0));

            const auto ds_layout = ( uses_depth_writes &&  uses_stencil_writes) ? Anvil::ImageLayout::DEPTH_STENCIL_ATTACHMENT_OPTIMAL
                                 : ( uses_depth_writes && !uses_stencil_writes) ? Anvil::ImageLayout::DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL
                                 : (!uses_depth_writes &&  uses_stencil_writes) ? Anvil::ImageLayout::DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL
                                 : ( uses_depth_reads  ||  uses_stencil_reads)  ? Anvil::ImageLayout::DEPTH_STENCIL_READ_ONLY_OPTIMAL
                                                                                : Anvil::ImageLayout::UNKNOWN;

            const Anvil::PipelineStageFlags pipeline_stages  = (Anvil::PipelineStageFlagBits::COLOR_ATTACHMENT_OUTPUT_BIT)                                                                                                   |
                                                               ((uses_depth_writes  || uses_stencil_writes) ? Anvil::PipelineStageFlagBits::EARLY_FRAGMENT_TESTS_BIT | Anvil::PipelineStageFlagBits::LATE_FRAGMENT_TESTS_BIT
                                                                                                            : Anvil::PipelineStageFlagBits::NONE);
            const auto                      access_mask      = ((uses_color_reads)                          ? Anvil::AccessFlagBits::COLOR_ATTACHMENT_READ_BIT          : Anvil::AccessFlagBits::NONE)      |
                                                               ((uses_color_writes)                         ? Anvil::AccessFlagBits::COLOR_ATTACHMENT_WRITE_BIT         : Anvil::AccessFlagBits::NONE)      |
                                                               ((uses_depth_reads   || uses_stencil_reads)  ? Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_READ_BIT  : Anvil::AccessFlagBits::NONE)      |
                                                               ((uses_depth_writes  || uses_stencil_writes) ? Anvil::AccessFlagBits::DEPTH_STENCIL_ATTACHMENT_WRITE_BIT : Anvil::AccessFlagBits::NONE);
            const Anvil::ImageAspectFlags   aspects_accessed = ((uses_color_reads   || uses_color_writes)   ? Anvil::ImageAspectFlagBits::COLOR_BIT                     : Anvil::ImageAspectFlagBits::NONE) |
                                                               ((uses_depth_reads   || uses_depth_writes)   ? Anvil::ImageAspectFlagBits::DEPTH_BIT                     : Anvil::ImageAspectFlagBits::NONE) |
                                                               ((uses_stencil_reads || uses_stencil_writes) ? Anvil::ImageAspectFlagBits::STENCIL_BIT                   : Anvil::ImageAspectFlagBits::NONE);

            auto new_node_io = OpenGL::NodeIO(nullptr, /* in_alwaysnull_vk_swapchain_reference_ptr */
                                              aspects_accessed,
                                              Anvil::ImageLayout::COLOR_ATTACHMENT_OPTIMAL, /* in_color_image_layout */
                                              ds_layout,
                                              pipeline_stages,
                                              access_mask,
                                              swapchain_output_location);

            m_info_ptr->inputs.push_back(new_node_io);

            if (uses_color_writes)
            {
                m_info_ptr->outputs.push_back(new_node_io);
            }
        }
    }

    /* TODO: Buffer support, texture support .. */

    /* TODO: Descriptor sets .. */
}

void OpenGL::VKNodes::Draw::record_commands(Anvil::CommandBufferBase*  in_cmd_buffer_ptr,
                                            const bool&                in_inside_renderpass,
                                            IVKFrameGraphNodeCallback* in_graph_callback_ptr) const
{
    auto                        backend_buffer_manager_ptr   = m_backend_ptr->get_buffer_manager_ptr                                              ();
    Anvil::PipelineID           pipeline_id                  = UINT32_MAX;
    auto                        frontend_program_manager_ptr = m_frontend_ptr->get_program_manager_ptr                                            ();
    auto                        frontend_vao_manager_ptr     = m_frontend_ptr->get_vao_manager_ptr();
    const auto&                 program_payload              = m_frontend_context_state_binding_references_ptr->program_reference_ptr->get_payload();
    const OpenGL::PostLinkData* program_post_link_data_ptr   = nullptr;

    frontend_program_manager_ptr->get_program_post_link_data_ptr(program_payload.id,
                                                                &program_payload.time_marker,
                                                                &program_post_link_data_ptr);

    if (program_post_link_data_ptr == nullptr)
    {
        vkgl_assert(program_post_link_data_ptr != nullptr);

        goto end;
    }

    /* Fetch the GFX pipeline instance we're going to use for the draw call. */
    vkgl_assert(in_inside_renderpass);

    pipeline_id = in_graph_callback_ptr->get_pipeline_id(m_args.mode);
    vkgl_assert(pipeline_id != UINT32_MAX);

    /* Update pipeline states */
    {
        Anvil::PipelineID bound_pipeline_id = UINT32_MAX;

        if (!in_graph_callback_ptr->get_bound_pipeline_id(&bound_pipeline_id)                ||
             bound_pipeline_id                                                != pipeline_id)
        {
            in_cmd_buffer_ptr->record_bind_pipeline(Anvil::PipelineBindPoint::GRAPHICS,
                                                    pipeline_id);

            in_graph_callback_ptr->set_bound_pipeline_id(pipeline_id);
        }
    }

    {
        float      bound_dynamic_blend_color_state[4];
        const bool needs_blend_constants              = (m_frontend_context_state_ptr->is_blend_enabled)                                                        &&
                                                        (m_frontend_context_state_ptr->blend_func_dst_alpha == OpenGL::BlendFunction::Constant_Alpha           ||
                                                         m_frontend_context_state_ptr->blend_func_dst_alpha == OpenGL::BlendFunction::Constant_Color           ||
                                                         m_frontend_context_state_ptr->blend_func_dst_alpha == OpenGL::BlendFunction::One_Minus_Constant_Alpha ||
                                                         m_frontend_context_state_ptr->blend_func_dst_alpha == OpenGL::BlendFunction::One_Minus_Constant_Color ||
                                                         m_frontend_context_state_ptr->blend_func_dst_rgb   == OpenGL::BlendFunction::Constant_Alpha           ||
                                                         m_frontend_context_state_ptr->blend_func_dst_rgb   == OpenGL::BlendFunction::Constant_Color           ||
                                                         m_frontend_context_state_ptr->blend_func_dst_rgb   == OpenGL::BlendFunction::One_Minus_Constant_Alpha ||
                                                         m_frontend_context_state_ptr->blend_func_dst_rgb   == OpenGL::BlendFunction::One_Minus_Constant_Color ||
                                                         m_frontend_context_state_ptr->blend_func_src_alpha == OpenGL::BlendFunction::Constant_Alpha           ||
                                                         m_frontend_context_state_ptr->blend_func_src_alpha == OpenGL::BlendFunction::Constant_Color           ||
                                                         m_frontend_context_state_ptr->blend_func_src_alpha == OpenGL::BlendFunction::One_Minus_Constant_Alpha ||
                                                         m_frontend_context_state_ptr->blend_func_src_alpha == OpenGL::BlendFunction::One_Minus_Constant_Color ||
                                                         m_frontend_context_state_ptr->blend_func_src_rgb   == OpenGL::BlendFunction::Constant_Alpha           ||
                                                         m_frontend_context_state_ptr->blend_func_src_rgb   == OpenGL::BlendFunction::Constant_Color           ||
                                                         m_frontend_context_state_ptr->blend_func_src_rgb   == OpenGL::BlendFunction::One_Minus_Constant_Alpha ||
                                                         m_frontend_context_state_ptr->blend_func_src_rgb   == OpenGL::BlendFunction::One_Minus_Constant_Color);

        if (needs_blend_constants                                                                            &&
            (!in_graph_callback_ptr->get_bound_dynamic_blend_color_state(bound_dynamic_blend_color_state)    ||
              fabs(bound_dynamic_blend_color_state[0] - m_frontend_context_state_ptr->blend_color[0]) > 1e-4 ||
              fabs(bound_dynamic_blend_color_state[1] - m_frontend_context_state_ptr->blend_color[1]) > 1e-4 ||
              fabs(bound_dynamic_blend_color_state[2] - m_frontend_context_state_ptr->blend_color[2]) > 1e-4 ||
              fabs(bound_dynamic_blend_color_state[3] - m_frontend_context_state_ptr->blend_color[3]) ))
        {
            in_cmd_buffer_ptr->record_set_blend_constants(m_frontend_context_state_ptr->blend_color);

            in_graph_callback_ptr->set_bound_dynamic_blend_color_state(m_frontend_context_state_ptr->blend_color);
        }
    }

    {
        /* TODO: Exclude if final vertex stage does not generate one of the line primitive types. */
        float bound_line_width_state = 0.0f;

        if (!in_graph_callback_ptr->get_bound_dynamic_line_width_state(&bound_line_width_state)         ||
             fabs(bound_line_width_state - m_frontend_context_state_ptr->line_width)            > 1e-4)
        {
            const float& line_width = m_frontend_context_state_ptr->line_width;

            in_cmd_buffer_ptr->record_set_line_width(line_width);

            in_graph_callback_ptr->set_bound_dynamic_line_width_state(m_frontend_context_state_ptr->line_width);
        }
    }

    {
        VkRect2D   bound_scissor_state;
        const bool needs_scissor_state = m_frontend_context_state_ptr->is_scissor_test_enabled;
        int32_t    ref_data[4];

        if (needs_scissor_state)
        {
            ref_data[0] = m_frontend_context_state_ptr->scissor_box[0];
            ref_data[1] = m_frontend_context_state_ptr->scissor_box[1];
            ref_data[2] = m_frontend_context_state_ptr->scissor_box[2];
            ref_data[3] = m_frontend_context_state_ptr->scissor_box[3];
        }
        else
        {
            ref_data[0] = m_frontend_context_state_ptr->viewport[0];
            ref_data[1] = m_frontend_context_state_ptr->viewport[1];
            ref_data[2] = m_frontend_context_state_ptr->viewport[2];
            ref_data[3] = m_frontend_context_state_ptr->viewport[3];
        }

        if (!in_graph_callback_ptr->get_bound_dynamic_scissor_state(&bound_scissor_state)                ||
             bound_scissor_state.extent.height                                            != ref_data[3] ||
             bound_scissor_state.extent.width                                             != ref_data[2] ||
             bound_scissor_state.offset.x                                                 != ref_data[0] ||
             bound_scissor_state.offset.y                                                 != ref_data[1])
        {
            VkRect2D scissor;

            scissor.extent.height = ref_data[3];
            scissor.extent.width  = ref_data[2];
            scissor.offset.x      = ref_data[0];
            scissor.offset.y      = ref_data[1];

            in_cmd_buffer_ptr->record_set_scissor(0, /* in_first_scissor */
                                                  1, /* in_scissor_count */
                                                 &scissor);

            in_graph_callback_ptr->set_bound_dynamic_scissor_state(scissor);
        }
    }

    {
        const bool needs_stencil_state = m_frontend_context_state_ptr->is_stencil_test_enabled;

        if (needs_stencil_state)
        {
            /* Compare masks */
            {
                int32_t bound_stencil_compare_mask_back = 0;

                if (!in_graph_callback_ptr->get_bound_dynamic_stencil_compare_mask_back_state(&bound_stencil_compare_mask_back) ||
                     bound_stencil_compare_mask_back                                                                            != m_frontend_context_state_ptr->stencil_value_mask_back)
                {
                    const auto& stencil_compare_mask_back = m_frontend_context_state_ptr->stencil_value_mask_back;

                    in_cmd_buffer_ptr->record_set_stencil_compare_mask(Anvil::StencilFaceFlagBits::BACK_BIT,
                                                                       stencil_compare_mask_back);

                    in_graph_callback_ptr->set_bound_dynamic_stencil_compare_mask_back_state(stencil_compare_mask_back);
                }
            }

            {
                int32_t bound_stencil_compare_mask_front = 0;

                if (!in_graph_callback_ptr->get_bound_dynamic_stencil_compare_mask_front_state(&bound_stencil_compare_mask_front) ||
                     bound_stencil_compare_mask_front                                                                             != m_frontend_context_state_ptr->stencil_value_mask_front)
                {
                    const auto& stencil_compare_mask_front = m_frontend_context_state_ptr->stencil_value_mask_front;

                    in_cmd_buffer_ptr->record_set_stencil_compare_mask(Anvil::StencilFaceFlagBits::FRONT_BIT,
                                                                       stencil_compare_mask_front);

                    in_graph_callback_ptr->set_bound_dynamic_stencil_compare_mask_front_state(stencil_compare_mask_front);
                }
            }

            /* Reference values */
            {
                int32_t bound_stencil_reference_back = 0;

                if (!in_graph_callback_ptr->get_bound_dynamic_stencil_reference_back_state(&bound_stencil_reference_back)                                                                ||
                     bound_stencil_reference_back                                                                         != m_frontend_context_state_ptr->stencil_reference_value_back)
                {
                    const auto& stencil_reference_back = m_frontend_context_state_ptr->stencil_reference_value_back;

                    in_cmd_buffer_ptr->record_set_stencil_reference(Anvil::StencilFaceFlagBits::BACK_BIT,
                                                                    stencil_reference_back);

                    in_graph_callback_ptr->set_bound_dynamic_stencil_reference_back_state(stencil_reference_back);
                }
            }

            {
                int32_t bound_stencil_reference_front = 0;

                if (!in_graph_callback_ptr->get_bound_dynamic_stencil_reference_front_state(&bound_stencil_reference_front)                                                              ||
                     bound_stencil_reference_front                                                                        != m_frontend_context_state_ptr->stencil_reference_value_front)
                {
                    const auto& stencil_reference_front = m_frontend_context_state_ptr->stencil_reference_value_front;

                    in_cmd_buffer_ptr->record_set_stencil_reference(Anvil::StencilFaceFlagBits::FRONT_BIT,
                                                                    stencil_reference_front);

                    in_graph_callback_ptr->set_bound_dynamic_stencil_reference_front_state(stencil_reference_front);
                }
            }

            /* Write masks */
            {
                int32_t bound_stencil_write_mask_back = 0;

                if (!in_graph_callback_ptr->get_bound_dynamic_stencil_write_mask_back_state(&bound_stencil_write_mask_back)                                                          ||
                    bound_stencil_write_mask_back                                                                           != m_frontend_context_state_ptr->stencil_writemask_back)
                {
                    const auto& stencil_write_mask_back  = m_frontend_context_state_ptr->stencil_writemask_back;

                    in_cmd_buffer_ptr->record_set_stencil_write_mask(Anvil::StencilFaceFlagBits::BACK_BIT,
                                                                     stencil_write_mask_back);

                    in_graph_callback_ptr->set_bound_dynamic_stencil_write_mask_back_state(stencil_write_mask_back);
                }
            }

            {
                int32_t bound_stencil_write_mask_front = 0;

                if (!in_graph_callback_ptr->get_bound_dynamic_stencil_write_mask_front_state(&bound_stencil_write_mask_front)                                                          ||
                    bound_stencil_write_mask_front                                                                            != m_frontend_context_state_ptr->stencil_writemask_front)
                {
                    const auto& stencil_write_mask_front = m_frontend_context_state_ptr->stencil_writemask_front;

                    in_cmd_buffer_ptr->record_set_stencil_write_mask(Anvil::StencilFaceFlagBits::FRONT_BIT,
                                                                     stencil_write_mask_front);

                    in_graph_callback_ptr->set_bound_dynamic_stencil_write_mask_front_state(stencil_write_mask_front);
                }
            }
        }
    }

    {
        VkViewport bound_viewport;

        if (!in_graph_callback_ptr->get_bound_dynamic_viewport_state(&bound_viewport)                                                                                              ||
            bound_viewport.height                                                     != -m_frontend_context_state_ptr->viewport   [3]                                             ||
            bound_viewport.maxDepth                                                   !=  m_frontend_context_state_ptr->depth_range[1]                                             ||
            bound_viewport.minDepth                                                   !=  m_frontend_context_state_ptr->depth_range[0]                                             ||
            bound_viewport.width                                                      !=  m_frontend_context_state_ptr->viewport   [2]                                             ||
            bound_viewport.x                                                          !=  m_frontend_context_state_ptr->viewport   [0]                                             ||
            bound_viewport.y                                                          !=  m_frontend_context_state_ptr->viewport   [3] - m_frontend_context_state_ptr->viewport[1])
        {
            VkViewport viewport;

            viewport.height   = -m_frontend_context_state_ptr->viewport   [3];
            viewport.maxDepth =  m_frontend_context_state_ptr->depth_range[1];
            viewport.minDepth =  m_frontend_context_state_ptr->depth_range[0];
            viewport.width    =  m_frontend_context_state_ptr->viewport   [2];
            viewport.x        =  m_frontend_context_state_ptr->viewport   [0];
            viewport.y        =  m_frontend_context_state_ptr->viewport   [3] - m_frontend_context_state_ptr->viewport[1];

            in_cmd_buffer_ptr->record_set_viewport(0, /* in_first_viewport */
                                                   1, /* in_viewport_count */
                                                  &viewport);

            in_graph_callback_ptr->set_bound_dynamic_viewport_state(viewport);
        }
    }

    if (program_post_link_data_ptr->active_attributes.size() > 0)
    {
        static constexpr uint32_t n_max_vertex_buffer_bindings = 8;

        VkDeviceSize                          buffer_offsets[n_max_vertex_buffer_bindings] = {0};
        Anvil::Buffer*                        buffer_ptrs   [n_max_vertex_buffer_bindings] = {nullptr};
        const auto&                           vao_payload                                  = m_frontend_context_state_binding_references_ptr->vao_reference_ptr->get_payload();
        const OpenGL::VertexArrayObjectState* vao_state_ptr                                = nullptr;

        vkgl_assert(n_max_vertex_buffer_bindings > program_post_link_data_ptr->max_active_attribute_location);

        if (!frontend_vao_manager_ptr->get_vao_state_ptr(vao_payload.id,
                                                        &vao_payload.time_marker,
                                                        &vao_state_ptr) )
        {
            vkgl_assert_fail();

            goto end;
        }

        vkgl_assert(vao_state_ptr != nullptr);

        for (const auto& current_active_attribute : program_post_link_data_ptr->active_attributes)
        {
            OpenGL::VKBufferReferenceUniquePtr backend_buffer_reference_ptr;
            const auto&                        current_active_attribute_location = current_active_attribute.location;
            const auto&                        vaa_props                        = vao_state_ptr->vertex_attribute_arrays.at(current_active_attribute_location);

            if (!vaa_props.enabled                        ||
                 vaa_props.buffer_binding_ptr == nullptr)
            {
                continue;
            }


            backend_buffer_reference_ptr = backend_buffer_manager_ptr->acquire_object(vaa_props.buffer_binding_ptr->get_payload().id,
                                                                                      vaa_props.buffer_binding_ptr->get_payload().object_creation_time,
                                                                                      vaa_props.buffer_binding_ptr->get_payload().time_marker);

            vkgl_assert(backend_buffer_reference_ptr != nullptr);

            buffer_ptrs   [current_active_attribute_location] = backend_buffer_reference_ptr->get_payload().buffer_ptr;
            buffer_offsets[current_active_attribute_location] = reinterpret_cast<VkDeviceSize>(vaa_props.pointer);
        }

        /* TODO: Use a non-zero start binding index whenever possible */
        in_cmd_buffer_ptr->record_bind_vertex_buffers(0, /* in_start_binding */
                                                      program_post_link_data_ptr->max_active_attribute_location + 1, /* in_binding_count */
                                                      buffer_ptrs,
                                                      buffer_offsets);

        if (m_args.index_data_type != OpenGL::DrawCallIndexType::Unknown)
        {
            auto index_buffer_ptr = m_index_buffer_reference_ptr->get_payload().buffer_ptr;

            vkgl_assert(m_args.index_data_type == OpenGL::DrawCallIndexType::Unsigned_Int    ||
                        m_args.index_data_type == OpenGL::DrawCallIndexType::Unsigned_Short);

            in_cmd_buffer_ptr->record_bind_index_buffer(index_buffer_ptr,
                                                        m_args.index_buffer_offset,
                                                        (m_args.index_data_type == OpenGL::DrawCallIndexType::Unsigned_Int) ? Anvil::IndexType::UINT32
                                                                                                                            : Anvil::IndexType::UINT16);
        }
    }

    /* Issue the draw call */
    switch (m_type)
    {
        case DrawType::Indexed:
        {
            in_cmd_buffer_ptr->record_draw_indexed(m_args.count,
                                                   1,  /* in_instance_count */
                                                   0,  /* in_first_index    */
                                                   0,  /* in_vertex_offset  */
                                                   0); /* in_first_instance */

            break;
        }

        case DrawType::Regular:
        {
            in_cmd_buffer_ptr->record_draw(m_args.count,
                                           1, /* in_instance_count */
                                           m_args.first,
                                           0); /* in_first_instance */

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

end:
    ;
}

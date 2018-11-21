/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/shader_module.h"
#include "Anvil/include/misc/graphics_pipeline_create_info.h"
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/graphics_pipeline_manager.h"
#include "OpenGL/utils_enum.h"
#include "OpenGL/backend/vk_utils.h"
#include "OpenGL/backend/vk_gfx_pipeline_manager.h"
#include "OpenGL/backend/vk_spirv_manager.h"
#include "OpenGL/frontend/gl_vao_manager.h"


OpenGL::VKGFXPipelineManager::GFXPipelineProps::GLState::GLState()
    :is_blend_enabled                    (false),
     is_color_logic_op_enabled           (false),
     is_cull_face_enabled                (false),
     is_depth_clamp_enabled              (false),
     is_depth_test_enabled               (false),
     is_framebuffer_srgb_enabled         (false),
     is_line_smooth_enabled              (false),
     is_multisample_enabled              (false),
     is_polygon_offset_fill_enabled      (false),
     is_polygon_offset_line_enabled      (false),
     is_polygon_offset_point_enabled     (false),
     is_polygon_smooth_enabled           (false),
     is_primitive_restart_enabled        (false),
     is_program_point_size_enabled       (false),
     is_sample_alpha_to_coverage_enabled (false),
     is_sample_alpha_to_one_enabled      (false),
     is_sample_coverage_enabled          (false),
     is_sample_coverage_invert_enabled   (false),
     is_sample_mask_enabled              (false),
     is_scissor_test_enabled             (false),
     is_stencil_test_enabled             (false),
     is_texture_cube_map_seamless_enabled(false),

     primitive_restart_index             (false),

     depth_range                         {0.0f, 0.0f},
     user_clip_planes_enabled            (0),
     clamp_read_color                    (OpenGL::ClampReadColorMode::Unknown),
     provoking_vertex                    (OpenGL::ProvokingVertexConvention::Unknown),

     point_fade_threshold_size           (0.0f),
     point_size                          (0.0f),
     point_sprite_coord_origin           (OpenGL::PointSpriteCoordOrigin::Unknown),

     cull_face_mode                      (OpenGL::CullMode::Unknown),
     front_face                          (OpenGL::FrontFaceOrientation::Unknown),
     polygon_offset_factor               (0.0f),
     polygon_offset_units                (0.0f),

     sample_coverage_value               (0.0f),
     sample_mask                         (0),

     stencil_function_back               (OpenGL::StencilFunction::Unknown),
     stencil_function_front              (OpenGL::StencilFunction::Unknown),
     stencil_op_fail_back                (OpenGL::StencilOperation::Unknown),
     stencil_op_fail_front               (OpenGL::StencilOperation::Unknown),
     stencil_op_pass_depth_fail_back     (OpenGL::StencilOperation::Unknown),
     stencil_op_pass_depth_fail_front    (OpenGL::StencilOperation::Unknown),
     stencil_op_pass_depth_pass_back     (OpenGL::StencilOperation::Unknown),
     stencil_op_pass_depth_pass_front    (OpenGL::StencilOperation::Unknown),

     blend_equation_alpha                (OpenGL::BlendEquation::Unknown),
     blend_equation_rgb                  (OpenGL::BlendEquation::Unknown),
     blend_func_dst_alpha                (OpenGL::BlendFunction::Unknown),
     blend_func_dst_rgb                  (OpenGL::BlendFunction::Unknown),
     blend_func_src_alpha                (OpenGL::BlendFunction::Unknown),
     blend_func_src_rgb                  (OpenGL::BlendFunction::Unknown),
     depth_function                      (OpenGL::DepthFunction::Unknown),
     logic_op_mode                       (OpenGL::LogicOpMode::Unknown),

     color_writemask_for_draw_buffers    (0),
     depth_writemask                     (false),

     polygon_mode                        (OpenGL::PolygonMode::Unknown),

     program_reference_payload           (OpenGL::GLPayload(0, /* in_id */
                                                            OpenGL::TimeMarker(std::chrono::nanoseconds(0) ),
                                                            OpenGL::TimeMarker(std::chrono::nanoseconds(0) ) )),
     vao_reference_payload               (OpenGL::GLPayload(0, /* in_id */
                                                            OpenGL::TimeMarker(std::chrono::nanoseconds(0) ),
                                                            OpenGL::TimeMarker(std::chrono::nanoseconds(0) ) ))
{
    /* Stub */
}

OpenGL::VKGFXPipelineManager::GFXPipelineProps::GLState::GLState(const OpenGL::ContextState* in_context_state_ptr)
    :program_reference_payload(in_context_state_ptr->program_reference_ptr->get_payload() ),
     vao_reference_payload    (in_context_state_ptr->vao_reference_ptr->get_payload    () ),

     is_blend_enabled                    (in_context_state_ptr->is_blend_enabled),
     is_color_logic_op_enabled           (in_context_state_ptr->is_color_logic_op_enabled),
     is_cull_face_enabled                (in_context_state_ptr->is_cull_face_enabled),
     is_depth_clamp_enabled              (in_context_state_ptr->is_depth_clamp_enabled),
     is_depth_test_enabled               (in_context_state_ptr->is_depth_test_enabled),
     is_framebuffer_srgb_enabled         (in_context_state_ptr->is_framebuffer_srgb_enabled),
     is_line_smooth_enabled              (in_context_state_ptr->is_line_smooth_enabled),
     is_multisample_enabled              (in_context_state_ptr->is_multisample_enabled),
     is_polygon_offset_fill_enabled      (in_context_state_ptr->is_polygon_offset_fill_enabled),
     is_polygon_offset_line_enabled      (in_context_state_ptr->is_polygon_offset_line_enabled),
     is_polygon_offset_point_enabled     (in_context_state_ptr->is_polygon_offset_point_enabled),
     is_polygon_smooth_enabled           (in_context_state_ptr->is_polygon_smooth_enabled),
     is_primitive_restart_enabled        (in_context_state_ptr->is_primitive_restart_enabled),
     is_program_point_size_enabled       (in_context_state_ptr->is_program_point_size_enabled),
     is_sample_alpha_to_coverage_enabled (in_context_state_ptr->is_sample_alpha_to_coverage_enabled),
     is_sample_alpha_to_one_enabled      (in_context_state_ptr->is_sample_alpha_to_one_enabled),
     is_sample_coverage_enabled          (in_context_state_ptr->is_sample_coverage_enabled),
     is_sample_coverage_invert_enabled   (in_context_state_ptr->is_sample_coverage_invert_enabled),
     is_sample_mask_enabled              (in_context_state_ptr->is_sample_mask_enabled),
     is_scissor_test_enabled             (in_context_state_ptr->is_scissor_test_enabled),
     is_stencil_test_enabled             (in_context_state_ptr->is_stencil_test_enabled),
     is_texture_cube_map_seamless_enabled(in_context_state_ptr->is_texture_cube_map_seamless_enabled),

     primitive_restart_index             (in_context_state_ptr->primitive_restart_index),

     depth_range                         {in_context_state_ptr->depth_range[0], in_context_state_ptr->depth_range[1]},
     user_clip_planes_enabled            (in_context_state_ptr->user_clip_planes_enabled),

     clamp_read_color                    (in_context_state_ptr->clamp_read_color),
     provoking_vertex                    (in_context_state_ptr->provoking_vertex),

     point_fade_threshold_size           (in_context_state_ptr->point_fade_threshold_size),
     point_size                          (in_context_state_ptr->point_size),
     point_sprite_coord_origin           (in_context_state_ptr->point_sprite_coord_origin),

     cull_face_mode                      (in_context_state_ptr->cull_face_mode),
     front_face                          (in_context_state_ptr->front_face),
     polygon_offset_factor               (in_context_state_ptr->polygon_offset_factor),
     polygon_offset_units                (in_context_state_ptr->polygon_offset_units),

     sample_coverage_value               (in_context_state_ptr->sample_coverage_value),
     sample_mask                         (in_context_state_ptr->sample_mask),

     stencil_function_back               (in_context_state_ptr->stencil_function_back),
     stencil_function_front              (in_context_state_ptr->stencil_function_front),
     stencil_op_fail_back                (in_context_state_ptr->stencil_op_fail_back),
     stencil_op_fail_front               (in_context_state_ptr->stencil_op_fail_front),
     stencil_op_pass_depth_fail_back     (in_context_state_ptr->stencil_op_pass_depth_fail_back),
     stencil_op_pass_depth_fail_front    (in_context_state_ptr->stencil_op_pass_depth_fail_front),
     stencil_op_pass_depth_pass_back     (in_context_state_ptr->stencil_op_pass_depth_pass_back),
     stencil_op_pass_depth_pass_front    (in_context_state_ptr->stencil_op_pass_depth_pass_front),

     blend_equation_alpha                (in_context_state_ptr->blend_equation_alpha),
     blend_equation_rgb                  (in_context_state_ptr->blend_equation_rgb),
     blend_func_dst_alpha                (in_context_state_ptr->blend_func_dst_alpha),
     blend_func_dst_rgb                  (in_context_state_ptr->blend_func_dst_rgb),
     blend_func_src_alpha                (in_context_state_ptr->blend_func_src_alpha),
     blend_func_src_rgb                  (in_context_state_ptr->blend_func_src_rgb),
     depth_function                      (in_context_state_ptr->depth_function),
     logic_op_mode                       (in_context_state_ptr->logic_op_mode),

     color_writemask_for_draw_buffers    (in_context_state_ptr->color_writemask_for_draw_buffers),
     depth_writemask                     (in_context_state_ptr->depth_writemask),

     polygon_mode                        (in_context_state_ptr->polygon_mode)
{
    /* Stub */
}

Anvil::GraphicsPipelineCreateInfoUniquePtr OpenGL::VKGFXPipelineManager::GFXPipelineProps::create_create_info_ptr(const OpenGL::GLVAOManager*     in_vao_manager_ptr,
                                                                                                                  const OpenGL::VKSPIRVManager*   in_spirv_manager_ptr,
                                                                                                                  const Anvil::PrimitiveTopology& in_primitive_topology,
                                                                                                                  const Anvil::SubPassID&         in_subpass_id) const
{
    Anvil::GraphicsPipelineCreateInfoUniquePtr result_ptr;

    /* Spawn a create info instance for the pipeline */
    {
        const char*          fs_sm_entrypoint_name = nullptr;
        Anvil::ShaderModule* fs_sm_ptr             = nullptr;
        const char*          gs_sm_entrypoint_name = nullptr;
        Anvil::ShaderModule* gs_sm_ptr             = nullptr;
        SPIRVBlobID          spirv_blob_id         = UINT32_MAX;
        const char*          vs_sm_entrypoint_name = nullptr;
        Anvil::ShaderModule* vs_sm_ptr             = nullptr;

        if (!in_spirv_manager_ptr->get_spirv_blob_id_for_program_reference(gl_state.program_reference_payload.id,
                                                                           gl_state.program_reference_payload.time_marker,
                                                                          &spirv_blob_id) )
        {
            vkgl_assert_fail();

            goto end;
        }

        in_spirv_manager_ptr->get_shader_module_ptr(spirv_blob_id,
                                                    OpenGL::ShaderType::Fragment,
                                                   &fs_sm_ptr,
                                                   &fs_sm_entrypoint_name);
        in_spirv_manager_ptr->get_shader_module_ptr(spirv_blob_id,
                                                    OpenGL::ShaderType::Geometry,
                                                   &gs_sm_ptr,
                                                   &gs_sm_entrypoint_name);
        in_spirv_manager_ptr->get_shader_module_ptr(spirv_blob_id,
                                                    OpenGL::ShaderType::Vertex,
                                                   &vs_sm_ptr,
                                                   &vs_sm_entrypoint_name);

        vkgl_assert(fs_sm_ptr != nullptr &&
                    vs_sm_ptr != nullptr);

        result_ptr = Anvil::GraphicsPipelineCreateInfo::create(Anvil::PipelineCreateFlagBits::NONE,
                                                               rp_ptr,
                                                               in_subpass_id,
                                                               Anvil::ShaderModuleStageEntryPoint(fs_sm_entrypoint_name,
                                                                                                  fs_sm_ptr,
                                                                                                  Anvil::ShaderStage::FRAGMENT),
                                                               Anvil::ShaderModuleStageEntryPoint(gs_sm_entrypoint_name,
                                                                                                  gs_sm_ptr,
                                                                                                  Anvil::ShaderStage::GEOMETRY),
                                                               Anvil::ShaderModuleStageEntryPoint(), /* in_tess_control_shader_stage_entrypoint_info    */
                                                               Anvil::ShaderModuleStageEntryPoint(), /* in_tess_evaluation_shader_stage_entrypoint_info */
                                                               Anvil::ShaderModuleStageEntryPoint(vs_sm_entrypoint_name,
                                                                                                  vs_sm_ptr,
                                                                                                  Anvil::ShaderStage::VERTEX)
        );
    }

    if (result_ptr == nullptr)
    {
        vkgl_assert(result_ptr != nullptr);

        goto end;
    }

    /* Attach vertex attributes as per bound VAO state
     *
     * TODO: For disabled vertex attribute arrays, for which vertex shader-level bindings have been defined, we need to add dummy bindings!
     */
    {
        uint32_t                              n_bindings    = 0;
        const OpenGL::VertexArrayObjectState* vao_state_ptr = nullptr;

        if (!in_vao_manager_ptr->get_vao_state_ptr(gl_state.vao_reference_payload.id,
                                                  &gl_state.vao_reference_payload.time_marker,
                                                  &vao_state_ptr) )
        {
            vkgl_assert(vao_state_ptr != nullptr);

            goto end;
        }

        n_bindings = static_cast<uint32_t>(vao_state_ptr->vertex_attribute_arrays.size() );

        for (uint32_t n_binding = 0;
                      n_binding < n_bindings;
                    ++n_binding)
        {
            const auto& current_binding = vao_state_ptr->vertex_attribute_arrays.at(n_binding);

            result_ptr->add_vertex_attribute(n_binding,
                                             get_format_for_vaa(current_binding),
                                             static_cast<uint32_t>(reinterpret_cast<uint64_t>(current_binding.pointer) ),
                                             static_cast<uint32_t>(current_binding.stride),
                                             Anvil::VertexInputRate::VERTEX,
                                             n_binding); /* in_explicit_binding_index */
        }
    }

    /* TODO: Blending support */
    vkgl_assert(!gl_state.is_blend_enabled);

    /* Carry on with other general state */
    result_ptr->set_multisampling_properties(Anvil::SampleCountFlagBits::_1_BIT,
                                             1.0f,  /* in_min_sample_shading */
                                             gl_state.sample_mask);
    result_ptr->set_n_dynamic_scissor_boxes (1 /* in_n_dynamic_scissor_boxes */);
    result_ptr->set_n_dynamic_viewports     (1 /* in_n_dynamic_viewports     */);
    result_ptr->set_primitive_topology      (in_primitive_topology);
    result_ptr->set_rasterization_properties(OpenGL::VKUtils::get_anvil_polygon_mode_for_polygon_mode        (gl_state.polygon_mode),
                                             OpenGL::VKUtils::get_anvil_cull_mode_flags_for_cull_face_mode   (gl_state.cull_face_mode),
                                             OpenGL::VKUtils::get_anvil_front_face_for_front_face_orientation(gl_state.front_face),
                                             0.0f /* in_line_width - irrelevant: dynamic state */);

    result_ptr->set_stencil_test_properties(false, /* in_update_front_face_state */
                                            OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(gl_state.stencil_op_fail_back),
                                            OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(gl_state.stencil_op_pass_depth_pass_back),
                                            OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(gl_state.stencil_op_pass_depth_fail_back),
                                            OpenGL::VKUtils::get_anvil_compare_op_for_stencil_function (gl_state.stencil_function_back),
                                            0,    /* in_stencil_compare_mask - irrelevant: dynamic state */
                                            0,    /* in_stencil_write_mask   - irrelevant: dynamic state */
                                            0     /* in_stencil_reference    - irrelevant: dynamic state*/);
    result_ptr->set_stencil_test_properties(true, /* in_update_front_face_state                         */
                                            OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(gl_state.stencil_op_fail_front),
                                            OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(gl_state.stencil_op_pass_depth_pass_front),
                                            OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(gl_state.stencil_op_pass_depth_fail_front),
                                            OpenGL::VKUtils::get_anvil_compare_op_for_stencil_function (gl_state.stencil_function_front),
                                            0, /* in_stencil_compare_mask - irrelevant: dynamic state */
                                            0, /* in_stencil_write_mask   - irrelevant: dynamic state */
                                            0  /* in_stencil_reference    - irrelevant: dynamic state*/);

    result_ptr->toggle_alpha_to_coverage(gl_state.is_sample_alpha_to_coverage_enabled);
    result_ptr->toggle_alpha_to_one     (gl_state.is_sample_alpha_to_one_enabled);
    result_ptr->toggle_depth_bias       (false, /* in_should_enable              */
                                         0.0f,  /* in_depth_bias_constant_factor */
                                         0.0f,  /* in_depth_bias_clamp           */
                                         0.0f); /* in_depth_bias_factor          */
    result_ptr->toggle_depth_bounds_test(false, /* in_should_enable              */
                                         0.0f,  /* in_min_depth_bounds           */
                                         0.0f); /* in_max_depth_bounds           */
    result_ptr->toggle_depth_clamp      (gl_state.is_depth_clamp_enabled);
    result_ptr->toggle_depth_test       (gl_state.is_depth_test_enabled,
                                         OpenGL::VKUtils::get_anvil_compare_op_for_depth_function(gl_state.depth_function) );
    result_ptr->toggle_depth_writes     (gl_state.depth_writemask);
    result_ptr->toggle_dynamic_states   (true, /* in_should_enable */
                                         {Anvil::DynamicState::BLEND_CONSTANTS,
                                          Anvil::DynamicState::LINE_WIDTH,
                                          Anvil::DynamicState::SCISSOR,
                                          Anvil::DynamicState::STENCIL_COMPARE_MASK,
                                          Anvil::DynamicState::STENCIL_REFERENCE,
                                          Anvil::DynamicState::STENCIL_WRITE_MASK,
                                          Anvil::DynamicState::VIEWPORT});
    result_ptr->toggle_logic_op         (gl_state.logic_op_mode != OpenGL::LogicOpMode::Set,
                                         OpenGL::VKUtils::get_anvil_logic_op_for_logic_op_mode(gl_state.logic_op_mode) );
    result_ptr->toggle_primitive_restart(gl_state.is_primitive_restart_enabled);
    result_ptr->toggle_rasterizer_discard(false);
    result_ptr->toggle_sample_mask       (gl_state.sample_mask != UINT32_MAX);
    result_ptr->toggle_stencil_test      (gl_state.is_stencil_test_enabled);

end:
    return result_ptr;
}

Anvil::Format OpenGL::VKGFXPipelineManager::GFXPipelineProps::get_format_for_vaa(const OpenGL::VertexAttributeArrayState& in_vaa) const
{
    Anvil::Format result = Anvil::Format::UNKNOWN;

    /* TODO. Not a GL3.2 feature */
    vkgl_assert(!in_vaa.integer);

    switch (in_vaa.type)
    {
        case OpenGL::VertexAttributeArrayType::Byte:
        {
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            if (in_vaa.normalized)
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R8_SNORM
                       : (in_vaa.size == 2) ? Anvil::Format::R8G8_SNORM
                       : (in_vaa.size == 3) ? Anvil::Format::R8G8B8_SNORM
                                            : Anvil::Format::R8G8B8A8_SNORM;
            }
            else
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R8_SINT
                       : (in_vaa.size == 2) ? Anvil::Format::R8G8_SINT
                       : (in_vaa.size == 3) ? Anvil::Format::R8G8B8_SINT
                                            : Anvil::Format::R8G8B8A8_SINT;
            }

            break;
        }

        case OpenGL::VertexAttributeArrayType::Double:
        {
            vkgl_not_implemented();

            break;
        }

        case OpenGL::VertexAttributeArrayType::Float:
        {
            vkgl_assert(!in_vaa.normalized);
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            result = (in_vaa.size == 1) ? Anvil::Format::R32_SFLOAT
                   : (in_vaa.size == 2) ? Anvil::Format::R32G32_SFLOAT
                   : (in_vaa.size == 3) ? Anvil::Format::R32G32B32_SFLOAT
                                        : Anvil::Format::R32G32B32A32_SFLOAT;

            break;
        }

        case OpenGL::VertexAttributeArrayType::Int:
        {
            vkgl_assert(!in_vaa.normalized);
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            result = (in_vaa.size == 1) ? Anvil::Format::R32_SINT
                   : (in_vaa.size == 2) ? Anvil::Format::R32G32_SINT
                   : (in_vaa.size == 3) ? Anvil::Format::R32G32B32_SINT
                                        : Anvil::Format::R32G32B32A32_SINT;

            break;
        }

        case OpenGL::VertexAttributeArrayType::Short:
        {
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            if (in_vaa.normalized)
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R16_SNORM
                       : (in_vaa.size == 2) ? Anvil::Format::R16G16_SNORM
                       : (in_vaa.size == 3) ? Anvil::Format::R16G16B16_SNORM
                                            : Anvil::Format::R16G16B16A16_SNORM;
            }
            else
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R16_SINT
                       : (in_vaa.size == 2) ? Anvil::Format::R16G16_SINT
                       : (in_vaa.size == 3) ? Anvil::Format::R16G16B16_SINT
                                            : Anvil::Format::R16G16B16A16_SINT;
            }

            break;
        }

        case OpenGL::VertexAttributeArrayType::Unsigned_Byte:
        {
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            if (in_vaa.normalized)
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R8_UNORM
                       : (in_vaa.size == 2) ? Anvil::Format::R8G8_UNORM
                       : (in_vaa.size == 3) ? Anvil::Format::R8G8B8_UNORM
                                            : Anvil::Format::R8G8B8A8_UNORM;
            }
            else
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R8_UINT
                       : (in_vaa.size == 2) ? Anvil::Format::R8G8_UINT
                       : (in_vaa.size == 3) ? Anvil::Format::R8G8B8_UINT
                                            : Anvil::Format::R8G8B8A8_UINT;
            }

            break;
        }

        case OpenGL::VertexAttributeArrayType::Unsigned_Int:
        {
            vkgl_assert(!in_vaa.normalized);
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            result = (in_vaa.size == 1) ? Anvil::Format::R32_UINT
                   : (in_vaa.size == 2) ? Anvil::Format::R32G32_UINT
                   : (in_vaa.size == 3) ? Anvil::Format::R32G32B32_UINT
                                        : Anvil::Format::R32G32B32A32_UINT;

            break;
        }

        case OpenGL::VertexAttributeArrayType::Unsigned_Short:
        {
            vkgl_assert(in_vaa.size >= 1 && in_vaa.size <= 4);

            if (in_vaa.normalized)
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R16_UNORM
                       : (in_vaa.size == 2) ? Anvil::Format::R16G16_UNORM
                       : (in_vaa.size == 3) ? Anvil::Format::R16G16B16_UNORM
                                            : Anvil::Format::R16G16B16A16_UNORM;
            }
            else
            {
                result = (in_vaa.size == 1) ? Anvil::Format::R16_UINT
                       : (in_vaa.size == 2) ? Anvil::Format::R16G16_UINT
                       : (in_vaa.size == 3) ? Anvil::Format::R16G16B16_UINT
                                            : Anvil::Format::R16G16B16A16_UINT;
            }

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::VKGFXPipelineManager::GFXPipelineProps::GLStateHash OpenGL::VKGFXPipelineManager::GFXPipelineProps::GLState::get_hash() const
{
    uint64_t hash_contributions[6] = {0, 0, 0, 0, 0, 0};

    hash_contributions[0] = ((is_blend_enabled)                     ? (1 << 0)  : 0)        |
                            ((is_color_logic_op_enabled)            ? (1 << 1)  : 0)        |
                            ((is_cull_face_enabled)                 ? (1 << 2)  : 0)        |
                            ((is_depth_clamp_enabled)               ? (1 << 3)  : 0)        |
                            ((is_depth_test_enabled)                ? (1 << 4)  : 0)        |
                            ((is_framebuffer_srgb_enabled)          ? (1 << 5)  : 0)        |
                            ((is_line_smooth_enabled)               ? (1 << 6)  : 0)        |
                            ((is_multisample_enabled)               ? (1 << 7)  : 0)        |
                            ((is_polygon_offset_fill_enabled)       ? (1 << 8)  : 0)        |
                            ((is_polygon_offset_line_enabled)       ? (1 << 9)  : 0)        |
                            ((is_polygon_offset_point_enabled)      ? (1 << 10) : 0)        |
                            ((is_polygon_smooth_enabled)            ? (1 << 11) : 0)        |
                            ((is_primitive_restart_enabled)         ? (1 << 12) : 0)        |
                            ((is_program_point_size_enabled)        ? (1 << 13) : 0)        |
                            ((is_sample_alpha_to_coverage_enabled)  ? (1 << 14) : 0)        |
                            ((is_sample_alpha_to_one_enabled)       ? (1 << 15) : 0)        |
                            ((is_sample_coverage_enabled)           ? (1 << 16) : 0)        |
                            ((is_sample_coverage_invert_enabled)    ? (1 << 17) : 0)        |
                            ((is_sample_mask_enabled)               ? (1 << 18) : 0)        |
                            ((is_scissor_test_enabled)              ? (1 << 19) : 0)        |
                            ((is_stencil_test_enabled)              ? (1 << 20) : 0)        |
                            ((is_texture_cube_map_seamless_enabled) ? (1 << 21) : 0)        |
                            (static_cast<uint64_t>(color_writemask_for_draw_buffers) << 22);


    hash_contributions[1] = primitive_restart_index                                        ^
                            *reinterpret_cast<const uint64_t*>(&depth_range[0])            ^
                            *reinterpret_cast<const uint64_t*>(&depth_range[1])            ^
                            *reinterpret_cast<const uint32_t*>(&point_fade_threshold_size) ^
                            *reinterpret_cast<const uint32_t*>(&point_size)                ^
                            *reinterpret_cast<const uint32_t*>(&polygon_offset_factor)     ^
                            *reinterpret_cast<const uint32_t*>(&polygon_offset_units)      ^
                            *reinterpret_cast<const uint32_t*>(&sample_coverage_value)     ^
                            sample_mask;

    for (uint32_t n_user_clip_plane = 0;
                  n_user_clip_plane < static_cast<uint32_t>(user_clip_planes_enabled.size() );
                ++n_user_clip_plane)
    {
        hash_contributions[2] |= (user_clip_planes_enabled.at(n_user_clip_plane) ? (1 << (n_user_clip_plane) ) : 0);
    }

    hash_contributions[3] = (static_cast<uint64_t>(clamp_read_color))                       |
                            (static_cast<uint64_t>(provoking_vertex)                 << 1)  |
                            (static_cast<uint64_t>(point_sprite_coord_origin)        << 2)  |
                            (static_cast<uint64_t>(cull_face_mode)                   << 3)  |
                            (static_cast<uint64_t>(front_face)                       << 5)  |
                            (static_cast<uint64_t>(sample_mask)                      << 7)  |
                            (static_cast<uint64_t>(stencil_function_back)            << 39) |
                            (static_cast<uint64_t>(stencil_function_front)           << 42) |
                            (static_cast<uint64_t>(stencil_op_fail_back)             << 45) |
                            (static_cast<uint64_t>(stencil_op_fail_front)            << 48) |
                            (static_cast<uint64_t>(stencil_op_pass_depth_fail_back)  << 51) |
                            (static_cast<uint64_t>(stencil_op_pass_depth_fail_front) << 54) |
                            (static_cast<uint64_t>(stencil_op_pass_depth_pass_back)  << 57) |
                            (static_cast<uint64_t>(stencil_op_pass_depth_pass_front) << 60);

    hash_contributions[4] = (static_cast<uint64_t>(blend_equation_alpha))                   |
                            (static_cast<uint64_t>(blend_equation_rgb)               << 3)  |
                            (static_cast<uint64_t>(blend_func_dst_alpha)             << 7)  |
                            (static_cast<uint64_t>(blend_func_dst_rgb)               << 11) |
                            (static_cast<uint64_t>(blend_func_src_alpha)             << 15) |
                            (static_cast<uint64_t>(blend_func_src_rgb)               << 19) |
                            (static_cast<uint64_t>(depth_function)                   << 23) |
                            (static_cast<uint64_t>(logic_op_mode)                    << 27) |
                            ((depth_writemask) ? (1 << 31) : 0)                             |
                            (static_cast<uint64_t>(polygon_mode)                     << 32);

    hash_contributions[5] = static_cast<uint64_t>(program_reference_payload.id)                                               ^
                            static_cast<uint64_t>(program_reference_payload.object_creation_time.time_since_epoch().count() ) ^
                            static_cast<uint64_t>(program_reference_payload.time_marker.time_since_epoch         ().count() );

    return hash_contributions[0] ^
           hash_contributions[1] ^
           hash_contributions[2] ^
           hash_contributions[3] ^
           hash_contributions[4] ^
           hash_contributions[5];
}

OpenGL::VKGFXPipelineManager::GFXPipelineProps::GFXPipelineProps(const Anvil::BaseDevice*    in_device_ptr,
                                                                 const OpenGL::ContextState* in_context_state_ptr,
                                                                 const Anvil::RenderPass*    in_rp_ptr)
    :device_ptr(in_device_ptr),
     gl_state  (in_context_state_ptr),
     rp_ptr    (in_rp_ptr)
{
    /* Stub */
}

OpenGL::VKGFXPipelineManager::GFXPipelineProps::~GFXPipelineProps()
{
    for (const auto& current_pipeline_data : subpass_id_to_pipeline_data_map)
    {
        for (const auto& current_pipeline_item : current_pipeline_data.second)
        {
            if (!device_ptr->get_graphics_pipeline_manager()->delete_pipeline(current_pipeline_item.pipeline_id) )
            {
                vkgl_assert_fail();
            }
        }
    }
}

Anvil::PipelineID OpenGL::VKGFXPipelineManager::GFXPipelineProps::get_pipeline_id(const Anvil::PrimitiveTopology&       in_primitive_topology,
                                                                                  const Anvil::SubPassID&               in_subpass_id,
                                                                                  const OpenGL::IBackend*               in_backend_ptr,
                                                                                  const OpenGL::IContextObjectManagers* in_frontend_ptr)
{
    Anvil::PipelineID pipeline_id  = UINT32_MAX;

    for (uint32_t n_iteration = 0;
                  n_iteration < 2 && (pipeline_id == UINT32_MAX); /* RO access, RW access */
                ++n_iteration)
    {
        if (n_iteration == 0)
        {
            rw_mutex.lock_shared();
        }
        else
        {
            rw_mutex.lock_unique();
        }
        {
            auto map_iterator = subpass_id_to_pipeline_data_map.find(in_subpass_id);

            if (map_iterator != subpass_id_to_pipeline_data_map.end() )
            {
                auto vec_iterator = std::find_if(map_iterator->second.begin(),
                                                 map_iterator->second.end  (),
                                                 [=](const PipelineData& in_pipeline_data)
                                                 {
                                                     bool result = (in_pipeline_data.primitive_topology == in_primitive_topology);

                                                     return result;
                                                 });

                if (vec_iterator != map_iterator->second.end() )
                {
                    pipeline_id = vec_iterator->pipeline_id;

                    vkgl_assert(pipeline_id != UINT32_MAX);
                }
            }

            if (pipeline_id == UINT32_MAX &&
                n_iteration == 1)
            {
                auto device_ptr                   = in_backend_ptr->get_device_ptr();
                auto gfx_pipeline_create_info_ptr = create_create_info_ptr        (in_frontend_ptr->get_vao_manager_ptr (),
                                                                                   in_backend_ptr->get_spirv_manager_ptr(),
                                                                                   in_primitive_topology,
                                                                                   in_subpass_id);

                vkgl_assert(gfx_pipeline_create_info_ptr != nullptr);

                if (!device_ptr->get_graphics_pipeline_manager()->add_pipeline(std::move(gfx_pipeline_create_info_ptr),
                                                                              &pipeline_id) )
                {
                    vkgl_assert_fail();
                }

                vkgl_assert(pipeline_id != UINT32_MAX);

                subpass_id_to_pipeline_data_map[in_subpass_id].push_back(
                    PipelineData(pipeline_id,
                                 in_primitive_topology)
                );
            }
        }
        if (n_iteration == 0)
        {
            rw_mutex.unlock_shared();
        }
        else
        {
            rw_mutex.unlock_unique();
        }
    }

    vkgl_assert(pipeline_id != UINT32_MAX);
    return pipeline_id;
}

OpenGL::VKGFXPipelineManager::VKGFXPipelineManager(IBackend* in_backend_ptr)
    :m_backend_ptr(in_backend_ptr)
{
    /* Stub */
}

OpenGL::VKGFXPipelineManager::~VKGFXPipelineManager()
{
    /* Stub */
}

OpenGL::VKGFXPipelineManagerUniquePtr OpenGL::VKGFXPipelineManager::create(IBackend* in_backend_ptr)
{
    OpenGL::VKGFXPipelineManagerUniquePtr result_ptr;

    result_ptr.reset(new VKGFXPipelineManager(in_backend_ptr) );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

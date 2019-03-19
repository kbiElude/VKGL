/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "OpenGL/frontend/gl_framebuffer_manager.h"
#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/gl_program_manager.h"
#include "OpenGL/frontend/gl_renderbuffer_manager.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/gl_vao_manager.h"
#include "OpenGL/types.h"

static const OpenGL::BufferTarget g_indexed_buffer_targets[] =
{
    OpenGL::BufferTarget::Transform_Feedback_Buffer,
    OpenGL::BufferTarget::Uniform_Buffer,
};

static const OpenGL::BufferTarget g_nonindexed_buffer_targets[] =
{
    OpenGL::BufferTarget::Array_Buffer,
    OpenGL::BufferTarget::Copy_Read_Buffer,
    OpenGL::BufferTarget::Copy_Write_Buffer,
    // NO. This is VAO state. OpenGL::BufferTarget::Element_Array_Buffer,
    OpenGL::BufferTarget::Pixel_Pack_Buffer,
    OpenGL::BufferTarget::Pixel_Unpack_Buffer,
    OpenGL::BufferTarget::Texture_Buffer,
    OpenGL::BufferTarget::Transform_Feedback_Buffer,
    OpenGL::BufferTarget::Uniform_Buffer,
};

OpenGL::BufferState::BufferState()
{
    access           = OpenGL::BufferAccess::Read_Write;
    map_pointer      = nullptr;
    map_size         = 0;
    map_start_offset = 0;
    mapped           = false;
    size             = 0;
    usage            = OpenGL::BufferUsage::Static_Draw;
}

OpenGL::ContextState::ContextState(IContextObjectManagers* in_frontend_object_managers_ptr,
                                   const IGLLimits*        in_limits_ptr,
                                   const int32_t*          in_viewport_ivec4_ptr,
                                   const int32_t*          in_scissor_box_ivec4_ptr)
    :texture_image_units     (in_limits_ptr->get_max_texture_image_units() ),
     user_clip_planes_enabled(in_limits_ptr->get_max_clip_distances     (), false)
{
    constexpr uint32_t n_max_stencil_bits = 8; /* todo: extract this info from vk backend */

    vkgl_assert(in_limits_ptr->get_max_draw_buffers() <= 8);

    is_primitive_restart_enabled = false;
    primitive_restart_index      = 0;

    memcpy(viewport,
           in_viewport_ivec4_ptr,
           sizeof(int32_t) * 4);

    depth_range[0]         = 0.0f;
    depth_range[1]         = 1.0f;
    is_depth_clamp_enabled = false;

    clamp_read_color = OpenGL::ClampReadColorMode::Fixed_Only;
    provoking_vertex = OpenGL::ProvokingVertexConvention::Last;

    is_line_smooth_enabled    = false;
    line_width                = 1.0f;
    point_fade_threshold_size = 1.0f;
    point_size                = 1.0f;
    point_sprite_coord_origin = OpenGL::PointSpriteCoordOrigin::Upper_Left;

    cull_face_mode                  = OpenGL::CullMode::Back;
    front_face                      = OpenGL::FrontFaceOrientation::Counter_Clockwise;
    is_cull_face_enabled            = false;
    is_polygon_offset_fill_enabled  = false;
    is_polygon_offset_line_enabled  = false;
    is_polygon_offset_point_enabled = false;
    is_polygon_smooth_enabled       = false;
    polygon_offset_factor           = 0;
    polygon_offset_units            = 0;

    vkgl_assert(in_limits_ptr->get_max_samples() <= 32);

    is_multisample_enabled              = true;
    is_sample_alpha_to_coverage_enabled = false;
    is_sample_alpha_to_one_enabled      = false;
    is_sample_coverage_enabled          = false;
    is_sample_coverage_invert_enabled   = false;
    is_sample_mask_enabled              = false;
    sample_coverage_value               = 1.0f;
    sample_mask                         = (~0) & ((1 << in_limits_ptr->get_max_samples() ) - 1);

    active_texture_unit = 0;

    memcpy(scissor_box,
           in_scissor_box_ivec4_ptr,
           sizeof(int32_t) * 4);

    is_scissor_test_enabled          = false;
    is_stencil_test_enabled          = false;
    stencil_function_back            = OpenGL::StencilFunction::Always;
    stencil_function_front           = OpenGL::StencilFunction::Always;
    stencil_op_fail_back             = OpenGL::StencilOperation::Keep;
    stencil_op_fail_front            = OpenGL::StencilOperation::Keep;
    stencil_op_pass_depth_fail_back  = OpenGL::StencilOperation::Keep;
    stencil_op_pass_depth_fail_front = OpenGL::StencilOperation::Keep;
    stencil_op_pass_depth_pass_back  = OpenGL::StencilOperation::Keep;
    stencil_op_pass_depth_pass_front = OpenGL::StencilOperation::Keep;
    stencil_reference_value_back     = 0;
    stencil_reference_value_front    = 0;
    stencil_value_mask_back          = (1 << n_max_stencil_bits) - 1;
    stencil_value_mask_front         = (1 << n_max_stencil_bits) - 1;

    blend_color[0]              = 0;
    blend_color[1]              = 0;
    blend_color[2]              = 0;
    blend_color[3]              = 0;
    blend_equation_alpha        = OpenGL::BlendEquation::Function_Add;
    blend_equation_rgb          = OpenGL::BlendEquation::Function_Add;
    blend_func_dst_alpha        = OpenGL::BlendFunction::Zero;
    blend_func_dst_rgb          = OpenGL::BlendFunction::Zero;
    blend_func_src_alpha        = OpenGL::BlendFunction::One;
    blend_func_src_rgb          = OpenGL::BlendFunction::One;
    depth_function              = OpenGL::DepthFunction::Less;
    is_blend_enabled            = false;
    is_color_logic_op_enabled   = false;
    is_depth_test_enabled       = false;
    is_dither_enabled           = true;
    is_framebuffer_srgb_enabled = false;
    logic_op_mode               = OpenGL::LogicOpMode::Copy;

    color_clear_value[0]             = 0;
    color_clear_value[1]             = 0;
    color_clear_value[2]             = 0;
    color_clear_value[3]             = 0;
    color_writemask_for_draw_buffers = ~0;
    depth_clear_value                = 1.0f;
    depth_writemask                  = true;
    stencil_clear_value              = 0;
    stencil_writemask_back           = ~0;
    stencil_writemask_front          = ~0;

    pack_alignment      = 4;
    pack_image_height   = 0;
    pack_lsb_first      = false;
    pack_row_length     = 0;
    pack_skip_images    = 0;
    pack_skip_pixels    = 0;
    pack_skip_rows      = 0;
    pack_swap_bytes     = false;
    unpack_alignment    = 4;
    unpack_image_height = 0;
    unpack_lsb_first    = false;
    unpack_row_length   = 0;
    unpack_skip_images  = 0;
    unpack_skip_pixels  = 0;
    unpack_skip_rows    = 0;
    unpack_swap_bytes   = false;

    hint_fragment_shader_derivative = OpenGL::HintMode::Dont_Care;
    hint_line_smooth                = OpenGL::HintMode::Dont_Care;
    hint_polygon_smooth             = OpenGL::HintMode::Dont_Care;
    hint_texture_compression        = OpenGL::HintMode::Dont_Care;

    is_texture_cube_map_seamless_enabled = false;

    active_any_samples_passed_query_id                    = 0;
    active_primitives_generated_query_id                  = 0;
    active_samples_passed_query_id                        = 0;
    active_time_elapsed_query_id                          = 0;
    active_timestamp_query_id                             = 0;
    active_transform_feedback_primitives_written_query_id = 0;

    is_program_point_size_enabled = false;
    polygon_mode                  = PolygonMode::Fill;

    for (const auto& current_indexed_target : g_indexed_buffer_targets)
    {
        const auto n_max_bindings = (current_indexed_target == OpenGL::BufferTarget::Transform_Feedback_Buffer) ? in_limits_ptr->get_max_transform_feedback_separate_attribs()
                                                                                                                : in_limits_ptr->get_max_uniform_buffer_bindings            ();

        for (uint32_t n_binding = 0;
                      n_binding < n_max_bindings;
                    ++n_binding)
        {
            indexed_buffer_proxy_binding_ptrs[IndexedBufferTarget(current_indexed_target, n_binding)] = IndexedBufferBinding(in_frontend_object_managers_ptr->get_buffer_manager_ptr()->get_default_object_reference(),
                                                                                                                             0,  /* in_start_offset */
                                                                                                                             0); /* in_size         */
        }
    }

    for (const auto& current_nonindexed_target : g_nonindexed_buffer_targets)
    {
        nonindexed_buffer_proxy_binding_ptrs[current_nonindexed_target] = in_frontend_object_managers_ptr->get_buffer_manager_ptr()->get_default_object_reference();
    }

    /* Set up default bindings */
    draw_framebuffer_proxy_reference_ptr = in_frontend_object_managers_ptr->get_framebuffer_manager_ptr ()->get_default_object_reference();
    read_framebuffer_proxy_reference_ptr = in_frontend_object_managers_ptr->get_framebuffer_manager_ptr ()->get_default_object_reference();
    renderbuffer_proxy_reference_ptr     = in_frontend_object_managers_ptr->get_renderbuffer_manager_ptr()->get_default_object_reference();
    vao_proxy_reference_ptr              = in_frontend_object_managers_ptr->get_vao_manager_ptr         ()->get_default_object_reference();
}

OpenGL::ContextState::ContextState(const OpenGL::ContextState&   in_context_state,
                                   const bool&                   in_convert_from_proxy_to_nonproxy,
                                   const IContextObjectManagers* in_frontend_object_managers_ptr)
{
    *this = in_context_state;

    if (in_convert_from_proxy_to_nonproxy)
    {
        auto buffer_frontend_manager_ptr  = in_frontend_object_managers_ptr->get_buffer_manager_ptr      ();
        auto fb_frontend_manager_ptr      = in_frontend_object_managers_ptr->get_framebuffer_manager_ptr ();
        auto program_frontend_manager_ptr = in_frontend_object_managers_ptr->get_program_manager_ptr     ();
        auto rb_frontend_manager_ptr      = in_frontend_object_managers_ptr->get_renderbuffer_manager_ptr();
        auto vao_frontend_manager_ptr     = in_frontend_object_managers_ptr->get_vao_manager_ptr         ();

        if (draw_framebuffer_proxy_reference_ptr != nullptr)
        {
            draw_framebuffer_proxy_reference_ptr = fb_frontend_manager_ptr->acquire_current_latest_snapshot_reference(draw_framebuffer_proxy_reference_ptr->get_payload().id);
        }

        if (read_framebuffer_proxy_reference_ptr != nullptr)
        {
            read_framebuffer_proxy_reference_ptr = fb_frontend_manager_ptr->acquire_current_latest_snapshot_reference(read_framebuffer_proxy_reference_ptr->get_payload().id);
        }

        if (renderbuffer_proxy_reference_ptr != nullptr)
        {
            renderbuffer_proxy_reference_ptr = rb_frontend_manager_ptr->acquire_current_latest_snapshot_reference(renderbuffer_proxy_reference_ptr->get_payload().id);
        }

        if (program_proxy_reference_ptr != nullptr)
        {
            program_proxy_reference_ptr = program_frontend_manager_ptr->acquire_current_latest_snapshot_reference(program_proxy_reference_ptr->get_payload().id);
        }

        if (renderbuffer_proxy_reference_ptr != nullptr)
        {
            renderbuffer_proxy_reference_ptr = rb_frontend_manager_ptr->acquire_current_latest_snapshot_reference(renderbuffer_proxy_reference_ptr->get_payload().id);
        }

        if (vao_proxy_reference_ptr != nullptr)
        {
            vao_proxy_reference_ptr = vao_frontend_manager_ptr->acquire_current_latest_snapshot_reference(vao_proxy_reference_ptr->get_payload().id);
        }

        for (auto& current_indexed_proxy_binding_ptr : indexed_buffer_proxy_binding_ptrs)
        {
            if (current_indexed_proxy_binding_ptr.second.reference_ptr != nullptr)
            {
                current_indexed_proxy_binding_ptr.second.reference_ptr = buffer_frontend_manager_ptr->acquire_current_latest_snapshot_reference(current_indexed_proxy_binding_ptr.second.reference_ptr->get_payload().id);
            }
        }

        for (auto& current_nonindexed_proxy_binding_ptr : nonindexed_buffer_proxy_binding_ptrs)
        {
            if (current_nonindexed_proxy_binding_ptr.second != nullptr)
            {
                current_nonindexed_proxy_binding_ptr.second = buffer_frontend_manager_ptr->acquire_current_latest_snapshot_reference(current_nonindexed_proxy_binding_ptr.second->get_payload().id);
            }
        }
    }
}

OpenGL::ContextState::~ContextState()
{
    draw_framebuffer_proxy_reference_ptr.reset();
    read_framebuffer_proxy_reference_ptr.reset();
    renderbuffer_proxy_reference_ptr.reset    ();
    program_proxy_reference_ptr.reset         ();
    renderbuffer_proxy_reference_ptr.reset    ();
    vao_proxy_reference_ptr.reset             ();

    indexed_buffer_proxy_binding_ptrs.clear   ();
    nonindexed_buffer_proxy_binding_ptrs.clear();
    texture_unit_to_state_ptr_map.clear ();
}

OpenGL::ContextState& OpenGL::ContextState::operator=(const OpenGL::ContextState& in_context_state)
{
    /* GL references need extra care.. */
    draw_framebuffer_proxy_reference_ptr = (in_context_state.draw_framebuffer_proxy_reference_ptr != nullptr) ? in_context_state.draw_framebuffer_proxy_reference_ptr->clone() : nullptr;
    read_framebuffer_proxy_reference_ptr = (in_context_state.read_framebuffer_proxy_reference_ptr != nullptr) ? in_context_state.read_framebuffer_proxy_reference_ptr->clone() : nullptr;
    renderbuffer_proxy_reference_ptr     = (in_context_state.renderbuffer_proxy_reference_ptr     != nullptr) ? in_context_state.renderbuffer_proxy_reference_ptr->clone    () : nullptr;
    program_proxy_reference_ptr          = (in_context_state.program_proxy_reference_ptr          != nullptr) ? in_context_state.program_proxy_reference_ptr->clone         () : nullptr;
    renderbuffer_proxy_reference_ptr     = (in_context_state.renderbuffer_proxy_reference_ptr     != nullptr) ? in_context_state.renderbuffer_proxy_reference_ptr->clone    () : nullptr;
    vao_proxy_reference_ptr              = (in_context_state.vao_proxy_reference_ptr              != nullptr) ? in_context_state.vao_proxy_reference_ptr->clone             () : nullptr;

    for (const auto& current_nonindexed_buffer_binding : in_context_state.nonindexed_buffer_proxy_binding_ptrs)
    {
        nonindexed_buffer_proxy_binding_ptrs[current_nonindexed_buffer_binding.first] = (current_nonindexed_buffer_binding.second != nullptr) ? current_nonindexed_buffer_binding.second->clone()
                                                                                                                                              : nullptr;
    }

    for (const auto& current_texture_unit_to_state_ptr_map_item : texture_unit_to_state_ptr_map)
    {
        texture_unit_to_state_ptr_map[current_texture_unit_to_state_ptr_map_item.first].reset(
            new OpenGL::TextureUnitState(*current_texture_unit_to_state_ptr_map_item.second)
        );
    }

    /* Arrays.. */
    memcpy(blend_color,
           in_context_state.blend_color,
           sizeof(blend_color) );
    memcpy(color_clear_value,
           in_context_state.color_clear_value,
           sizeof(color_clear_value) );
    memcpy(depth_range,
           in_context_state.depth_range,
           sizeof(depth_range) );
    memcpy(scissor_box,
           in_context_state.scissor_box,
           sizeof(scissor_box) );
    memcpy(viewport,
           in_context_state.viewport,
           sizeof(viewport) );

    /* Follow with trivial copy ops.. */
    indexed_buffer_proxy_binding_ptrs = in_context_state.indexed_buffer_proxy_binding_ptrs;

    is_primitive_restart_enabled = in_context_state.is_primitive_restart_enabled;
    primitive_restart_index      = in_context_state.primitive_restart_index;

    is_depth_clamp_enabled   = in_context_state.is_depth_clamp_enabled;
    user_clip_planes_enabled = in_context_state.user_clip_planes_enabled;

    clamp_read_color = in_context_state.clamp_read_color;
    provoking_vertex = in_context_state.provoking_vertex;

    is_line_smooth_enabled    = in_context_state.is_line_smooth_enabled;
    line_width                = in_context_state.line_width;
    point_fade_threshold_size = in_context_state.point_fade_threshold_size;
    point_size                = in_context_state.point_size;
    point_sprite_coord_origin = in_context_state.point_sprite_coord_origin;

    cull_face_mode                  = in_context_state.cull_face_mode;
    front_face                      = in_context_state.front_face;
    is_cull_face_enabled            = in_context_state.is_cull_face_enabled;
    is_polygon_offset_fill_enabled  = in_context_state.is_polygon_offset_fill_enabled;
    is_polygon_offset_line_enabled  = in_context_state.is_polygon_offset_line_enabled;
    is_polygon_offset_point_enabled = in_context_state.is_polygon_offset_point_enabled;
    is_polygon_smooth_enabled       = in_context_state.is_polygon_smooth_enabled;
    polygon_offset_factor           = in_context_state.polygon_offset_factor;
    polygon_offset_units            = in_context_state.polygon_offset_units;

    is_multisample_enabled              = in_context_state.is_multisample_enabled;
    is_sample_alpha_to_coverage_enabled = in_context_state.is_sample_alpha_to_coverage_enabled;
    is_sample_alpha_to_one_enabled      = in_context_state.is_sample_alpha_to_one_enabled;
    is_sample_coverage_enabled          = in_context_state.is_sample_coverage_enabled;
    is_sample_coverage_invert_enabled   = in_context_state.is_sample_coverage_invert_enabled;
    is_sample_mask_enabled              = in_context_state.is_sample_mask_enabled;
    sample_coverage_value               = in_context_state.sample_coverage_value;
    sample_mask                         = in_context_state.sample_mask;

    active_texture_unit = in_context_state.active_texture_unit;
    texture_image_units = in_context_state.texture_image_units;

    is_scissor_test_enabled          = in_context_state.is_scissor_test_enabled;
    is_stencil_test_enabled          = in_context_state.is_stencil_test_enabled;
    stencil_function_back            = in_context_state.stencil_function_back;
    stencil_function_front           = in_context_state.stencil_function_front;
    stencil_op_fail_back             = in_context_state.stencil_op_fail_back;
    stencil_op_fail_front            = in_context_state.stencil_op_fail_front;
    stencil_op_pass_depth_fail_back  = in_context_state.stencil_op_pass_depth_fail_back;
    stencil_op_pass_depth_fail_front = in_context_state.stencil_op_pass_depth_fail_front;
    stencil_op_pass_depth_pass_back  = in_context_state.stencil_op_pass_depth_pass_back;
    stencil_op_pass_depth_pass_front = in_context_state.stencil_op_pass_depth_pass_front;
    stencil_reference_value_back     = in_context_state.stencil_reference_value_back;
    stencil_reference_value_front    = in_context_state.stencil_reference_value_front;
    stencil_value_mask_back          = in_context_state.stencil_value_mask_back;
    stencil_value_mask_front         = in_context_state.stencil_value_mask_front;

    blend_equation_alpha        = in_context_state.blend_equation_alpha;
    blend_equation_rgb          = in_context_state.blend_equation_rgb;
    blend_func_dst_alpha        = in_context_state.blend_func_dst_alpha;
    blend_func_dst_rgb          = in_context_state.blend_func_dst_rgb;
    blend_func_src_alpha        = in_context_state.blend_func_src_alpha;
    blend_func_src_rgb          = in_context_state.blend_func_src_rgb;
    depth_function              = in_context_state.depth_function;
    is_blend_enabled            = in_context_state.is_blend_enabled;
    is_color_logic_op_enabled   = in_context_state.is_color_logic_op_enabled;
    is_depth_test_enabled       = in_context_state.is_depth_test_enabled;
    is_dither_enabled           = in_context_state.is_dither_enabled;
    is_framebuffer_srgb_enabled = in_context_state.is_framebuffer_srgb_enabled;
    logic_op_mode               = in_context_state.logic_op_mode;

    color_writemask_for_draw_buffers = in_context_state.color_writemask_for_draw_buffers;
    depth_clear_value                = in_context_state.depth_clear_value;
    depth_writemask                  = in_context_state.depth_writemask;
    stencil_clear_value              = in_context_state.stencil_clear_value;
    stencil_writemask_back           = in_context_state.stencil_writemask_back;
    stencil_writemask_front          = in_context_state.stencil_writemask_front;

    pack_alignment      = in_context_state.pack_alignment;
    pack_image_height   = in_context_state.pack_image_height;
    pack_lsb_first      = in_context_state.pack_lsb_first;
    pack_row_length     = in_context_state.pack_row_length;
    pack_skip_images    = in_context_state.pack_skip_images;
    pack_skip_pixels    = in_context_state.pack_skip_pixels;
    pack_skip_rows      = in_context_state.pack_skip_rows;
    pack_swap_bytes     = in_context_state.pack_swap_bytes;
    unpack_alignment    = in_context_state.unpack_alignment;
    unpack_image_height = in_context_state.unpack_image_height;
    unpack_lsb_first    = in_context_state.unpack_lsb_first;
    unpack_row_length   = in_context_state.unpack_row_length;
    unpack_skip_images  = in_context_state.unpack_skip_images;
    unpack_skip_pixels  = in_context_state.unpack_skip_pixels;
    unpack_skip_rows    = in_context_state.unpack_skip_rows;
    unpack_swap_bytes   = in_context_state.unpack_swap_bytes;

    hint_fragment_shader_derivative = in_context_state.hint_fragment_shader_derivative;
    hint_line_smooth                = in_context_state.hint_line_smooth;
    hint_polygon_smooth             = in_context_state.hint_polygon_smooth;
    hint_texture_compression        = in_context_state.hint_texture_compression;

    is_texture_cube_map_seamless_enabled = in_context_state.is_texture_cube_map_seamless_enabled;

    active_any_samples_passed_query_id                    = in_context_state.active_any_samples_passed_query_id;
    active_primitives_generated_query_id                  = in_context_state.active_primitives_generated_query_id;
    active_samples_passed_query_id                        = in_context_state.active_samples_passed_query_id;
    active_time_elapsed_query_id                          = in_context_state.active_time_elapsed_query_id;
    active_timestamp_query_id                             = in_context_state.active_timestamp_query_id;
    active_transform_feedback_primitives_written_query_id = in_context_state.active_transform_feedback_primitives_written_query_id;

    is_program_point_size_enabled = in_context_state.is_program_point_size_enabled;
    polygon_mode                  = in_context_state.polygon_mode;

    return *this;
}

OpenGL::DispatchTable::DispatchTable()
{
    memset(this,
           0,
           sizeof(*this) );
}

OpenGL::FramebufferAttachmentPointState::FramebufferAttachmentPointState()
{
    component_type           = OpenGL::FramebufferAttachmentComponentType::None;
    layered                  = false;
    size_alpha               = 0;
    size_blue                = 0;
    size_depth               = 0;
    size_green               = 0;
    size_red                 = 0;
    size_stencil             = 0;
    texture_cube_map_face    = OpenGL::TextureCubeMapFace::None;
    texture_layer            = 0;
    texture_level            = 0;
    type                     = OpenGL::FramebufferAttachmentObjectType::None;
    uses_srgb_color_encoding = false;
}

OpenGL::FramebufferState::FramebufferState()
{
    is_doublebuffer  = false;
    is_stereo        = false;
    n_sample_buffers = 0;
    n_samples        = 0;
    read_buffer      = OpenGL::ReadBuffer::Unknown;
}

OpenGL::FramebufferState::FramebufferState(const uint32_t& in_n_color_attachments)
    :color_attachments           (in_n_color_attachments),
     draw_buffer_per_color_output(in_n_color_attachments, OpenGL::DrawBuffer::None)
{
    is_doublebuffer  = false;
    is_stereo        = false;
    n_sample_buffers = 0;
    n_samples        = 1;
    read_buffer      = OpenGL::ReadBuffer::None;
}

OpenGL::FramebufferState& OpenGL::FramebufferState::operator=(const OpenGL::FramebufferState& in_state)
{
    color_attachments            = in_state.color_attachments;
    depth_attachment             = in_state.depth_attachment;
    draw_buffer_per_color_output = in_state.draw_buffer_per_color_output;
    is_doublebuffer              = in_state.is_doublebuffer;
    is_stereo                    = in_state.is_stereo;
    n_samples                    = in_state.n_samples;
    n_sample_buffers             = in_state.n_sample_buffers;
    read_buffer                  = in_state.read_buffer;
    sample_position              = in_state.sample_position;
    stencil_attachment           = in_state.stencil_attachment;

    return *this;
}

OpenGL::FramebufferAttachmentPointState::FramebufferAttachmentPointState(const OpenGL::FramebufferAttachmentPointState& in_state)
{
    *this = in_state;
}

OpenGL::FramebufferAttachmentPointState& OpenGL::FramebufferAttachmentPointState::operator=(const OpenGL::FramebufferAttachmentPointState& in_state)
{
    component_type           = in_state.component_type;
    layered                  = in_state.layered;
    size_alpha               = in_state.size_alpha;
    size_blue                = in_state.size_blue;
    size_depth               = in_state.size_depth;
    size_green               = in_state.size_green;
    size_red                 = in_state.size_red;
    size_stencil             = in_state.size_stencil;
    texture_cube_map_face    = in_state.texture_cube_map_face;
    texture_layer            = in_state.texture_layer;
    texture_level            = in_state.texture_level;
    type                     = in_state.type;
    uses_srgb_color_encoding = in_state.uses_srgb_color_encoding;

    renderbuffer_reference_ptr = (in_state.renderbuffer_reference_ptr != nullptr) ? in_state.renderbuffer_reference_ptr->clone() : nullptr;
    texture_reference_ptr      = (in_state.texture_reference_ptr      != nullptr) ? in_state.texture_reference_ptr->clone     () : nullptr;

    return *this;
}

OpenGL::GLContextStatePayload::GLContextStatePayload(const OpenGL::TimeMarker& in_time_marker)
   :time_marker(in_time_marker)
{
    /* Stub */
}

OpenGL::IndexedBufferBinding::IndexedBufferBinding(const OpenGL::IndexedBufferBinding& in_binding)
{
    *this = in_binding;
}

OpenGL::IndexedBufferBinding& OpenGL::IndexedBufferBinding::operator=(const OpenGL::IndexedBufferBinding& in_binding)
{
    reference_ptr = (in_binding.reference_ptr != nullptr) ? in_binding.reference_ptr->clone()
                                                          : nullptr;
    size          = in_binding.size;
    start_offset  = in_binding.start_offset;

    return *this;
}

OpenGL::RangedBufferBinding::RangedBufferBinding()
{
    buffer_id    = 0;
    size         = 0;
    start_offset = 0;
}

OpenGL::RenderbufferState::RenderbufferState()
{
    height          = 0;
    internal_format = OpenGL::InternalFormat::RGBA;
    samples         = 0;
    size_alpha      = 0;
    size_blue       = 0;
    size_depth      = 0;
    size_green      = 0;
    size_red        = 0;
    size_stencil    = 0;
    width           = 0;
}

OpenGL::SamplePosition::SamplePosition()
{
    x = FLT_MAX;
    y = FLT_MAX;
}

OpenGL::ShaderState::ShaderState()
{
    compile_status = false;
    delete_status  = false;
    type           = OpenGL::ShaderType::Unknown;
}

OpenGL::TextureMipState::TextureMipState(const OpenGL::InternalFormat& in_internal_format,
                                         const uint32_t&               in_width,
                                         const uint32_t&               in_height,
                                         const uint32_t&               in_depth,
                                         const uint32_t&               in_samples,
                                         const bool&                   in_fixed_sample_locations)
{
    binding_texture_buffer_data_store = 0;
    compressed_image_size             = 0;
    fixed_sample_locations            = in_fixed_sample_locations;
    depth                             = in_depth;
    height                            = in_height;
    internal_format                   = in_internal_format;
    samples                           = in_samples;
    width                             = in_width;
}

OpenGL::TextureState::TextureState(const OpenGL::TextureMinFilter& in_min_filter,
                                   const OpenGL::TextureWrapMode&  in_wrap_s,
                                   const OpenGL::TextureWrapMode&  in_wrap_t,
                                   const OpenGL::TextureWrapMode&  in_wrap_r)
{
    base_level                 = 0;
    border_color[0]            = 0;
    border_color[1]            = 0;
    border_color[2]            = 0;
    border_color[3]            = 0;
    compare_function           = OpenGL::TextureCompareFunction::LEqual;
    compare_mode               = OpenGL::TextureCompareMode::None;
    depth_stencil_texture_mode = OpenGL::DepthStencilTextureMode::Depth_Component;
    lod_bias                   = 0.0f;
    mag_filter                 = OpenGL::TextureMagFilter::Linear;
    max_level                  = 1000;
    max_lod                    = 1000.0f;
    min_filter                 = in_min_filter;
    min_lod                    = -1000.0f;
    swizzle_a                  = OpenGL::TextureSwizzle::Alpha;
    swizzle_b                  = OpenGL::TextureSwizzle::Blue;
    swizzle_g                  = OpenGL::TextureSwizzle::Green;
    swizzle_r                  = OpenGL::TextureSwizzle::Red;
    wrap_r                     = in_wrap_r;
    wrap_s                     = in_wrap_s;
    wrap_t                     = in_wrap_t;
}

OpenGL::TextureUnitState::TextureUnitState()
{
    binding_1d                   = 0;
    binding_1d_array             = 0;
    binding_2d                   = 0;
    binding_2d_array             = 0;
    binding_2d_multisample       = 0;
    binding_2d_multisample_array = 0;
    binding_3d                   = 0;
    binding_cube_map             = 0;
    binding_rectangle            = 0;
    binding_texture_buffer       = 0;
}

OpenGL::TransformFeedbackVaryingState::TransformFeedbackVaryingState()
{
    size = 0;
    type = VariableType::Unknown;
}

OpenGL::UniformValue::UniformValue()
{
    ivec4[0] = 0;
    ivec4[1] = 0;
    ivec4[2] = 0;
    ivec4[3] = 0;
}

OpenGL::VertexArrayObjectState::VertexArrayObjectState(const uint32_t& in_n_vertex_attribute_arrays)
    :vertex_attribute_arrays(in_n_vertex_attribute_arrays)
{
    /* Stub */
}

OpenGL::VertexArrayObjectState::VertexArrayObjectState(const VertexArrayObjectState& in_vaa)
{
    *this = in_vaa;
}

OpenGL::VertexArrayObjectState& OpenGL::VertexArrayObjectState::operator=(const VertexArrayObjectState& in_state)
{
    if (in_state.element_array_buffer_binding_ptr != nullptr)
    {
        element_array_buffer_binding_ptr = in_state.element_array_buffer_binding_ptr->clone();
    }

    vertex_attribute_arrays = in_state.vertex_attribute_arrays;

    return *this;
}

OpenGL::VertexAttributeArrayState::VertexAttributeArrayState()
{
    /* As per table 6.4, core GL 3.2 spec */
    enabled    = false;
    integer    = false;
    normalized = false;
    pointer    = nullptr;
    size       = 4;
    stride     = 0;
    type       = VertexAttributeArrayType::Float;
}

OpenGL::VertexAttributeArrayState::VertexAttributeArrayState(const VertexAttributeArrayState& in_vaa_state)
{
    buffer_binding_ptr = (in_vaa_state.buffer_binding_ptr != nullptr) ? in_vaa_state.buffer_binding_ptr->clone()
                                                                      : GLBufferReferenceUniquePtr();
    enabled            = in_vaa_state.enabled;
    integer            = in_vaa_state.integer;
    normalized         = in_vaa_state.normalized;
    pointer            = in_vaa_state.pointer;
    size               = in_vaa_state.size;
    stride             = in_vaa_state.stride;
    type               = in_vaa_state.type;
}

OpenGL::VertexAttributeArrayState& OpenGL::VertexAttributeArrayState::operator=(const VertexAttributeArrayState& in_state)
{
    buffer_binding_ptr = (in_state.buffer_binding_ptr != nullptr) ? in_state.buffer_binding_ptr->clone()
                                                                  : GLBufferReferenceUniquePtr();
    enabled            = in_state.enabled;
    integer            = in_state.integer;
    normalized         = in_state.normalized;
    pointer            = in_state.pointer;
    size               = in_state.size;
    stride             = in_state.stride;
    type               = in_state.type;

    return *this;
}

bool OpenGL::VertexAttributeArrayState::operator==(const VertexAttributeArrayState& in_state)
{
    bool result = false;

    if (enabled    == in_state.enabled    &&
        integer    == in_state.integer    &&
        normalized == in_state.normalized &&
        pointer    == in_state.pointer    &&
        size       == in_state.size       &&
        stride     == in_state.stride     &&
        type       == in_state.type)
    {
        if ((buffer_binding_ptr == nullptr && in_state.buffer_binding_ptr == nullptr)                                                       ||
            (buffer_binding_ptr != nullptr && in_state.buffer_binding_ptr != nullptr && *buffer_binding_ptr == *in_state.buffer_binding_ptr))
        {
            result = true;
        }
    }

    return result;
}

OpenGL::PostLinkData::PostLinkData()
    :active_attribute_max_length         (0),
     active_uniform_block_max_name_length(0),
     active_uniform_max_length           (0),
     gs_input_type                       (OpenGL::GeometryInputType::Unknown),
     gs_output_type                      (OpenGL::GeometryOutputType::Unknown),
     max_active_attribute_location       (INT32_MAX),
     n_max_gs_vertices_generated         (0)
{
    /* Stub */
}

OpenGL::PostLinkData::PostLinkData(const OpenGL::PostLinkData& in_data)
{
    active_attribute_name_to_location_map = in_data.active_attribute_name_to_location_map;
    active_attributes                     = in_data.active_attributes;
    active_uniform_blocks                 = in_data.active_uniform_blocks;
    active_uniforms                       = in_data.active_uniforms;
    frag_data_locations                   = in_data.frag_data_locations;
    index_to_ub_and_uniform_index_pair    = in_data.index_to_ub_and_uniform_index_pair;
    link_log                              = in_data.link_log;

    active_attribute_max_length          = in_data.active_attribute_max_length;
    active_uniform_block_max_name_length = in_data.active_uniform_block_max_name_length;
    active_uniform_max_length            = in_data.active_uniform_max_length;

    gs_input_type                 = in_data.gs_input_type;
    gs_output_type                = in_data.gs_output_type;
    max_active_attribute_location = in_data.max_active_attribute_location;
    n_max_gs_vertices_generated   = in_data.n_max_gs_vertices_generated;

    init_ptr_valued_maps();
}

OpenGL::PostLinkData& OpenGL::PostLinkData::operator=(const OpenGL::PostLinkData& in_data)
{
    active_attribute_name_to_location_map = in_data.active_attribute_name_to_location_map;
    active_attributes                     = in_data.active_attributes;
    active_uniform_blocks                 = in_data.active_uniform_blocks;
    active_uniforms                       = in_data.active_uniforms;
    frag_data_locations                   = in_data.frag_data_locations;
    index_to_ub_and_uniform_index_pair    = in_data.index_to_ub_and_uniform_index_pair;
    link_log                              = in_data.link_log;

    active_attribute_max_length          = in_data.active_attribute_max_length;
    active_uniform_block_max_name_length = in_data.active_uniform_block_max_name_length;
    active_uniform_max_length            = in_data.active_uniform_max_length;

    gs_input_type                 = in_data.gs_input_type;
    gs_output_type                = in_data.gs_output_type;
    max_active_attribute_location = in_data.max_active_attribute_location;
    n_max_gs_vertices_generated   = in_data.n_max_gs_vertices_generated;

    init_ptr_valued_maps();

    return *this;
}

void OpenGL::PostLinkData::init_ptr_valued_maps()
{
    active_uniform_block_by_name_map.clear();
    active_uniform_by_name_map.clear      ();

    for (const auto& current_ub : active_uniform_blocks)
    {
        vkgl_assert(active_uniform_block_by_name_map.find(current_ub.name) == active_uniform_block_by_name_map.end() );

        active_uniform_block_by_name_map[current_ub.name] = &current_ub;
    }

    for (const auto& current_uniform : active_uniforms)
    {
        vkgl_assert(active_uniform_by_name_map.find(current_uniform.name) == active_uniform_by_name_map.end() );

        active_uniform_by_name_map[current_uniform.name] = &current_uniform;
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/gl_reference.h"
#include "OpenGL/types.h"

OpenGL::ActiveAttributeState::ActiveAttributeState()
{
    size = 0;
    type = VariableType::Unknown;
}

OpenGL::ActiveUniformBlock::ActiveUniformBlock()
{
    binding                       = UINT32_MAX;
    data_size                     = UINT32_MAX;
    referenced_by_fragment_shader = false;
    referenced_by_geometry_shader = false;
    referenced_by_vertex_shader   = false;
}

OpenGL::ActiveUniformState::ActiveUniformState()
{
    is_row_major          = false;
    location              = UINT32_MAX;
    size                  = 0;
    type                  = VariableType::Unknown;
    uniform_array_stride  = UINT32_MAX;
    uniform_block_index   = -1;
    uniform_block_offset  = UINT32_MAX;
    uniform_matrix_stride = UINT32_MAX;
}

OpenGL::BufferState::BufferState()
{
    access           = OpenGL::BufferAccess::Read_Write;
    map_size         = 0;
    map_start_offset = 0;
    mapped           = false;
    size             = 0;
    usage            = OpenGL::BufferUsage::Static_Draw;
}

OpenGL::ContextState::ContextState(const IGLLimits* in_limits_ptr,
                                   const int32_t*   in_viewport_ivec4_ptr,
                                   const int32_t*   in_scissor_box_ivec4_ptr)
    :texture_image_units                       (in_limits_ptr->get_max_texture_image_units() ),
     user_clip_planes_enabled                  (in_limits_ptr->get_max_clip_distances     (), false)
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

    blend_color[0]                    = 0;
    blend_color[1]                    = 0;
    blend_color[2]                    = 0;
    blend_color[3]                    = 0;
    blend_equation_alpha              = OpenGL::BlendEquation::Function_Add;
    blend_equation_rgb                = OpenGL::BlendEquation::Function_Add;
    blend_func_dst_alpha              = OpenGL::BlendFunction::Zero;
    blend_func_dst_rgb                = OpenGL::BlendFunction::Zero;
    blend_func_src_alpha              = OpenGL::BlendFunction::One;
    blend_func_src_rgb                = OpenGL::BlendFunction::One;
    depth_function                    = OpenGL::DepthFunction::Less;
    is_blend_enabled_for_draw_buffers = 0;
    is_color_logic_op_enabled         = false;
    is_depth_test_enabled             = false;
    is_dither_enabled                 = true;
    is_framebuffer_srgb_enabled       = false;
    logic_op_mode                     = OpenGL::LogicOpMode::Copy;

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

    binding_draw_framebuffer = 0;
    binding_read_framebuffer = 0;
    binding_renderbuffer     = 0;

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

    current_program_id = 0;

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

    version = "WIP";
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
    name                     = 0;
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

OpenGL::FramebufferState::FramebufferState(const uint32_t& in_n_color_attachments)
    :color_attachments           (in_n_color_attachments),
     draw_buffer_per_color_output(in_n_color_attachments)
{
    is_doublebuffer  = false;
    is_stereo        = false;
    n_sample_buffers = 0;
    n_samples        = 1;
    read_buffer      = 0;
}

OpenGL::ProgramState::ProgramState(const uint32_t& in_n_max_indexed_uniform_buffer_bindings)
    :uniform_buffer_binding_indexed(in_n_max_indexed_uniform_buffer_bindings)
{
    active_attribute_max_length           = 0;
    active_uniform_block_max_length       = 0;
    active_uniform_max_length             = 0;
    delete_status                         = false;
    link_status                           = false;
    n_geometry_vertices_out               = 0;
    n_transform_feedback_varyings         = 0;
    geometry_input_type                   = OpenGL::GeometryInputType::Unknown;
    geometry_output_type                  = OpenGL::GeometryOutputType::Unknown;
    transform_feedback_buffer_mode        = OpenGL::TransformFeedbackBufferMode::Unknown;
    transform_feedback_varying_max_length = 0;
    validate_status                       = false;
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

OpenGL::TextureImageState::TextureImageState(const OpenGL::InternalFormat& in_internal_format)
{
    binding_texture_buffer_data_store = 0;
    compressed_image_size             = 0;
    fixed_sample_locations            = true;
    depth                             = 0;
    height                            = 0;
    internal_format                   = in_internal_format;
    samples                           = 0;
    width                             = 0;
}

OpenGL::TextureState::TextureState(const OpenGL::TextureMinFilter& in_min_filter,
                                   const OpenGL::TextureWrapMode&  in_wrap_s,
                                   const OpenGL::TextureWrapMode&  in_wrap_t,
                                   const OpenGL::TextureWrapMode&  in_wrap_r)
{
    base_level       = 0;
    border_color[0]  = 0;
    border_color[1]  = 0;
    border_color[2]  = 0;
    border_color[3]  = 0;
    compare_function = OpenGL::TextureCompareFunction::LEqual;
    compare_mode     = OpenGL::TextureCompareMode::None;
    lod_bias         = 0.0f;
    mag_filter       = OpenGL::TextureMagFilter::Linear;
    max_level        = 1000;
    max_lod          = 1000.0f;
    min_filter       = in_min_filter;
    min_lod          = -1000.0f;
    wrap_r           = in_wrap_r;
    wrap_s           = in_wrap_s;
    wrap_t           = in_wrap_t;
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
    element_array_buffer_binding = 0;
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

OpenGL::VertexAttributeArrayState& OpenGL::VertexAttributeArrayState::operator=(const VertexAttributeArrayState& in_state)
{
    buffer_binding_ptr = (in_state.buffer_binding_ptr != nullptr) ? in_state.buffer_binding_ptr->clone()
                                                                  : GLReferenceUniquePtr();
    enabled            = in_state.enabled;
    integer            = in_state.integer;
    normalized         = in_state.normalized;
    pointer            = in_state.pointer;
    size               = in_state.size;
    stride             = in_state.stride;
    type               = in_state.type;

    return *this;
}
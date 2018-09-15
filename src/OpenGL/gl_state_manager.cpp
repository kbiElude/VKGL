/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/gl_state_manager.h"
#include "OpenGL/gl_vao_manager.h"
#include "OpenGL/utils_enum.h"

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
    OpenGL::BufferTarget::Element_Array_Buffer,
    OpenGL::BufferTarget::Pixel_Pack_Buffer,
    OpenGL::BufferTarget::Pixel_Unpack_Buffer,
    OpenGL::BufferTarget::Texture_Buffer,
    OpenGL::BufferTarget::Transform_Feedback_Buffer,
    OpenGL::BufferTarget::Uniform_Buffer,
};


OpenGL::GLStateManager::GLStateManager(const IGLLimits*        in_limits_ptr,
                                       const IGLObjectManager* in_buffer_manager_ptr,
                                       const IGLObjectManager* in_vao_manager_ptr)
    :m_current_error_code(OpenGL::ErrorCode::No_Error),
     m_limits_ptr        (in_limits_ptr)
{
    const int32_t scissor [4] = {0, 0, 0, 0}; /* TODO */
    const int32_t viewport[4] = {0, 0, 0, 0}; /* TODO */

    m_state_ptr.reset(
        new OpenGL::ContextState(in_limits_ptr,
                                 viewport,
                                 scissor)
    );
    vkgl_assert(m_state_ptr != nullptr);

    /* Set up default buffer bindings */
    for (const auto& current_indexed_target : g_indexed_buffer_targets)
    {
        const auto n_max_bindings = (current_indexed_target == OpenGL::BufferTarget::Transform_Feedback_Buffer) ? in_limits_ptr->get_max_transform_feedback_separate_attribs()
                                                                                                                : in_limits_ptr->get_max_uniform_buffer_bindings            ();

        for (uint32_t n_binding = 0;
                      n_binding < n_max_bindings;
                    ++n_binding)
        {
            m_indexed_buffer_binding_ptrs[IndexedBufferTarget(current_indexed_target, n_binding)] = IndexedBufferBinding(in_buffer_manager_ptr->get_default_object_reference(),
                                                                                                                         0,  /* in_start_offset */
                                                                                                                         0); /* in_size         */
        }
    }

    for (const auto& current_nonindexed_target : g_nonindexed_buffer_targets)
    {
        m_nonindexed_buffer_binding_ptrs[current_nonindexed_target] = in_buffer_manager_ptr->get_default_object_reference();
    }

    /* Set up default VAO binding */
    m_vao_binding_ptr = in_vao_manager_ptr->get_default_object_reference();

    init_prop_maps    ();
    init_texture_units();
}

OpenGL::GLStateManager::~GLStateManager()
{
}

void OpenGL::GLStateManager::disable(const OpenGL::Capability& in_capability)
{
    switch (in_capability)
    {
        case OpenGL::Capability::Blend:                     m_state_ptr->is_blend_enabled_for_draw_buffers    = 0;     break;
        case OpenGL::Capability::Color_Logic_Op:            m_state_ptr->is_color_logic_op_enabled            = false; break;
        case OpenGL::Capability::Cull_Face:                 m_state_ptr->is_cull_face_enabled                 = false; break;
        case OpenGL::Capability::Depth_Clamp:               m_state_ptr->is_depth_clamp_enabled               = false; break;
        case OpenGL::Capability::Depth_Test:                m_state_ptr->is_depth_test_enabled                = false; break;
        case OpenGL::Capability::Dither:                    m_state_ptr->is_dither_enabled                    = false; break;
        case OpenGL::Capability::Framebuffer_SRGB:          m_state_ptr->is_framebuffer_srgb_enabled          = false; break;
        case OpenGL::Capability::Line_Smooth:               m_state_ptr->is_line_smooth_enabled               = false; break;
        case OpenGL::Capability::Multisample:               m_state_ptr->is_multisample_enabled               = false; break;
        case OpenGL::Capability::Polygon_Offset_Fill:       m_state_ptr->is_polygon_offset_fill_enabled       = false; break;
        case OpenGL::Capability::Polygon_Offset_Line:       m_state_ptr->is_polygon_offset_line_enabled       = false; break;
        case OpenGL::Capability::Polygon_Offset_Point:      m_state_ptr->is_polygon_offset_point_enabled      = false; break;
        case OpenGL::Capability::Polygon_Smooth:            m_state_ptr->is_polygon_smooth_enabled            = false; break;
        case OpenGL::Capability::Primitive_Restart:         m_state_ptr->is_primitive_restart_enabled         = false; break;
        case OpenGL::Capability::Program_Point_Size:        m_state_ptr->is_program_point_size_enabled        = false; break;
        case OpenGL::Capability::Sample_Alpha_To_Coverage:  m_state_ptr->is_sample_alpha_to_coverage_enabled  = false; break;
        case OpenGL::Capability::Sample_Alpha_To_One:       m_state_ptr->is_sample_alpha_to_one_enabled       = false; break;
        case OpenGL::Capability::Sample_Coverage:           m_state_ptr->is_sample_coverage_enabled           = false; break;
        case OpenGL::Capability::Scissor_Test:              m_state_ptr->is_scissor_test_enabled              = false; break;
        case OpenGL::Capability::Stencil_Test:              m_state_ptr->is_stencil_test_enabled              = false; break;
        case OpenGL::Capability::Texture_Cube_Map_Seamless: m_state_ptr->is_texture_cube_map_seamless_enabled = false; break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

void OpenGL::GLStateManager::enable(const OpenGL::Capability& in_capability)
{
    switch (in_capability)
    {
        case OpenGL::Capability::Blend:                     m_state_ptr->is_blend_enabled_for_draw_buffers    = ~0;    break;
        case OpenGL::Capability::Color_Logic_Op:            m_state_ptr->is_color_logic_op_enabled            = true;  break;
        case OpenGL::Capability::Cull_Face:                 m_state_ptr->is_cull_face_enabled                 = true;  break;
        case OpenGL::Capability::Depth_Clamp:               m_state_ptr->is_depth_clamp_enabled               = true;  break;
        case OpenGL::Capability::Depth_Test:                m_state_ptr->is_depth_test_enabled                = true;  break;
        case OpenGL::Capability::Dither:                    m_state_ptr->is_dither_enabled                    = true;  break;
        case OpenGL::Capability::Framebuffer_SRGB:          m_state_ptr->is_framebuffer_srgb_enabled          = true;  break;
        case OpenGL::Capability::Line_Smooth:               m_state_ptr->is_line_smooth_enabled               = true;  break;
        case OpenGL::Capability::Multisample:               m_state_ptr->is_multisample_enabled               = true;  break;
        case OpenGL::Capability::Polygon_Offset_Fill:       m_state_ptr->is_polygon_offset_fill_enabled       = true;  break;
        case OpenGL::Capability::Polygon_Offset_Line:       m_state_ptr->is_polygon_offset_line_enabled       = true;  break;
        case OpenGL::Capability::Polygon_Offset_Point:      m_state_ptr->is_polygon_offset_point_enabled      = true;  break;
        case OpenGL::Capability::Polygon_Smooth:            m_state_ptr->is_polygon_smooth_enabled            = true;  break;
        case OpenGL::Capability::Primitive_Restart:         m_state_ptr->is_primitive_restart_enabled         = true;  break;
        case OpenGL::Capability::Program_Point_Size:        m_state_ptr->is_program_point_size_enabled        = true;  break;
        case OpenGL::Capability::Sample_Alpha_To_Coverage:  m_state_ptr->is_sample_alpha_to_coverage_enabled  = true;  break;
        case OpenGL::Capability::Sample_Alpha_To_One:       m_state_ptr->is_sample_alpha_to_one_enabled       = true;  break;
        case OpenGL::Capability::Sample_Coverage:           m_state_ptr->is_sample_coverage_enabled           = true;  break;
        case OpenGL::Capability::Scissor_Test:              m_state_ptr->is_scissor_test_enabled              = true;  break;
        case OpenGL::Capability::Stencil_Test:              m_state_ptr->is_stencil_test_enabled              = true;  break;
        case OpenGL::Capability::Texture_Cube_Map_Seamless: m_state_ptr->is_texture_cube_map_seamless_enabled = true;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

const OpenGL::GLReference* OpenGL::GLStateManager::get_bound_buffer_object(const OpenGL::BufferTarget& in_target) const
{
    vkgl_assert(m_nonindexed_buffer_binding_ptrs.find(in_target) != m_nonindexed_buffer_binding_ptrs.end() );

    return m_nonindexed_buffer_binding_ptrs.at(in_target).get();
}

const OpenGL::GLReference* OpenGL::GLStateManager::get_bound_buffer_object(const OpenGL::BufferTarget& in_target,
                                                                           const uint32_t&             in_index) const
{
    vkgl_assert(m_indexed_buffer_binding_ptrs.find(IndexedBufferTarget(in_target, in_index) ) != m_indexed_buffer_binding_ptrs.end() );

    return m_indexed_buffer_binding_ptrs.at(IndexedBufferTarget(in_target, in_index) ).reference_ptr.get();
}

const OpenGL::GLReference* OpenGL::GLStateManager::get_bound_vertex_array_object() const
{
    /* NOTE: There is ALWAYS a VAO binding set up for a GL context. */
    vkgl_assert(m_vao_binding_ptr != nullptr);

    return m_vao_binding_ptr.get();
}

OpenGL::ErrorCode OpenGL::GLStateManager::get_error(const bool& in_reset_error_code)
{
    OpenGL::ErrorCode result = m_current_error_code;

    /* TODO: In cases where we have pending GpU-side ops which may trigger deferred failures,
     *        this function should do a Context::Finish()
     */
    if (in_reset_error_code)
    {
        m_current_error_code = OpenGL::ErrorCode::No_Error;
    }

    return result;
}

void OpenGL::GLStateManager::get_parameter(const OpenGL::ContextProperty&    in_pname,
                                           const OpenGL::GetSetArgumentType& in_arg_type,
                                           void*                             out_arg_value_ptr) const
{
    const auto texture_binding_pname = OpenGL::Utils::get_texture_binding_property_for_context_property(in_pname);

    if (texture_binding_pname != OpenGL::TextureBindingProperty::Unknown)
    {
        get_texture_binding_parameter(texture_binding_pname,
                                      in_arg_type,
                                      out_arg_value_ptr);
    }
    else
    {
        const auto pixel_property_pname = OpenGL::Utils::get_pixel_store_property_from_context_property(in_pname);

        if (pixel_property_pname != OpenGL::PixelStoreProperty::Unknown)
        {
            get_pixel_store_parameter(pixel_property_pname,
                                      in_arg_type,
                                      out_arg_value_ptr);
        }
        else
        {
            const auto prop_map_iterator = m_context_prop_map.find(in_pname);

            vkgl_assert(prop_map_iterator != m_context_prop_map.end() );
            if (prop_map_iterator != m_context_prop_map.end() )
            {
                const auto& prop_props = prop_map_iterator->second;

                OpenGL::Converters::convert(prop_props.getter_value_type,
                                            prop_props.value_ptr,
                                            prop_props.n_value_components,
                                            in_arg_type,
                                            out_arg_value_ptr);
            }
        }
    }
}

void OpenGL::GLStateManager::get_pixel_store_parameter(const OpenGL::PixelStoreProperty& in_pname,
                                                       const OpenGL::GetSetArgumentType& in_arg_type,
                                                       void*                             out_arg_value_ptr) const
{
    const auto prop_map_iterator = m_pixel_store_prop_map.find(in_pname);

    vkgl_assert(prop_map_iterator != m_pixel_store_prop_map.end() );
    if (prop_map_iterator != m_pixel_store_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        OpenGL::Converters::convert(prop_props.getter_value_type,
                                    prop_props.value_ptr,
                                    prop_props.n_value_components,
                                    in_arg_type,
                                    out_arg_value_ptr);
    }
}

const OpenGL::ContextState* OpenGL::GLStateManager::get_state() const
{
    return m_state_ptr.get();
}

void OpenGL::GLStateManager::get_texture_binding_parameter(const OpenGL::TextureBindingProperty& in_pname,
                                                           const OpenGL::GetSetArgumentType&     in_arg_type,
                                                           void*                                 out_arg_value_ptr) const
{
    GLuint      result                = 0;
    const auto& texture_unit_data_ptr = m_texture_unit_to_state_ptr_map.at(m_state_ptr->active_texture_unit).get();;

    switch (in_pname)
    {
        case OpenGL::TextureBindingProperty::_1D:                   result = texture_unit_data_ptr->binding_1d;                   break;
        case OpenGL::TextureBindingProperty::_1D_Array:             result = texture_unit_data_ptr->binding_1d_array;             break;
        case OpenGL::TextureBindingProperty::_2D:                   result = texture_unit_data_ptr->binding_2d;                   break;
        case OpenGL::TextureBindingProperty::_2D_Array:             result = texture_unit_data_ptr->binding_2d_array;             break;
        case OpenGL::TextureBindingProperty::_2D_Multisample:       result = texture_unit_data_ptr->binding_2d_multisample;       break;
        case OpenGL::TextureBindingProperty::_2D_Multisample_Array: result = texture_unit_data_ptr->binding_2d_multisample_array; break;
        case OpenGL::TextureBindingProperty::_3D:                   result = texture_unit_data_ptr->binding_3d;                   break;
        case OpenGL::TextureBindingProperty::Buffer:                result = texture_unit_data_ptr->binding_texture_buffer;       break;
        case OpenGL::TextureBindingProperty::Cube_Map:              result = texture_unit_data_ptr->binding_cube_map;             break;
        case OpenGL::TextureBindingProperty::Rectangle:             result = texture_unit_data_ptr->binding_rectangle;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    OpenGL::Converters::convert(OpenGL::GetSetArgumentType::Int,
                               &result,
                                1, /* in_n_vals */
                                in_arg_type,
                                out_arg_value_ptr);
}

void OpenGL::GLStateManager::init_prop_maps()
{
    m_context_prop_map =
    {
        {OpenGL::ContextProperty::Active_Texture,                             {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->active_texture_unit}  },
        {OpenGL::ContextProperty::Blend,                                      {OpenGL::GetSetArgumentType::BooleanFromInt32_Bit0,         1, &m_state_ptr->is_blend_enabled_for_draw_buffers} },
        {OpenGL::ContextProperty::Blend_Color,                                {OpenGL::GetSetArgumentType::Float,                         4,  m_state_ptr->blend_color} },
        {OpenGL::ContextProperty::Blend_Dst_Alpha,                            {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_dst_alpha} },
        {OpenGL::ContextProperty::Blend_Dst_RGB,                              {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_dst_rgb} },
        {OpenGL::ContextProperty::Blend_Equation_Alpha,                       {OpenGL::GetSetArgumentType::BlendEquationVKGL,             1, &m_state_ptr->blend_equation_alpha} },
        {OpenGL::ContextProperty::Blend_Equation_RGB,                         {OpenGL::GetSetArgumentType::BlendEquationVKGL,             1, &m_state_ptr->blend_equation_rgb} },
        {OpenGL::ContextProperty::Blend_Src_Alpha,                            {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_src_alpha} },
        {OpenGL::ContextProperty::Blend_Src_RGB,                              {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_src_rgb} },
        {OpenGL::ContextProperty::Color_Clear_Value,                          {OpenGL::GetSetArgumentType::Float,                         4,  m_state_ptr->color_clear_value} },
        {OpenGL::ContextProperty::Color_Logic_Op,                             {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_color_logic_op_enabled} },
        {OpenGL::ContextProperty::Color_Writemask,                            {OpenGL::GetSetArgumentType::BooleanFromInt32_Bit0,         1, &m_state_ptr->color_writemask_for_draw_buffers} },
        {OpenGL::ContextProperty::Cull_Face,                                  {OpenGL::GetSetArgumentType::CullFaceVKGL,                  1, &m_state_ptr->cull_face_mode} },
        {OpenGL::ContextProperty::Current_Program,                            {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->current_program_id} },
        {OpenGL::ContextProperty::Depth_Clear_Value,                          {OpenGL::GetSetArgumentType::Double,                        1, &m_state_ptr->depth_clear_value} },
        {OpenGL::ContextProperty::Depth_Func,                                 {OpenGL::GetSetArgumentType::DepthFunctionVKGL,             1, &m_state_ptr->depth_function} },
        {OpenGL::ContextProperty::Depth_Range,                                {OpenGL::GetSetArgumentType::Double,                        2,  m_state_ptr->depth_range} },
        {OpenGL::ContextProperty::Depth_Test,                                 {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_depth_test_enabled} },
        {OpenGL::ContextProperty::Depth_Writemask,                            {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->depth_writemask} },
        {OpenGL::ContextProperty::Dither,                                     {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_dither_enabled} },
        {OpenGL::ContextProperty::Draw_Framebuffer_Binding,                   {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->binding_draw_framebuffer} },
        {OpenGL::ContextProperty::Fragment_Shader_Derivative_Hint,            {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_fragment_shader_derivative} },
        {OpenGL::ContextProperty::Line_Smooth,                                {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_line_smooth_enabled} },
        {OpenGL::ContextProperty::Line_Smooth_Hint,                           {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_line_smooth} },
        {OpenGL::ContextProperty::Line_Width,                                 {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->line_width} },
        {OpenGL::ContextProperty::Logic_Op_Mode,                              {OpenGL::GetSetArgumentType::LogicOpModeVKGL,               1, &m_state_ptr->logic_op_mode} },
        {OpenGL::ContextProperty::Point_Fade_Threshold_Size,                  {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->point_fade_threshold_size} },
        {OpenGL::ContextProperty::Point_Size,                                 {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->point_size} },
        {OpenGL::ContextProperty::Polygon_Offset_Factor,                      {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->polygon_offset_factor} },
        {OpenGL::ContextProperty::Polygon_Offset_Fill,                        {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_offset_fill_enabled} },
        {OpenGL::ContextProperty::Polygon_Offset_Line,                        {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_offset_line_enabled} },
        {OpenGL::ContextProperty::Polygon_Offset_Point,                       {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_offset_point_enabled} },
        {OpenGL::ContextProperty::Polygon_Offset_Units,                       {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->polygon_offset_units} },
        {OpenGL::ContextProperty::Polygon_Smooth,                             {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_smooth_enabled} },
        {OpenGL::ContextProperty::Polygon_Smooth_Hint,                        {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_polygon_smooth} },
        {OpenGL::ContextProperty::Primitive_Restart_Index,                    {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->primitive_restart_index} },
        {OpenGL::ContextProperty::Program_Point_Size,                         {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_program_point_size_enabled} },
        {OpenGL::ContextProperty::Provoking_Vertex,                           {OpenGL::GetSetArgumentType::ProvokingVertexConventionVKGL, 1, &m_state_ptr->provoking_vertex} },
        {OpenGL::ContextProperty::Read_Framebuffer_Binding,                   {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->binding_read_framebuffer} },
        // todo {OpenGL::ContextProperty::Sampler_Binding,                            {OpenGL::GetSetArgumentType::, 1, &m_state_ptr->} },
        {OpenGL::ContextProperty::Sample_Coverage_Invert,                     {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_sample_coverage_invert_enabled} },
        {OpenGL::ContextProperty::Sample_Coverage_Value,                      {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->sample_coverage_value} },
        {OpenGL::ContextProperty::Scissor_Box,                                {OpenGL::GetSetArgumentType::Int,                           4, &m_state_ptr->scissor_box} },
        {OpenGL::ContextProperty::Scissor_Test,                               {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_scissor_test_enabled} },
        {OpenGL::ContextProperty::Stencil_Back_Fail,                          {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_fail_back} },
        {OpenGL::ContextProperty::Stencil_Back_Func,                          {OpenGL::GetSetArgumentType::StencilFunctionVKGL,           1, &m_state_ptr->stencil_function_back} },
        {OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Fail,               {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_fail_back} },
        {OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Pass,               {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_pass_back} },
        {OpenGL::ContextProperty::Stencil_Back_Ref,                           {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_reference_value_back} },
        {OpenGL::ContextProperty::Stencil_Back_Value_Mask,                    {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_value_mask_back} },
        {OpenGL::ContextProperty::Stencil_Back_Writemask,                     {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_writemask_back} },
        {OpenGL::ContextProperty::Stencil_Clear_Value,                        {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_clear_value} },
        {OpenGL::ContextProperty::Stencil_Fail,                               {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_fail_front} },
        {OpenGL::ContextProperty::Stencil_Func,                               {OpenGL::GetSetArgumentType::StencilFunctionVKGL,           1, &m_state_ptr->stencil_function_front} },
        {OpenGL::ContextProperty::Stencil_Pass_Depth_Fail,                    {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_fail_front} },
        {OpenGL::ContextProperty::Stencil_Pass_Depth_Pass,                    {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_pass_front} },
        {OpenGL::ContextProperty::Stencil_Ref,                                {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_reference_value_front} },
        {OpenGL::ContextProperty::Stencil_Test,                               {OpenGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_stencil_test_enabled} },
        {OpenGL::ContextProperty::Stencil_Value_Mask,                         {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_value_mask_front} },
        {OpenGL::ContextProperty::Stencil_Writemask,                          {OpenGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_writemask_front} },
        {OpenGL::ContextProperty::Texture_Compression_Hint,                   {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_texture_compression} },
        {OpenGL::ContextProperty::Version,                                    {OpenGL::GetSetArgumentType::String,                        1, &m_state_ptr->version} },
        {OpenGL::ContextProperty::Viewport,                                   {OpenGL::GetSetArgumentType::Float,                         1, &m_state_ptr->viewport} },
    };

    m_pixel_store_prop_map =
    {
        {OpenGL::PixelStoreProperty::Pack_Alignment,      {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_alignment}    },
        {OpenGL::PixelStoreProperty::Pack_Image_Height,   {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_image_height} },
        {OpenGL::PixelStoreProperty::Pack_LSB_First,      {OpenGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->pack_lsb_first}    },
        {OpenGL::PixelStoreProperty::Pack_Row_Length,     {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_row_length}   },
        {OpenGL::PixelStoreProperty::Pack_Skip_Images,    {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_skip_images}  },
        {OpenGL::PixelStoreProperty::Pack_Skip_Rows,      {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_skip_rows}    },
        {OpenGL::PixelStoreProperty::Pack_Swap_Bytes,     {OpenGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->pack_swap_bytes}   },

        {OpenGL::PixelStoreProperty::Unpack_Alignment,    {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_alignment}    },
        {OpenGL::PixelStoreProperty::Unpack_Image_Height, {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_image_height} },
        {OpenGL::PixelStoreProperty::Unpack_LSB_First,    {OpenGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->unpack_lsb_first}    },
        {OpenGL::PixelStoreProperty::Unpack_Row_Length,   {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_row_length}   },
        {OpenGL::PixelStoreProperty::Unpack_Skip_Images,  {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_skip_images}  },
        {OpenGL::PixelStoreProperty::Unpack_Skip_Rows,    {OpenGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_skip_rows}    },
        {OpenGL::PixelStoreProperty::Unpack_Swap_Bytes,   {OpenGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->unpack_swap_bytes}   },
    };

    m_point_prop_map =
    {
        {OpenGL::PointProperty::Fade_Threshold_Size, {OpenGL::GetSetArgumentType::Float,                      1, &m_state_ptr->point_fade_threshold_size} },
        {OpenGL::PointProperty::Sprite_Coord_Origin, {OpenGL::GetSetArgumentType::PointSpriteCoordOriginVKGL, 1, &m_state_ptr->point_sprite_coord_origin} },
    };
}

void OpenGL::GLStateManager::init_texture_units()
{
    const uint32_t n_texture_units = m_limits_ptr->get_max_texture_image_units();

    for (uint32_t n_texture_unit = 0;
                  n_texture_unit < n_texture_units;
                ++n_texture_unit)
    {
        m_texture_unit_to_state_ptr_map[n_texture_unit].reset(
            new TextureUnitState()
        );

        if (m_texture_unit_to_state_ptr_map[n_texture_unit] == nullptr)
        {
            vkgl_assert(m_texture_unit_to_state_ptr_map[n_texture_unit] != nullptr);
        }
    }
}

void OpenGL::GLStateManager::set_active_texture(const uint32_t& in_n_texture_unit)
{
    m_state_ptr->active_texture_unit = in_n_texture_unit;
}

void OpenGL::GLStateManager::set_blend_color(const float& in_red,
                                             const float& in_green,
                                             const float& in_blue,
                                             const float& in_alpha)
{
    m_state_ptr->blend_color[0] = in_red;
    m_state_ptr->blend_color[1] = in_green;
    m_state_ptr->blend_color[2] = in_blue;
    m_state_ptr->blend_color[3] = in_alpha;
}

void OpenGL::GLStateManager::set_blend_equation(const OpenGL::BlendEquation& in_blend_equation)
{
    m_state_ptr->blend_equation_alpha = in_blend_equation;
    m_state_ptr->blend_equation_rgb   = in_blend_equation;
}

void OpenGL::GLStateManager::set_blend_functions(const OpenGL::BlendFunction& in_src_rgba_function,
                                                 const OpenGL::BlendFunction& in_dst_rgba_function)
{
    m_state_ptr->blend_func_src_alpha = in_src_rgba_function;
    m_state_ptr->blend_func_src_rgb   = in_src_rgba_function;
    m_state_ptr->blend_func_dst_alpha = in_dst_rgba_function;
    m_state_ptr->blend_func_dst_rgb   = in_dst_rgba_function;

}

void OpenGL::GLStateManager::set_blend_functions_separate(const OpenGL::BlendFunction& in_src_rgb_function,
                                                          const OpenGL::BlendFunction& in_dst_rgb_function,
                                                          const OpenGL::BlendFunction& in_src_alpha_function,
                                                          const OpenGL::BlendFunction& in_dst_alpha_function)
{
    m_state_ptr->blend_func_src_alpha = in_src_alpha_function;
    m_state_ptr->blend_func_src_rgb   = in_src_rgb_function;
    m_state_ptr->blend_func_dst_alpha = in_dst_alpha_function;
    m_state_ptr->blend_func_dst_rgb   = in_dst_rgb_function;
}

void OpenGL::GLStateManager::set_bound_buffer_object(const OpenGL::BufferTarget&  in_target,
                                                     OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr)
{
    vkgl_assert(m_nonindexed_buffer_binding_ptrs.find(in_target) != m_nonindexed_buffer_binding_ptrs.end() );

    m_nonindexed_buffer_binding_ptrs[in_target] = std::move(in_buffer_reference_ptr);
}

void OpenGL::GLStateManager::set_bound_buffer_object(const OpenGL::BufferTarget&  in_target,
                                                     const uint32_t&              in_index,
                                                     OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                                                     const size_t&                in_start_offset,
                                                     const size_t&                in_size)
{
    vkgl_assert(m_indexed_buffer_binding_ptrs.find(IndexedBufferTarget(in_target, in_index) ) != m_indexed_buffer_binding_ptrs.end() );

    m_indexed_buffer_binding_ptrs[IndexedBufferTarget(in_target, in_index)] = IndexedBufferBinding(std::move(in_buffer_reference_ptr),
                                                                                                   in_start_offset,
                                                                                                   in_size);
}

void OpenGL::GLStateManager::set_bound_program_object(OpenGL::GLReferenceUniquePtr in_program_binding_ptr)
{
    m_program_binding_ptr = std::move(in_program_binding_ptr);
}


void OpenGL::GLStateManager::set_bound_vertex_array_object(OpenGL::GLReferenceUniquePtr in_vao_binding_ptr)
{
    m_vao_binding_ptr = std::move(in_vao_binding_ptr);
}

void OpenGL::GLStateManager::set_clear_color_value(const float& in_red,
                                                   const float& in_green,
                                                   const float& in_blue,
                                                   const float& in_alpha)
{
    m_state_ptr->color_clear_value[0] = in_red;
    m_state_ptr->color_clear_value[1] = in_green;
    m_state_ptr->color_clear_value[2] = in_blue;
    m_state_ptr->color_clear_value[3] = in_alpha;
}

void OpenGL::GLStateManager::set_clear_depth_value(const double& in_value)
{
    m_state_ptr->depth_clear_value = in_value;
}

void OpenGL::GLStateManager::set_clear_stencil_value(const int& in_value)
{
    m_state_ptr->stencil_clear_value = in_value;
}

void OpenGL::GLStateManager::set_color_mask(const bool& in_red,
                                            const bool& in_green,
                                            const bool& in_blue,
                                            const bool& in_alpha)
{
    const uint32_t red_mask   = (in_red)   ? ((1 << 0) | (1 << 4) | (1 << 8)  | (1 << 12) | (1 << 16) | (1 << 20) | (1 << 24) | (1 << 28)) : 0;
    const uint32_t green_mask = (in_green) ? ((1 << 1) | (1 << 5) | (1 << 9)  | (1 << 13) | (1 << 17) | (1 << 21) | (1 << 25) | (1 << 29)) : 0;
    const uint32_t blue_mask  = (in_blue)  ? ((1 << 2) | (1 << 6) | (1 << 10) | (1 << 14) | (1 << 18) | (1 << 22) | (1 << 26) | (1 << 30)) : 0;
    const uint32_t alpha_mask = (in_alpha) ? ((1 << 3) | (1 << 7) | (1 << 11) | (1 << 15) | (1 << 19) | (1 << 23) | (1 << 27) | (1 << 31)) : 0;

    m_state_ptr->color_writemask_for_draw_buffers = red_mask | green_mask | blue_mask | alpha_mask;
}

void OpenGL::GLStateManager::set_cull_mode(const OpenGL::CullMode& in_mode)
{
    m_state_ptr->cull_face_mode = in_mode;
}

void OpenGL::GLStateManager::set_depth_function(const OpenGL::DepthFunction& in_function)
{
    m_state_ptr->depth_function = in_function;
}

void OpenGL::GLStateManager::set_depth_mask(const bool& in_flag)
{
    m_state_ptr->depth_writemask = in_flag;
}

void OpenGL::GLStateManager::set_depth_range(const double& in_near,
                                             const double& in_far)
{
    m_state_ptr->depth_range[0] = in_near;
    m_state_ptr->depth_range[1] = in_far;
}

void OpenGL::GLStateManager::set_draw_buffer(const OpenGL::DrawBuffer& in_draw_buffer)
{
    vkgl_not_implemented();
}

void OpenGL::GLStateManager::set_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation)
{
    m_state_ptr->front_face = in_orientation;
}

void OpenGL::GLStateManager::set_hint(const OpenGL::HintTarget& in_target,
                                      const OpenGL::HintMode&   in_mode)
{
    switch (in_target)
    {
        case OpenGL::HintTarget::Fragment_Shader_Derivative: m_state_ptr->hint_fragment_shader_derivative = in_mode; break;
        case OpenGL::HintTarget::Line_Smooth:                m_state_ptr->hint_line_smooth                = in_mode; break;
        case OpenGL::HintTarget::Polygon_Smooth:             m_state_ptr->hint_polygon_smooth             = in_mode; break;
        case OpenGL::HintTarget::Texture_Compression:        m_state_ptr->hint_texture_compression        = in_mode; break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

void OpenGL::GLStateManager::set_line_width(const float& in_width)
{
    m_state_ptr->line_width = in_width;
}

void OpenGL::GLStateManager::set_logic_op(const OpenGL::LogicOpMode& in_mode)
{
    m_state_ptr->logic_op_mode = in_mode;
}

void OpenGL::GLStateManager::set_pixel_store_property(const OpenGL::PixelStoreProperty& in_property,
                                                      const OpenGL::GetSetArgumentType& in_arg_type,
                                                      const void*                       in_arg_value_ptr)
{
    const auto prop_map_iterator = m_pixel_store_prop_map.find(in_property);

    vkgl_assert(prop_map_iterator != m_pixel_store_prop_map.end() );
    if (prop_map_iterator != m_pixel_store_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        OpenGL::Converters::convert(in_arg_type,
                                    in_arg_value_ptr,
                                    prop_props.n_value_components,
                                    prop_props.getter_value_type,
                                    prop_map_iterator->second.value_ptr);
    }
}

void OpenGL::GLStateManager::set_point_property(const OpenGL::PointProperty&      in_property,
                                                const OpenGL::GetSetArgumentType& in_arg_type,
                                                const void*                       in_arg_value_ptr)
{
    const auto prop_map_iterator = m_point_prop_map.find(in_property);

    vkgl_assert(prop_map_iterator != m_point_prop_map.end() );
    if (prop_map_iterator != m_point_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        OpenGL::Converters::convert(in_arg_type,
                                    in_arg_value_ptr,
                                    prop_props.n_value_components,
                                    prop_props.getter_value_type,
                                    prop_map_iterator->second.value_ptr);
    }
}

void OpenGL::GLStateManager::set_point_size(const float& in_size)
{
    m_state_ptr->point_size = in_size;
}

void OpenGL::GLStateManager::set_polygon_mode(const OpenGL::PolygonMode& in_mode)
{
    m_state_ptr->polygon_mode = in_mode;
}

void OpenGL::GLStateManager::set_polygon_offset(const float& in_factor,
                                                const float& in_units)
{
    m_state_ptr->polygon_offset_factor = in_factor;
    m_state_ptr->polygon_offset_units  = in_units;
}

void OpenGL::GLStateManager::set_read_buffer(const OpenGL::ReadBuffer& in_read_buffer)
{
    vkgl_not_implemented();
}

void OpenGL::GLStateManager::set_sample_coverage(const float& in_value,
                                                 const bool&  in_invert)
{
    m_state_ptr->is_sample_coverage_invert_enabled = in_invert;
    m_state_ptr->sample_coverage_value             = in_value;
}

void OpenGL::GLStateManager::set_scissor(const int32_t& in_x,
                                         const int32_t& in_y,
                                         const size_t&  in_width,
                                         const size_t&  in_height)
{
    m_state_ptr->scissor_box[0] = in_x;
    m_state_ptr->scissor_box[1] = in_y;
    m_state_ptr->scissor_box[2] = static_cast<int32_t>(in_width);
    m_state_ptr->scissor_box[3] = static_cast<int32_t>(in_height);
}

void OpenGL::GLStateManager::set_stencil_function(const OpenGL::StencilFunction& in_func,
                                                  const int32_t&                 in_ref,
                                                  const uint32_t&                in_mask)
{
    m_state_ptr->stencil_function_back         = in_func;
    m_state_ptr->stencil_function_front        = in_func;
    m_state_ptr->stencil_reference_value_back  = in_ref;
    m_state_ptr->stencil_reference_value_front = in_ref;
    m_state_ptr->stencil_value_mask_back       = in_mask;
    m_state_ptr->stencil_value_mask_front      = in_mask;
}

void OpenGL::GLStateManager::set_stencil_mask(const uint32_t& in_mask)
{
    m_state_ptr->stencil_writemask_back  = in_mask;
    m_state_ptr->stencil_writemask_front = in_mask;
}

void OpenGL::GLStateManager::set_stencil_operations(const OpenGL::StencilOperation& in_fail,
                                                    const OpenGL::StencilOperation& in_zfail,
                                                    const OpenGL::StencilOperation& in_zpass)
{
    m_state_ptr->stencil_op_fail_back             = in_fail;
    m_state_ptr->stencil_op_fail_front            = in_fail;
    m_state_ptr->stencil_op_pass_depth_fail_back  = in_zfail;
    m_state_ptr->stencil_op_pass_depth_fail_front = in_zfail;
    m_state_ptr->stencil_op_pass_depth_pass_back  = in_zpass;
    m_state_ptr->stencil_op_pass_depth_pass_front = in_zpass;
}

void OpenGL::GLStateManager::set_texture_binding(const uint32_t&              in_n_texture_unit,
                                                 const OpenGL::TextureTarget& in_texture_target,
                                                 const GLuint&                in_texture_id)
{
    auto texture_unit_state_ptr = m_texture_unit_to_state_ptr_map.at(in_n_texture_unit).get();

    vkgl_assert(texture_unit_state_ptr != nullptr);
    if (texture_unit_state_ptr != nullptr)
    {
        switch (in_texture_target)
        {
            case OpenGL::TextureTarget::_1D:                   texture_unit_state_ptr->binding_1d                   = in_texture_id; break;
            case OpenGL::TextureTarget::_1D_Array:             texture_unit_state_ptr->binding_1d_array             = in_texture_id; break;
            case OpenGL::TextureTarget::_2D:                   texture_unit_state_ptr->binding_2d                   = in_texture_id; break;
            case OpenGL::TextureTarget::_2D_Array:             texture_unit_state_ptr->binding_2d_array             = in_texture_id; break;
            case OpenGL::TextureTarget::_2D_Multisample:       texture_unit_state_ptr->binding_2d_multisample       = in_texture_id; break;
            case OpenGL::TextureTarget::_2D_Multisample_Array: texture_unit_state_ptr->binding_2d_multisample_array = in_texture_id; break;
            case OpenGL::TextureTarget::_3D:                   texture_unit_state_ptr->binding_3d                   = in_texture_id; break;
            case OpenGL::TextureTarget::Cube_Map:              texture_unit_state_ptr->binding_cube_map             = in_texture_id; break;
            case OpenGL::TextureTarget::Rectangle:             texture_unit_state_ptr->binding_rectangle            = in_texture_id; break;
            case OpenGL::TextureTarget::Texture_Buffer:        texture_unit_state_ptr->binding_texture_buffer       = in_texture_id; break;

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

void OpenGL::GLStateManager::set_viewport(const int32_t& in_x,
                                          const int32_t& in_y,
                                          const size_t&  in_width,
                                          const size_t&  in_height)
{
    m_state_ptr->viewport[0] = in_x;
    m_state_ptr->viewport[1] = in_y;
    m_state_ptr->viewport[2] = static_cast<int32_t>(in_width);
    m_state_ptr->viewport[3] = static_cast<int32_t>(in_height);
}

bool OpenGL::GLStateManager::is_enabled(const OpenGL::Capability& in_capability) const
{
    bool result = false;

    switch (in_capability)
    {
        case OpenGL::Capability::Blend:                     result = (m_state_ptr->is_blend_enabled_for_draw_buffers & (1 << 0) ); break;
        case OpenGL::Capability::Color_Logic_Op:            result = m_state_ptr->is_color_logic_op_enabled;                       break;
        case OpenGL::Capability::Cull_Face:                 result = m_state_ptr->is_cull_face_enabled;                            break;
        case OpenGL::Capability::Depth_Clamp:               result = m_state_ptr->is_depth_clamp_enabled;                          break;
        case OpenGL::Capability::Depth_Test:                result = m_state_ptr->is_depth_test_enabled;                           break;
        case OpenGL::Capability::Dither:                    result = m_state_ptr->is_dither_enabled;                               break;
        case OpenGL::Capability::Framebuffer_SRGB:          result = m_state_ptr->is_framebuffer_srgb_enabled;                     break;
        case OpenGL::Capability::Line_Smooth:               result = m_state_ptr->is_line_smooth_enabled;                          break;
        case OpenGL::Capability::Multisample:               result = m_state_ptr->is_multisample_enabled;                          break;
        case OpenGL::Capability::Polygon_Offset_Fill:       result = m_state_ptr->is_polygon_offset_fill_enabled;                  break;
        case OpenGL::Capability::Polygon_Offset_Line:       result = m_state_ptr->is_polygon_offset_line_enabled;                  break;
        case OpenGL::Capability::Polygon_Offset_Point:      result = m_state_ptr->is_polygon_offset_point_enabled;                 break;
        case OpenGL::Capability::Polygon_Smooth:            result = m_state_ptr->is_polygon_smooth_enabled;                       break;
        case OpenGL::Capability::Primitive_Restart:         result = m_state_ptr->is_primitive_restart_enabled;                    break;
        case OpenGL::Capability::Program_Point_Size:        result = m_state_ptr->is_program_point_size_enabled;                   break;
        case OpenGL::Capability::Sample_Alpha_To_Coverage:  result = m_state_ptr->is_sample_alpha_to_coverage_enabled;             break;
        case OpenGL::Capability::Sample_Alpha_To_One:       result = m_state_ptr->is_sample_alpha_to_one_enabled;                  break;
        case OpenGL::Capability::Sample_Coverage:           result = m_state_ptr->is_sample_coverage_enabled;                      break;
        case OpenGL::Capability::Scissor_Test:              result = m_state_ptr->is_scissor_test_enabled;                         break;
        case OpenGL::Capability::Stencil_Test:              result = m_state_ptr->is_stencil_test_enabled;                         break;
        case OpenGL::Capability::Texture_Cube_Map_Seamless: result = m_state_ptr->is_texture_cube_map_seamless_enabled;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

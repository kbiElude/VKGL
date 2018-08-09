/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/converters.h"
#include "OpenGL/gl_state_manager.h"
#include "OpenGL/utils_enum.h"

VKGL::GLStateManager::GLStateManager(const IGLLimits* in_limits_ptr)
    :m_current_error_code(VKGL::ErrorCode::No_Error),
     m_limits_ptr        (in_limits_ptr)
{
    const int32_t scissor [4] = {0, 0, 0, 0}; /* TODO */
    const int32_t viewport[4] = {0, 0, 0, 0}; /* TODO */

    m_state_ptr.reset(
        new VKGL::ContextState(in_limits_ptr,
                               viewport,
                               scissor)
    );
    vkgl_assert(m_state_ptr != nullptr);

    init_prop_maps    ();
    init_texture_units();
}

VKGL::GLStateManager::~GLStateManager()
{
}

void VKGL::GLStateManager::disable(const VKGL::Capability& in_capability)
{
    switch (in_capability)
    {
        case VKGL::Capability::Blend:                     m_state_ptr->is_blend_enabled_for_draw_buffers    = 0;     break;
        case VKGL::Capability::Color_Logic_Op:            m_state_ptr->is_color_logic_op_enabled            = false; break;
        case VKGL::Capability::Cull_Face:                 m_state_ptr->is_cull_face_enabled                 = false; break;
        case VKGL::Capability::Depth_Clamp:               m_state_ptr->is_depth_clamp_enabled               = false; break;
        case VKGL::Capability::Depth_Test:                m_state_ptr->is_depth_test_enabled                = false; break;
        case VKGL::Capability::Dither:                    m_state_ptr->is_dither_enabled                    = false; break;
        case VKGL::Capability::Framebuffer_SRGB:          m_state_ptr->is_framebuffer_srgb_enabled          = false; break;
        case VKGL::Capability::Line_Smooth:               m_state_ptr->is_line_smooth_enabled               = false; break;
        case VKGL::Capability::Multisample:               m_state_ptr->is_multisample_enabled               = false; break;
        case VKGL::Capability::Polygon_Offset_Fill:       m_state_ptr->is_polygon_offset_fill_enabled       = false; break;
        case VKGL::Capability::Polygon_Offset_Line:       m_state_ptr->is_polygon_offset_line_enabled       = false; break;
        case VKGL::Capability::Polygon_Offset_Point:      m_state_ptr->is_polygon_offset_point_enabled      = false; break;
        case VKGL::Capability::Polygon_Smooth:            m_state_ptr->is_polygon_smooth_enabled            = false; break;
        case VKGL::Capability::Primitive_Restart:         m_state_ptr->is_primitive_restart_enabled         = false; break;
        case VKGL::Capability::Program_Point_Size:        m_state_ptr->is_program_point_size_enabled        = false; break;
        case VKGL::Capability::Sample_Alpha_To_Coverage:  m_state_ptr->is_sample_alpha_to_coverage_enabled  = false; break;
        case VKGL::Capability::Sample_Alpha_To_One:       m_state_ptr->is_sample_alpha_to_one_enabled       = false; break;
        case VKGL::Capability::Sample_Coverage:           m_state_ptr->is_sample_coverage_enabled           = false; break;
        case VKGL::Capability::Scissor_Test:              m_state_ptr->is_scissor_test_enabled              = false; break;
        case VKGL::Capability::Stencil_Test:              m_state_ptr->is_stencil_test_enabled              = false; break;
        case VKGL::Capability::Texture_Cube_Map_Seamless: m_state_ptr->is_texture_cube_map_seamless_enabled = false; break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

void VKGL::GLStateManager::enable(const VKGL::Capability& in_capability)
{
    switch (in_capability)
    {
        case VKGL::Capability::Blend:                     m_state_ptr->is_blend_enabled_for_draw_buffers    = ~0;    break;
        case VKGL::Capability::Color_Logic_Op:            m_state_ptr->is_color_logic_op_enabled            = true;  break;
        case VKGL::Capability::Cull_Face:                 m_state_ptr->is_cull_face_enabled                 = true;  break;
        case VKGL::Capability::Depth_Clamp:               m_state_ptr->is_depth_clamp_enabled               = true;  break;
        case VKGL::Capability::Depth_Test:                m_state_ptr->is_depth_test_enabled                = true;  break;
        case VKGL::Capability::Dither:                    m_state_ptr->is_dither_enabled                    = true;  break;
        case VKGL::Capability::Framebuffer_SRGB:          m_state_ptr->is_framebuffer_srgb_enabled          = true;  break;
        case VKGL::Capability::Line_Smooth:               m_state_ptr->is_line_smooth_enabled               = true;  break;
        case VKGL::Capability::Multisample:               m_state_ptr->is_multisample_enabled               = true;  break;
        case VKGL::Capability::Polygon_Offset_Fill:       m_state_ptr->is_polygon_offset_fill_enabled       = true;  break;
        case VKGL::Capability::Polygon_Offset_Line:       m_state_ptr->is_polygon_offset_line_enabled       = true;  break;
        case VKGL::Capability::Polygon_Offset_Point:      m_state_ptr->is_polygon_offset_point_enabled      = true;  break;
        case VKGL::Capability::Polygon_Smooth:            m_state_ptr->is_polygon_smooth_enabled            = true;  break;
        case VKGL::Capability::Primitive_Restart:         m_state_ptr->is_primitive_restart_enabled         = true;  break;
        case VKGL::Capability::Program_Point_Size:        m_state_ptr->is_program_point_size_enabled        = true;  break;
        case VKGL::Capability::Sample_Alpha_To_Coverage:  m_state_ptr->is_sample_alpha_to_coverage_enabled  = true;  break;
        case VKGL::Capability::Sample_Alpha_To_One:       m_state_ptr->is_sample_alpha_to_one_enabled       = true;  break;
        case VKGL::Capability::Sample_Coverage:           m_state_ptr->is_sample_coverage_enabled           = true;  break;
        case VKGL::Capability::Scissor_Test:              m_state_ptr->is_scissor_test_enabled              = true;  break;
        case VKGL::Capability::Stencil_Test:              m_state_ptr->is_stencil_test_enabled              = true;  break;
        case VKGL::Capability::Texture_Cube_Map_Seamless: m_state_ptr->is_texture_cube_map_seamless_enabled = true;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

VKGL::ErrorCode VKGL::GLStateManager::get_error(const bool& in_reset_error_code)
{
    VKGL::ErrorCode result = m_current_error_code;

    /* TODO: In cases where we have pending GpU-side ops which may trigger deferred failures,
     *        this function should do a Context::Finish()
     */
    if (in_reset_error_code)
    {
        m_current_error_code = VKGL::ErrorCode::No_Error;
    }

    return result;
}

void VKGL::GLStateManager::get_parameter(const VKGL::ContextProperty&    in_pname,
                                         const VKGL::GetSetArgumentType& in_arg_type,
                                         void*                           out_arg_value_ptr) const
{
    const auto texture_binding_pname = VKGL::Utils::get_texture_binding_property_for_context_property(in_pname);

    if (texture_binding_pname != VKGL::TextureBindingProperty::Unknown)
    {
        get_texture_binding_parameter(texture_binding_pname,
                                      in_arg_type,
                                      out_arg_value_ptr);
    }
    else
    {
        const auto pixel_property_pname = VKGL::Utils::get_pixel_store_property_from_context_property(in_pname);

        if (pixel_property_pname != VKGL::PixelStoreProperty::Unknown)
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

                VKGL::Converters::convert(prop_props.getter_value_type,
                                          prop_props.value_ptr,
                                          prop_props.n_value_components,
                                          in_arg_type,
                                          out_arg_value_ptr);
            }
        }
    }
}

void VKGL::GLStateManager::get_pixel_store_parameter(const VKGL::PixelStoreProperty& in_pname,
                                                     const VKGL::GetSetArgumentType& in_arg_type,
                                                     void*                           out_arg_value_ptr) const
{
    const auto prop_map_iterator = m_pixel_store_prop_map.find(in_pname);

    vkgl_assert(prop_map_iterator != m_pixel_store_prop_map.end() );
    if (prop_map_iterator != m_pixel_store_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        VKGL::Converters::convert(prop_props.getter_value_type,
                                  prop_props.value_ptr,
                                  prop_props.n_value_components,
                                  in_arg_type,
                                  out_arg_value_ptr);
    }
}

const VKGL::ContextState* VKGL::GLStateManager::get_state() const
{
    return m_state_ptr.get();
}

void VKGL::GLStateManager::get_texture_binding_parameter(const VKGL::TextureBindingProperty& in_pname,
                                                         const VKGL::GetSetArgumentType&     in_arg_type,
                                                         void*                               out_arg_value_ptr) const
{
    GLuint      result                = 0;
    const auto& texture_unit_data_ptr = m_texture_unit_to_state_ptr_map.at(m_state_ptr->active_texture_unit).get();;

    switch (in_pname)
    {
        case VKGL::TextureBindingProperty::_1D:                   result = texture_unit_data_ptr->binding_1d;                   break;
        case VKGL::TextureBindingProperty::_1D_Array:             result = texture_unit_data_ptr->binding_1d_array;             break;
        case VKGL::TextureBindingProperty::_2D:                   result = texture_unit_data_ptr->binding_2d;                   break;
        case VKGL::TextureBindingProperty::_2D_Array:             result = texture_unit_data_ptr->binding_2d_array;             break;
        case VKGL::TextureBindingProperty::_2D_Multisample:       result = texture_unit_data_ptr->binding_2d_multisample;       break;
        case VKGL::TextureBindingProperty::_2D_Multisample_Array: result = texture_unit_data_ptr->binding_2d_multisample_array; break;
        case VKGL::TextureBindingProperty::_3D:                   result = texture_unit_data_ptr->binding_3d;                   break;
        case VKGL::TextureBindingProperty::Buffer:                result = texture_unit_data_ptr->binding_texture_buffer;       break;
        case VKGL::TextureBindingProperty::Cube_Map:              result = texture_unit_data_ptr->binding_cube_map;             break;
        case VKGL::TextureBindingProperty::Rectangle:             result = texture_unit_data_ptr->binding_rectangle;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    VKGL::Converters::convert(VKGL::GetSetArgumentType::Int,
                             &result,
                              1, /* in_n_vals */
                              in_arg_type,
                              out_arg_value_ptr);
}

void VKGL::GLStateManager::init_prop_maps()
{
    m_context_prop_map =
    {
        {VKGL::ContextProperty::Active_Texture,                             {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->active_texture_unit}  },
        {VKGL::ContextProperty::Blend,                                      {VKGL::GetSetArgumentType::BooleanFromInt32_Bit0,         1, &m_state_ptr->is_blend_enabled_for_draw_buffers} },
        {VKGL::ContextProperty::Blend_Color,                                {VKGL::GetSetArgumentType::Float,                         4,  m_state_ptr->blend_color} },
        {VKGL::ContextProperty::Blend_Dst_Alpha,                            {VKGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_dst_alpha} },
        {VKGL::ContextProperty::Blend_Dst_RGB,                              {VKGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_dst_rgb} },
        {VKGL::ContextProperty::Blend_Equation_Alpha,                       {VKGL::GetSetArgumentType::BlendEquationVKGL,             1, &m_state_ptr->blend_equation_alpha} },
        {VKGL::ContextProperty::Blend_Equation_RGB,                         {VKGL::GetSetArgumentType::BlendEquationVKGL,             1, &m_state_ptr->blend_equation_rgb} },
        {VKGL::ContextProperty::Blend_Src_Alpha,                            {VKGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_src_alpha} },
        {VKGL::ContextProperty::Blend_Src_RGB,                              {VKGL::GetSetArgumentType::BlendFunctionVKGL,             1, &m_state_ptr->blend_func_src_rgb} },
        {VKGL::ContextProperty::Color_Clear_Value,                          {VKGL::GetSetArgumentType::Float,                         4,  m_state_ptr->color_clear_value} },
        {VKGL::ContextProperty::Color_Logic_Op,                             {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_color_logic_op_enabled} },
        {VKGL::ContextProperty::Color_Writemask,                            {VKGL::GetSetArgumentType::BooleanFromInt32_Bit0,         1, &m_state_ptr->color_writemask_for_draw_buffers} },
        // TODO: {VKGL::ContextProperty::Context_Flags,                              {VKGL::GetSetArgumentType::, 1, &m_state_ptr->} },
        {VKGL::ContextProperty::Cull_Face,                                  {VKGL::GetSetArgumentType::CullFaceVKGL,                  1, &m_state_ptr->cull_face_mode} },
        {VKGL::ContextProperty::Current_Program,                            {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->current_program_id} },
        {VKGL::ContextProperty::Depth_Clear_Value,                          {VKGL::GetSetArgumentType::Double,                        1, &m_state_ptr->depth_clear_value} },
        {VKGL::ContextProperty::Depth_Func,                                 {VKGL::GetSetArgumentType::DepthFunctionVKGL,             1, &m_state_ptr->depth_function} },
        {VKGL::ContextProperty::Depth_Range,                                {VKGL::GetSetArgumentType::Double,                        2,  m_state_ptr->depth_range} },
        {VKGL::ContextProperty::Depth_Test,                                 {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_depth_test_enabled} },
        {VKGL::ContextProperty::Depth_Writemask,                            {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->depth_writemask} },
        {VKGL::ContextProperty::Dither,                                     {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_dither_enabled} },
        {VKGL::ContextProperty::Draw_Framebuffer_Binding,                   {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->binding_draw_framebuffer} },
        {VKGL::ContextProperty::Fragment_Shader_Derivative_Hint,            {VKGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_fragment_shader_derivative} },
        {VKGL::ContextProperty::Line_Smooth,                                {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_line_smooth_enabled} },
        {VKGL::ContextProperty::Line_Smooth_Hint,                           {VKGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_line_smooth} },
        {VKGL::ContextProperty::Line_Width,                                 {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->line_width} },
        {VKGL::ContextProperty::Logic_Op_Mode,                              {VKGL::GetSetArgumentType::LogicOpModeVKGL,               1, &m_state_ptr->logic_op_mode} },
        {VKGL::ContextProperty::Point_Fade_Threshold_Size,                  {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->point_fade_threshold_size} },
        {VKGL::ContextProperty::Point_Size,                                 {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->point_size} },
        {VKGL::ContextProperty::Polygon_Offset_Factor,                      {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->polygon_offset_factor} },
        {VKGL::ContextProperty::Polygon_Offset_Fill,                        {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_offset_fill_enabled} },
        {VKGL::ContextProperty::Polygon_Offset_Line,                        {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_offset_line_enabled} },
        {VKGL::ContextProperty::Polygon_Offset_Point,                       {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_offset_point_enabled} },
        {VKGL::ContextProperty::Polygon_Offset_Units,                       {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->polygon_offset_units} },
        {VKGL::ContextProperty::Polygon_Smooth,                             {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_polygon_smooth_enabled} },
        {VKGL::ContextProperty::Polygon_Smooth_Hint,                        {VKGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_polygon_smooth} },
        {VKGL::ContextProperty::Primitive_Restart_Index,                    {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->primitive_restart_index} },
        {VKGL::ContextProperty::Program_Point_Size,                         {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_program_point_size_enabled} },
        {VKGL::ContextProperty::Provoking_Vertex,                           {VKGL::GetSetArgumentType::ProvokingVertexConventionVKGL, 1, &m_state_ptr->provoking_vertex} },
        {VKGL::ContextProperty::Read_Framebuffer_Binding,                   {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->binding_read_framebuffer} },
        // todo {VKGL::ContextProperty::Sampler_Binding,                            {VKGL::GetSetArgumentType::, 1, &m_state_ptr->} },
        {VKGL::ContextProperty::Sample_Coverage_Invert,                     {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_sample_coverage_invert_enabled} },
        {VKGL::ContextProperty::Sample_Coverage_Value,                      {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->sample_coverage_value} },
        {VKGL::ContextProperty::Scissor_Box,                                {VKGL::GetSetArgumentType::Int,                           4, &m_state_ptr->scissor_box} },
        {VKGL::ContextProperty::Scissor_Test,                               {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_scissor_test_enabled} },
        {VKGL::ContextProperty::Stencil_Back_Fail,                          {VKGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_fail_back} },
        {VKGL::ContextProperty::Stencil_Back_Func,                          {VKGL::GetSetArgumentType::StencilFunctionVKGL,           1, &m_state_ptr->stencil_function_back} },
        {VKGL::ContextProperty::Stencil_Back_Pass_Depth_Fail,               {VKGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_fail_back} },
        {VKGL::ContextProperty::Stencil_Back_Pass_Depth_Pass,               {VKGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_pass_back} },
        {VKGL::ContextProperty::Stencil_Back_Ref,                           {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_reference_value_back} },
        {VKGL::ContextProperty::Stencil_Back_Value_Mask,                    {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_value_mask_back} },
        {VKGL::ContextProperty::Stencil_Back_Writemask,                     {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_writemask_back} },
        {VKGL::ContextProperty::Stencil_Clear_Value,                        {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_clear_value} },
        {VKGL::ContextProperty::Stencil_Fail,                               {VKGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_fail_front} },
        {VKGL::ContextProperty::Stencil_Func,                               {VKGL::GetSetArgumentType::StencilFunctionVKGL,           1, &m_state_ptr->stencil_function_front} },
        {VKGL::ContextProperty::Stencil_Pass_Depth_Fail,                    {VKGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_fail_front} },
        {VKGL::ContextProperty::Stencil_Pass_Depth_Pass,                    {VKGL::GetSetArgumentType::StencilOperationVKGL,          1, &m_state_ptr->stencil_op_pass_depth_pass_front} },
        {VKGL::ContextProperty::Stencil_Ref,                                {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_reference_value_front} },
        {VKGL::ContextProperty::Stencil_Test,                               {VKGL::GetSetArgumentType::Boolean,                       1, &m_state_ptr->is_stencil_test_enabled} },
        {VKGL::ContextProperty::Stencil_Value_Mask,                         {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_value_mask_front} },
        {VKGL::ContextProperty::Stencil_Writemask,                          {VKGL::GetSetArgumentType::Int,                           1, &m_state_ptr->stencil_writemask_front} },
        {VKGL::ContextProperty::Texture_Compression_Hint,                   {VKGL::GetSetArgumentType::HintModeVKGL,                  1, &m_state_ptr->hint_texture_compression} },
        {VKGL::ContextProperty::Viewport,                                   {VKGL::GetSetArgumentType::Float,                         1, &m_state_ptr->viewport} },
    };

    m_pixel_store_prop_map =
    {
        {VKGL::PixelStoreProperty::Pack_Alignment,      {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_alignment}    },
        {VKGL::PixelStoreProperty::Pack_Image_Height,   {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_image_height} },
        {VKGL::PixelStoreProperty::Pack_LSB_First,      {VKGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->pack_lsb_first}    },
        {VKGL::PixelStoreProperty::Pack_Row_Length,     {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_row_length}   },
        {VKGL::PixelStoreProperty::Pack_Skip_Images,    {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_skip_images}  },
        {VKGL::PixelStoreProperty::Pack_Skip_Rows,      {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->pack_skip_rows}    },
        {VKGL::PixelStoreProperty::Pack_Swap_Bytes,     {VKGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->pack_swap_bytes}   },

        {VKGL::PixelStoreProperty::Unpack_Alignment,    {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_alignment}    },
        {VKGL::PixelStoreProperty::Unpack_Image_Height, {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_image_height} },
        {VKGL::PixelStoreProperty::Unpack_LSB_First,    {VKGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->unpack_lsb_first}    },
        {VKGL::PixelStoreProperty::Unpack_Row_Length,   {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_row_length}   },
        {VKGL::PixelStoreProperty::Unpack_Skip_Images,  {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_skip_images}  },
        {VKGL::PixelStoreProperty::Unpack_Skip_Rows,    {VKGL::GetSetArgumentType::Int,     1, &m_state_ptr->unpack_skip_rows}    },
        {VKGL::PixelStoreProperty::Unpack_Swap_Bytes,   {VKGL::GetSetArgumentType::Boolean, 1, &m_state_ptr->unpack_swap_bytes}   },
    };

    m_point_prop_map =
    {
        {VKGL::PointProperty::Fade_Threshold_Size, {VKGL::GetSetArgumentType::Float,                      1, &m_state_ptr->point_fade_threshold_size} },
        {VKGL::PointProperty::Sprite_Coord_Origin, {VKGL::GetSetArgumentType::PointSpriteCoordOriginVKGL, 1, &m_state_ptr->point_sprite_coord_origin} },
    };
}

void VKGL::GLStateManager::init_texture_units()
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

void VKGL::GLStateManager::set_active_texture(const uint32_t& in_n_texture_unit)
{
    m_state_ptr->active_texture_unit = in_n_texture_unit;
}

void VKGL::GLStateManager::set_blend_color(const float& in_red,
                                           const float& in_green,
                                           const float& in_blue,
                                           const float& in_alpha)
{
    m_state_ptr->blend_color[0] = in_red;
    m_state_ptr->blend_color[1] = in_green;
    m_state_ptr->blend_color[2] = in_blue;
    m_state_ptr->blend_color[3] = in_alpha;
}

void VKGL::GLStateManager::set_blend_equation(const VKGL::BlendEquation& in_blend_equation)
{
    m_state_ptr->blend_equation_alpha = in_blend_equation;
    m_state_ptr->blend_equation_rgb   = in_blend_equation;
}

void VKGL::GLStateManager::set_blend_functions(const VKGL::BlendFunction& in_src_rgba_function,
                                               const VKGL::BlendFunction& in_dst_rgba_function)
{
    m_state_ptr->blend_func_src_alpha = in_src_rgba_function;
    m_state_ptr->blend_func_src_rgb   = in_src_rgba_function;
    m_state_ptr->blend_func_dst_alpha = in_dst_rgba_function;
    m_state_ptr->blend_func_dst_rgb   = in_dst_rgba_function;

}

void VKGL::GLStateManager::set_blend_functions_separate(const VKGL::BlendFunction& in_src_rgb_function,
                                                        const VKGL::BlendFunction& in_dst_rgb_function,
                                                        const VKGL::BlendFunction& in_src_alpha_function,
                                                        const VKGL::BlendFunction& in_dst_alpha_function)
{
    m_state_ptr->blend_func_src_alpha = in_src_alpha_function;
    m_state_ptr->blend_func_src_rgb   = in_src_rgb_function;
    m_state_ptr->blend_func_dst_alpha = in_dst_alpha_function;
    m_state_ptr->blend_func_dst_rgb   = in_dst_rgb_function;
}

void VKGL::GLStateManager::set_clear_color_value(const float& in_red,
                                                 const float& in_green,
                                                 const float& in_blue,
                                                 const float& in_alpha)
{
    m_state_ptr->color_clear_value[0] = in_red;
    m_state_ptr->color_clear_value[1] = in_green;
    m_state_ptr->color_clear_value[2] = in_blue;
    m_state_ptr->color_clear_value[3] = in_alpha;
}

void VKGL::GLStateManager::set_clear_depth_value(const double& in_value)
{
    m_state_ptr->depth_clear_value = in_value;
}

void VKGL::GLStateManager::set_clear_stencil_value(const int& in_value)
{
    m_state_ptr->stencil_clear_value = in_value;
}

void VKGL::GLStateManager::set_color_mask(const bool& in_red,
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

void VKGL::GLStateManager::set_cull_mode(const VKGL::CullMode& in_mode)
{
    m_state_ptr->cull_face_mode = in_mode;
}

void VKGL::GLStateManager::set_depth_function(const VKGL::DepthFunction& in_function)
{
    m_state_ptr->depth_function = in_function;
}

void VKGL::GLStateManager::set_depth_mask(const bool& in_flag)
{
    m_state_ptr->depth_writemask = in_flag;
}

void VKGL::GLStateManager::set_depth_range(const double& in_near,
                                           const double& in_far)
{
    m_state_ptr->depth_range[0] = in_near;
    m_state_ptr->depth_range[1] = in_far;
}

void VKGL::GLStateManager::set_draw_buffer(const VKGL::DrawBuffer& in_draw_buffer)
{
    todo_fbos;
}

void VKGL::GLStateManager::set_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation)
{
    m_state_ptr->front_face = in_orientation;
}

void VKGL::GLStateManager::set_hint(const VKGL::HintTarget& in_target,
                                    const VKGL::HintMode&   in_mode)
{
    switch (in_target)
    {
        case VKGL::HintTarget::Fragment_Shader_Derivative: m_state_ptr->hint_fragment_shader_derivative = in_mode; break;
        case VKGL::HintTarget::Line_Smooth:                m_state_ptr->hint_line_smooth                = in_mode; break;
        case VKGL::HintTarget::Polygon_Smooth:             m_state_ptr->hint_polygon_smooth             = in_mode; break;
        case VKGL::HintTarget::Texture_Compression:        m_state_ptr->hint_texture_compression        = in_mode; break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

void VKGL::GLStateManager::set_line_width(const float& in_width)
{
    m_state_ptr->line_width = in_width;
}

void VKGL::GLStateManager::set_logic_op(const VKGL::LogicOpMode& in_mode)
{
    m_state_ptr->logic_op_mode = in_mode;
}

void VKGL::GLStateManager::set_pixel_store_property(const VKGL::PixelStoreProperty& in_property,
                                                    const VKGL::GetSetArgumentType& in_arg_type,
                                                    const void*                     in_arg_value_ptr)
{
    const auto prop_map_iterator = m_pixel_store_prop_map.find(in_property);

    vkgl_assert(prop_map_iterator != m_pixel_store_prop_map.end() );
    if (prop_map_iterator != m_pixel_store_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        VKGL::Converters::convert(in_arg_type,
                                  in_arg_value_ptr,
                                  prop_props.n_value_components,
                                  prop_props.getter_value_type,
                                  prop_map_iterator->second.value_ptr);
    }
}

void VKGL::GLStateManager::set_point_property(const VKGL::PointProperty&      in_property,
                                              const VKGL::GetSetArgumentType& in_arg_type,
                                              const void*                     in_arg_value_ptr)
{
    const auto prop_map_iterator = m_point_prop_map.find(in_property);

    vkgl_assert(prop_map_iterator != m_point_prop_map.end() );
    if (prop_map_iterator != m_point_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        VKGL::Converters::convert(in_arg_type,
                                  in_arg_value_ptr,
                                  prop_props.n_value_components,
                                  prop_props.getter_value_type,
                                  prop_map_iterator->second.value_ptr);
    }
}

void VKGL::GLStateManager::set_point_size(const float& in_size)
{
    m_state_ptr->point_size = in_size;
}

void VKGL::GLStateManager::set_polygon_mode(const VKGL::PolygonMode& in_mode)
{
    m_state_ptr->polygon_mode = in_mode;
}

void VKGL::GLStateManager::set_read_buffer(const VKGL::ReadBuffer& in_read_buffer)
{
    todo_fbos;
}

void VKGL::GLStateManager::set_sample_coverage(const float& in_value,
                                               const bool&  in_invert)
{
    m_state_ptr->is_sample_coverage_invert_enabled = in_invert;
    m_state_ptr->sample_coverage_value             = in_value;
}

void VKGL::GLStateManager::set_scissor(const int32_t& in_x,
                                       const int32_t& in_y,
                                       const size_t&  in_width,
                                       const size_t&  in_height)
{
    m_state_ptr->scissor_box[0] = in_x;
    m_state_ptr->scissor_box[1] = in_y;
    m_state_ptr->scissor_box[2] = static_cast<int32_t>(in_width);
    m_state_ptr->scissor_box[3] = static_cast<int32_t>(in_height);
}

void VKGL::GLStateManager::set_stencil_function(const VKGL::StencilFunction& in_func,
                                                const int32_t&               in_ref,
                                                const uint32_t&              in_mask)
{
    m_state_ptr->stencil_function_back         = in_func;
    m_state_ptr->stencil_function_front        = in_func;
    m_state_ptr->stencil_reference_value_back  = in_ref;
    m_state_ptr->stencil_reference_value_front = in_ref;
    m_state_ptr->stencil_value_mask_back       = in_mask;
    m_state_ptr->stencil_value_mask_front      = in_mask;
}

void VKGL::GLStateManager::set_stencil_mask(const uint32_t& in_mask)
{
    m_state_ptr->stencil_writemask_back  = in_mask;
    m_state_ptr->stencil_writemask_front = in_mask;
}

void VKGL::GLStateManager::set_stencil_operations(const VKGL::StencilOperation& in_fail,
                                                  const VKGL::StencilOperation& in_zfail,
                                                  const VKGL::StencilOperation& in_zpass)
{
    m_state_ptr->stencil_op_fail_back             = in_fail;
    m_state_ptr->stencil_op_fail_front            = in_fail;
    m_state_ptr->stencil_op_pass_depth_fail_back  = in_zfail;
    m_state_ptr->stencil_op_pass_depth_fail_front = in_zfail;
    m_state_ptr->stencil_op_pass_depth_pass_back  = in_zpass;
    m_state_ptr->stencil_op_pass_depth_pass_front = in_zpass;
}

void VKGL::GLStateManager::set_texture_binding(const uint32_t&            in_n_texture_unit,
                                               const VKGL::TextureTarget& in_texture_target,
                                               const GLuint&              in_texture_id)
{
    auto texture_unit_state_ptr = m_texture_unit_to_state_ptr_map.at(in_n_texture_unit).get();

    vkgl_assert(texture_unit_state_ptr != nullptr);
    if (texture_unit_state_ptr != nullptr)
    {
        switch (in_texture_target)
        {
            case VKGL::TextureTarget::_1D:                   texture_unit_state_ptr->binding_1d                   = in_texture_id; break;
            case VKGL::TextureTarget::_1D_Array:             texture_unit_state_ptr->binding_1d_array             = in_texture_id; break;
            case VKGL::TextureTarget::_2D:                   texture_unit_state_ptr->binding_2d                   = in_texture_id; break;
            case VKGL::TextureTarget::_2D_Array:             texture_unit_state_ptr->binding_2d_array             = in_texture_id; break;
            case VKGL::TextureTarget::_2D_Multisample:       texture_unit_state_ptr->binding_2d_multisample       = in_texture_id; break;
            case VKGL::TextureTarget::_2D_Multisample_Array: texture_unit_state_ptr->binding_2d_multisample_array = in_texture_id; break;
            case VKGL::TextureTarget::_3D:                   texture_unit_state_ptr->binding_3d                   = in_texture_id; break;
            case VKGL::TextureTarget::Cube_Map:              texture_unit_state_ptr->binding_cube_map             = in_texture_id; break;
            case VKGL::TextureTarget::Rectangle:             texture_unit_state_ptr->binding_rectangle            = in_texture_id; break;
            case VKGL::TextureTarget::Texture_Buffer:        texture_unit_state_ptr->binding_texture_buffer       = in_texture_id; break;

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

void VKGL::GLStateManager::set_viewport(const int32_t& in_x,
                                        const int32_t& in_y,
                                        const size_t&  in_width,
                                        const size_t&  in_height)
{
    m_state_ptr->viewport[0] = in_x;
    m_state_ptr->viewport[1] = in_y;
    m_state_ptr->viewport[2] = static_cast<int32_t>(in_width);
    m_state_ptr->viewport[3] = static_cast<int32_t>(in_height);
}

bool VKGL::GLStateManager::is_enabled(const VKGL::Capability& in_capability) const
{
    bool result = false;

    switch (in_capability)
    {
        case VKGL::Capability::Blend:                     result = (m_state_ptr->is_blend_enabled_for_draw_buffers & (1 << 0) ); break;
        case VKGL::Capability::Color_Logic_Op:            result = m_state_ptr->is_color_logic_op_enabled;                       break;
        case VKGL::Capability::Cull_Face:                 result = m_state_ptr->is_cull_face_enabled;                            break;
        case VKGL::Capability::Depth_Clamp:               result = m_state_ptr->is_depth_clamp_enabled;                          break;
        case VKGL::Capability::Depth_Test:                result = m_state_ptr->is_depth_test_enabled;                           break;
        case VKGL::Capability::Dither:                    result = m_state_ptr->is_dither_enabled;                               break;
        case VKGL::Capability::Framebuffer_SRGB:          result = m_state_ptr->is_framebuffer_srgb_enabled;                     break;
        case VKGL::Capability::Line_Smooth:               result = m_state_ptr->is_line_smooth_enabled;                          break;
        case VKGL::Capability::Multisample:               result = m_state_ptr->is_multisample_enabled;                          break;
        case VKGL::Capability::Polygon_Offset_Fill:       result = m_state_ptr->is_polygon_offset_fill_enabled;                  break;
        case VKGL::Capability::Polygon_Offset_Line:       result = m_state_ptr->is_polygon_offset_line_enabled;                  break;
        case VKGL::Capability::Polygon_Offset_Point:      result = m_state_ptr->is_polygon_offset_point_enabled;                 break;
        case VKGL::Capability::Polygon_Smooth:            result = m_state_ptr->is_polygon_smooth_enabled;                       break;
        case VKGL::Capability::Primitive_Restart:         result = m_state_ptr->is_primitive_restart_enabled;                    break;
        case VKGL::Capability::Program_Point_Size:        result = m_state_ptr->is_program_point_size_enabled;                   break;
        case VKGL::Capability::Sample_Alpha_To_Coverage:  result = m_state_ptr->is_sample_alpha_to_coverage_enabled;             break;
        case VKGL::Capability::Sample_Alpha_To_One:       result = m_state_ptr->is_sample_alpha_to_one_enabled;                  break;
        case VKGL::Capability::Sample_Coverage:           result = m_state_ptr->is_sample_coverage_enabled;                      break;
        case VKGL::Capability::Scissor_Test:              result = m_state_ptr->is_scissor_test_enabled;                         break;
        case VKGL::Capability::Stencil_Test:              result = m_state_ptr->is_stencil_test_enabled;                         break;
        case VKGL::Capability::Texture_Cube_Map_Seamless: result = m_state_ptr->is_texture_cube_map_seamless_enabled;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }
}

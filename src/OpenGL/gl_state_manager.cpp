/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/gl_state_manager.h"

VKGL::GLStateManager::GLStateManager(const IGLLimits* in_limits_ptr)
    :m_current_error_code(VKGL::ErrorCode::No_Error)
{
    const int32_t scissor [4] = {0, 0, 0, 0}; /* TODO */
    const int32_t viewport[4] = {0, 0, 0, 0}; /* TODO */

    m_state_ptr.reset(
        new VKGL::ContextState(in_limits_ptr,
                               viewport,
                               scissor)
    );
    vkgl_assert(m_state_ptr != nullptr);
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
    todo;
}

void VKGL::GLStateManager::set_blend_functions(const VKGL::BlendFunction& in_src_rgba_function,
                                               const VKGL::BlendFunction& in_dst_rgba_function)
{
    m_state_ptr->blend_func_src_alpha = in_src_rgba_function;
    m_state_ptr->blend_func_src_rgb   = in_src_rgba_function;
    m_state_ptr->blend_func_dst_alpha = in_dst_rgba_function;
    m_state_ptr->blend_func_dst_rgb   = in_dst_rgba_function;

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
    todo;
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

void VKGL::GLStateManager::set_scissor(const int32_t& in_x,
                                       const int32_t& in_y,
                                       const size_t&  in_width,
                                       const size_t&  in_height)
{
    m_state_ptr->scissor_box[0] = in_x;
    m_state_ptr->scissor_box[1] = in_y;
    m_state_ptr->scissor_box[2] = in_width;
    m_state_ptr->scissor_box[3] = in_height;
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

void VKGL::GLStateManager::set_viewport(const int32_t& in_x,
                                        const int32_t& in_y,
                                        const size_t&  in_width,
                                        const size_t&  in_height)
{
    m_state_ptr->viewport[0] = in_x;
    m_state_ptr->viewport[1] = in_y;
    m_state_ptr->viewport[2] = in_width;
    m_state_ptr->viewport[3] = in_height;
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

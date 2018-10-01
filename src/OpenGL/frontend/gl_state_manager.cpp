/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_state_manager.h"
#include "OpenGL/frontend/gl_vao_manager.h"
#include "OpenGL/utils_enum.h"
#include <cmath>

OpenGL::GLStateManager::GLStateManager(const IGLLimits*        in_limits_ptr,
                                       const IGLObjectManager* in_buffer_manager_ptr,
                                       const IGLObjectManager* in_vao_manager_ptr)
    :m_buffer_manager_ptr(in_buffer_manager_ptr),
     m_current_error_code(OpenGL::ErrorCode::No_Error),
     m_limits_ptr        (in_limits_ptr),
     m_vao_manager_ptr   (in_vao_manager_ptr)
{
    /* Initialize snapshot manager.. */
    m_snapshot_manager_ptr.reset(
        new OpenGL::SnapshotManager(dynamic_cast<OpenGL::IStateSnapshotAccessors*>(this),
                                    std::chrono::high_resolution_clock::now(),
                                    nullptr)
    );

    /* Set up texture unit bindings */
    init_texture_units();

    /* Refresh ToT snapshot before we continue .. */
    m_snapshot_manager_ptr->update_last_modified_time();

    /* Continue with less exciting initialization process.. */
    init_prop_maps();
}

OpenGL::GLStateManager::~GLStateManager()
{
    m_snapshot_manager_ptr.reset();
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLStateManager::clone_internal_data_object(const void* in_ptr)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){ delete reinterpret_cast<OpenGL::ContextState*>(in_ptr); });

    result_ptr.reset(
        new OpenGL::ContextState(*reinterpret_cast<const OpenGL::ContextState*>(in_ptr) )
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::GLStateManager::copy_internal_data_object(const void* in_src_ptr,
                                                       void*       in_dst_ptr)
{
    *reinterpret_cast<OpenGL::ContextState*>(in_dst_ptr) = *reinterpret_cast<const OpenGL::ContextState*>(in_src_ptr);
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLStateManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){ delete reinterpret_cast<OpenGL::ContextState*>(in_ptr); });

    const int32_t scissor [4] = {0, 0, 0, 0}; /* TODO */
    const int32_t viewport[4] = {0, 0, 0, 0}; /* TODO */

    result_ptr.reset(
        new OpenGL::ContextState(m_buffer_manager_ptr,
                                 m_vao_manager_ptr,
                                 m_limits_ptr,
                                 viewport,
                                 scissor)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::GLStateManager::disable(const OpenGL::Capability& in_capability)
{
    bool modified  = false;
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    switch (in_capability)
    {
        case OpenGL::Capability::Blend:
        {
            if (state_ptr->is_blend_enabled_for_draw_buffers != 0)
            {
                state_ptr->is_blend_enabled_for_draw_buffers = 0;
                modified                                     = true;
            }

            break;
        }

        case OpenGL::Capability::Color_Logic_Op:
        {
            if (state_ptr->is_color_logic_op_enabled)
            {
                state_ptr->is_color_logic_op_enabled = false;
                modified                             = true;
            }

            break;
        }

        case OpenGL::Capability::Cull_Face:
        {
            if (state_ptr->is_cull_face_enabled)
            {
                state_ptr->is_cull_face_enabled = false;
                modified                        = true;
            }

            break;
        }

        case OpenGL::Capability::Depth_Clamp:
        {
            if (state_ptr->is_depth_clamp_enabled)
            {
                state_ptr->is_depth_clamp_enabled = false;
                modified                          = true;
            }

            break;
        }

        case OpenGL::Capability::Depth_Test:
        {
            if (state_ptr->is_depth_test_enabled)
            {
                state_ptr->is_depth_test_enabled = false;
                modified                         = true;
            }

            break;
        }

        case OpenGL::Capability::Dither:
        {
            if (state_ptr->is_dither_enabled)
            {
                state_ptr->is_dither_enabled = false;
                modified                     = true;
            }

            break;
        }

        case OpenGL::Capability::Framebuffer_SRGB:
        {
            if (state_ptr->is_framebuffer_srgb_enabled)
            {
                state_ptr->is_framebuffer_srgb_enabled = false;
                modified                               = true;
            }

            break;
        }

        case OpenGL::Capability::Line_Smooth:
        {
            if (state_ptr->is_line_smooth_enabled)
            {
                state_ptr->is_line_smooth_enabled = false;
                modified                          = true;
            }

            break;
        }

        case OpenGL::Capability::Multisample:
        {
            if (state_ptr->is_multisample_enabled)
            {
                state_ptr->is_multisample_enabled = false;
                modified                          = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Offset_Fill:
        {
            if (state_ptr->is_polygon_offset_fill_enabled)
            {
                state_ptr->is_polygon_offset_fill_enabled = false;
                modified                                  = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Offset_Line:
        {
            if (state_ptr->is_polygon_offset_line_enabled)
            {
                state_ptr->is_polygon_offset_line_enabled = false;
                modified                                  = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Offset_Point:
        {
            if (state_ptr->is_polygon_offset_point_enabled)
            {
                state_ptr->is_polygon_offset_point_enabled = false;
                modified                                   = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Smooth:
        {
            if (state_ptr->is_polygon_smooth_enabled)
            {
                state_ptr->is_polygon_smooth_enabled = false;
                modified                             = true;
            }

            break;
        }

        case OpenGL::Capability::Primitive_Restart:
        {
            if (state_ptr->is_primitive_restart_enabled)
            {
                state_ptr->is_primitive_restart_enabled = false;
                modified                                = true;
            }

            break;
        }

        case OpenGL::Capability::Program_Point_Size:
        {
            if (state_ptr->is_program_point_size_enabled)
            {
                state_ptr->is_program_point_size_enabled = false;
                modified                                 = true;
            }

            break;
        }

        case OpenGL::Capability::Sample_Alpha_To_Coverage:
        {
            if (state_ptr->is_sample_alpha_to_coverage_enabled)
            {
                state_ptr->is_sample_alpha_to_coverage_enabled = false;
                modified                                       = true;
            }

            break;
        }

        case OpenGL::Capability::Sample_Alpha_To_One:
        {
            if (state_ptr->is_sample_alpha_to_one_enabled)
            {
                state_ptr->is_sample_alpha_to_one_enabled = false;
                modified                                  = true;
            }

            break;
        }

        case OpenGL::Capability::Sample_Coverage:
        {
            if (state_ptr->is_sample_coverage_enabled)
            {
                state_ptr->is_sample_coverage_enabled = false;
                modified                              = true;
            }

            break;
        }

        case OpenGL::Capability::Scissor_Test:
        {
            if (state_ptr->is_scissor_test_enabled)
            {
                state_ptr->is_scissor_test_enabled = false;
                modified                           = true;
            }

            break;
        }

        case OpenGL::Capability::Stencil_Test:
        {
            if (state_ptr->is_stencil_test_enabled)
            {
                state_ptr->is_stencil_test_enabled = false;
                modified                           = true;
            }

            break;
        }

        case OpenGL::Capability::Texture_Cube_Map_Seamless:
        {
            if (state_ptr->is_texture_cube_map_seamless_enabled)
            {
                state_ptr->is_texture_cube_map_seamless_enabled = false;
                modified                                        = true;
            }

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    if (modified)
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::enable(const OpenGL::Capability& in_capability)
{
    bool modified  = false;
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    switch (in_capability)
    {
        case OpenGL::Capability::Blend:
        {
            if (state_ptr->is_blend_enabled_for_draw_buffers != ~0)
            {
                state_ptr->is_blend_enabled_for_draw_buffers = ~0;
                modified                                     = true;
            }

            break;
        }

        case OpenGL::Capability::Color_Logic_Op:
        {
            if (!state_ptr->is_color_logic_op_enabled)
            {
                state_ptr->is_color_logic_op_enabled = true;
                modified                             = true;
            }

            break;
        }

        case OpenGL::Capability::Cull_Face:
        {
            if (!state_ptr->is_cull_face_enabled)
            {
                state_ptr->is_cull_face_enabled = true;
                modified                        = true;
            }

            break;
        }

        case OpenGL::Capability::Depth_Clamp:
        {
            if (!state_ptr->is_depth_clamp_enabled)
            {
                state_ptr->is_depth_clamp_enabled = true;
                modified                          = true;
            }

            break;
        }

        case OpenGL::Capability::Depth_Test:
        {
            if (!state_ptr->is_depth_test_enabled)
            {
                state_ptr->is_depth_test_enabled = true;
                modified                         = true;
            }

            break;
        }

        case OpenGL::Capability::Dither:
        {
            if (!state_ptr->is_dither_enabled)
            {
                state_ptr->is_dither_enabled = true;
                modified                     = true;
            }

            break;
        }

        case OpenGL::Capability::Framebuffer_SRGB:
        {
            if (!state_ptr->is_framebuffer_srgb_enabled)
            {
                state_ptr->is_framebuffer_srgb_enabled = true;
                modified                               = true;
            }

            break;
        }

        case OpenGL::Capability::Line_Smooth:
        {
            if (!state_ptr->is_line_smooth_enabled)
            {
                state_ptr->is_line_smooth_enabled = true;
                modified                          = true;
            }

            break;
        }

        case OpenGL::Capability::Multisample:
        {
            if (!state_ptr->is_multisample_enabled)
            {
                state_ptr->is_multisample_enabled = true;
                modified                          = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Offset_Fill:
        {
            if (!state_ptr->is_polygon_offset_fill_enabled)
            {
                state_ptr->is_polygon_offset_fill_enabled = true;
                modified                                  = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Offset_Line:
        {
            if (!state_ptr->is_polygon_offset_line_enabled)
            {
                state_ptr->is_polygon_offset_line_enabled = true;
                modified                                  = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Offset_Point:
        {
            if (!state_ptr->is_polygon_offset_point_enabled)
            {
                state_ptr->is_polygon_offset_point_enabled = true;
                modified                                   = true;
            }

            break;
        }

        case OpenGL::Capability::Polygon_Smooth:
        {
            if (!state_ptr->is_polygon_smooth_enabled)
            {
                state_ptr->is_polygon_smooth_enabled = true;
                modified                             = true;
            }

            break;
        }

        case OpenGL::Capability::Primitive_Restart:
        {
            if (!state_ptr->is_primitive_restart_enabled)
            {
                state_ptr->is_primitive_restart_enabled = true;
                modified                                = true;
            }

            break;
        }

        case OpenGL::Capability::Program_Point_Size:
        {
            if (!state_ptr->is_program_point_size_enabled)
            {
                state_ptr->is_program_point_size_enabled = true;
                modified                                 = true;
            }

            break;
        }

        case OpenGL::Capability::Sample_Alpha_To_Coverage:
        {
            if (!state_ptr->is_sample_alpha_to_coverage_enabled)
            {
                state_ptr->is_sample_alpha_to_coverage_enabled = true;
                modified                                       = true;
            }

            break;
        }

        case OpenGL::Capability::Sample_Alpha_To_One:
        {
            if (!state_ptr->is_sample_alpha_to_one_enabled)
            {
                state_ptr->is_sample_alpha_to_one_enabled = true;
                modified                                  = true;
            }

            break;
        }

        case OpenGL::Capability::Sample_Coverage:
        {
            if (!state_ptr->is_sample_coverage_enabled)
            {
                state_ptr->is_sample_coverage_enabled = true;
                modified                              = true;
            }

            break;
        }

        case OpenGL::Capability::Scissor_Test:
        {
            if (!state_ptr->is_scissor_test_enabled)
            {
                state_ptr->is_scissor_test_enabled = true;
                modified                           = true;
            }

            break;
        }

        case OpenGL::Capability::Stencil_Test:
        {
            if (!state_ptr->is_stencil_test_enabled)
            {
                state_ptr->is_stencil_test_enabled = true;
                modified                           = true;
            }

            break;
        }

        case OpenGL::Capability::Texture_Cube_Map_Seamless:
        {
            if (!state_ptr->is_texture_cube_map_seamless_enabled)
            {
                state_ptr->is_texture_cube_map_seamless_enabled = true;
                modified                                        = true;
            }

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    if (modified)
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

const OpenGL::GLReference* OpenGL::GLStateManager::get_bound_buffer_object(const OpenGL::BufferTarget& in_target) const
{
    auto state_ptr = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );

    vkgl_assert(state_ptr->nonindexed_buffer_binding_ptrs.find(in_target) != state_ptr->nonindexed_buffer_binding_ptrs.end() );

    return state_ptr->nonindexed_buffer_binding_ptrs.at(in_target).get();
}

const OpenGL::GLReference* OpenGL::GLStateManager::get_bound_buffer_object(const OpenGL::BufferTarget& in_target,
                                                                           const uint32_t&             in_index) const
{
    auto state_ptr = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );

    vkgl_assert(state_ptr->indexed_buffer_binding_ptrs.find(IndexedBufferTarget(in_target, in_index) ) != state_ptr->indexed_buffer_binding_ptrs.end() );

    return state_ptr->indexed_buffer_binding_ptrs.at(IndexedBufferTarget(in_target, in_index) ).reference_ptr.get();
}

const OpenGL::GLReference* OpenGL::GLStateManager::get_bound_vertex_array_object() const
{
    /* NOTE: There is ALWAYS a VAO binding set up for a GL context. */
    auto state_ptr = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );

    vkgl_assert(state_ptr->vao_reference_ptr != nullptr);

    return state_ptr->vao_reference_ptr.get();
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
    auto       state_ptr             = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );
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
                                            reinterpret_cast<const char*>(state_ptr) + prop_props.value_offset,
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
    auto       state_ptr         = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );

    vkgl_assert(prop_map_iterator != m_pixel_store_prop_map.end() );
    if (prop_map_iterator != m_pixel_store_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        OpenGL::Converters::convert(prop_props.getter_value_type,
                                    reinterpret_cast<const char*>(state_ptr) + prop_props.value_offset,
                                    prop_props.n_value_components,
                                    in_arg_type,
                                    out_arg_value_ptr);
    }
}

const OpenGL::ContextState* OpenGL::GLStateManager::get_state() const
{
    auto state_ptr = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );

    return state_ptr;
}

void OpenGL::GLStateManager::get_texture_binding_parameter(const OpenGL::TextureBindingProperty& in_pname,
                                                           const OpenGL::GetSetArgumentType&     in_arg_type,
                                                           void*                                 out_arg_value_ptr) const
{
    GLuint      result                = 0;
    auto        state_ptr             = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );
    const auto& texture_unit_data_ptr = state_ptr->texture_unit_to_state_ptr_map.at(state_ptr->active_texture_unit).get();;

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
        {OpenGL::ContextProperty::Active_Texture,                             {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, active_texture_unit)}  },
        {OpenGL::ContextProperty::Blend,                                      {OpenGL::GetSetArgumentType::BooleanFromInt32_Bit0,         1, offsetof(OpenGL::ContextState, is_blend_enabled_for_draw_buffers)} },
        {OpenGL::ContextProperty::Blend_Color,                                {OpenGL::GetSetArgumentType::Float,                         4, offsetof(OpenGL::ContextState, blend_color)} },
        {OpenGL::ContextProperty::Blend_Dst_Alpha,                            {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, offsetof(OpenGL::ContextState, blend_func_dst_alpha)} },
        {OpenGL::ContextProperty::Blend_Dst_RGB,                              {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, offsetof(OpenGL::ContextState, blend_func_dst_rgb)} },
        {OpenGL::ContextProperty::Blend_Equation_Alpha,                       {OpenGL::GetSetArgumentType::BlendEquationVKGL,             1, offsetof(OpenGL::ContextState, blend_equation_alpha)} },
        {OpenGL::ContextProperty::Blend_Equation_RGB,                         {OpenGL::GetSetArgumentType::BlendEquationVKGL,             1, offsetof(OpenGL::ContextState, blend_equation_rgb)} },
        {OpenGL::ContextProperty::Blend_Src_Alpha,                            {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, offsetof(OpenGL::ContextState, blend_func_src_alpha)} },
        {OpenGL::ContextProperty::Blend_Src_RGB,                              {OpenGL::GetSetArgumentType::BlendFunctionVKGL,             1, offsetof(OpenGL::ContextState, blend_func_src_rgb)} },
        {OpenGL::ContextProperty::Color_Clear_Value,                          {OpenGL::GetSetArgumentType::Float,                         4, offsetof(OpenGL::ContextState, color_clear_value)} },
        {OpenGL::ContextProperty::Color_Logic_Op,                             {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_color_logic_op_enabled)} },
        {OpenGL::ContextProperty::Color_Writemask,                            {OpenGL::GetSetArgumentType::BooleanFromInt32_Bit0,         1, offsetof(OpenGL::ContextState, color_writemask_for_draw_buffers)} },
        {OpenGL::ContextProperty::Cull_Face,                                  {OpenGL::GetSetArgumentType::CullFaceVKGL,                  1, offsetof(OpenGL::ContextState, cull_face_mode)} },
        {OpenGL::ContextProperty::Current_Program,                            {OpenGL::GetSetArgumentType::GLRereferenceObjectIDPtrVKGL,  1, offsetof(OpenGL::ContextState, program_reference_ptr)} },
        {OpenGL::ContextProperty::Depth_Clear_Value,                          {OpenGL::GetSetArgumentType::Double,                        1, offsetof(OpenGL::ContextState, depth_clear_value)} },
        {OpenGL::ContextProperty::Depth_Func,                                 {OpenGL::GetSetArgumentType::DepthFunctionVKGL,             1, offsetof(OpenGL::ContextState, depth_function)} },
        {OpenGL::ContextProperty::Depth_Range,                                {OpenGL::GetSetArgumentType::Double,                        2, offsetof(OpenGL::ContextState, depth_range)} },
        {OpenGL::ContextProperty::Depth_Test,                                 {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_depth_test_enabled)} },
        {OpenGL::ContextProperty::Depth_Writemask,                            {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, depth_writemask)} },
        {OpenGL::ContextProperty::Dither,                                     {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_dither_enabled)} },
        {OpenGL::ContextProperty::Draw_Framebuffer_Binding,                   {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, binding_draw_framebuffer)} },
        {OpenGL::ContextProperty::Fragment_Shader_Derivative_Hint,            {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, offsetof(OpenGL::ContextState, hint_fragment_shader_derivative)} },
        {OpenGL::ContextProperty::Line_Smooth,                                {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_line_smooth_enabled)} },
        {OpenGL::ContextProperty::Line_Smooth_Hint,                           {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, offsetof(OpenGL::ContextState, hint_line_smooth)} },
        {OpenGL::ContextProperty::Line_Width,                                 {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, line_width)} },
        {OpenGL::ContextProperty::Logic_Op_Mode,                              {OpenGL::GetSetArgumentType::LogicOpModeVKGL,               1, offsetof(OpenGL::ContextState, logic_op_mode)} },
        {OpenGL::ContextProperty::Point_Fade_Threshold_Size,                  {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, point_fade_threshold_size)} },
        {OpenGL::ContextProperty::Point_Size,                                 {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, point_size)} },
        {OpenGL::ContextProperty::Polygon_Offset_Factor,                      {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, polygon_offset_factor)} },
        {OpenGL::ContextProperty::Polygon_Offset_Fill,                        {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_polygon_offset_fill_enabled)} },
        {OpenGL::ContextProperty::Polygon_Offset_Line,                        {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_polygon_offset_line_enabled)} },
        {OpenGL::ContextProperty::Polygon_Offset_Point,                       {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_polygon_offset_point_enabled)} },
        {OpenGL::ContextProperty::Polygon_Offset_Units,                       {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, polygon_offset_units)} },
        {OpenGL::ContextProperty::Polygon_Smooth,                             {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_polygon_smooth_enabled)} },
        {OpenGL::ContextProperty::Polygon_Smooth_Hint,                        {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, offsetof(OpenGL::ContextState, hint_polygon_smooth)} },
        {OpenGL::ContextProperty::Primitive_Restart_Index,                    {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, primitive_restart_index)} },
        {OpenGL::ContextProperty::Program_Point_Size,                         {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_program_point_size_enabled)} },
        {OpenGL::ContextProperty::Provoking_Vertex,                           {OpenGL::GetSetArgumentType::ProvokingVertexConventionVKGL, 1, offsetof(OpenGL::ContextState, provoking_vertex)} },
        {OpenGL::ContextProperty::Read_Framebuffer_Binding,                   {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, binding_read_framebuffer)} },
        // todo {OpenGL::ContextProperty::Sampler_Binding,                            {OpenGL::GetSetArgumentType::, 1, &m_state_ptr->} },
        {OpenGL::ContextProperty::Sample_Coverage_Invert,                     {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_sample_coverage_invert_enabled)} },
        {OpenGL::ContextProperty::Sample_Coverage_Value,                      {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, sample_coverage_value)} },
        {OpenGL::ContextProperty::Scissor_Box,                                {OpenGL::GetSetArgumentType::Int,                           4, offsetof(OpenGL::ContextState, scissor_box)} },
        {OpenGL::ContextProperty::Scissor_Test,                               {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_scissor_test_enabled)} },
        {OpenGL::ContextProperty::Stencil_Back_Fail,                          {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, offsetof(OpenGL::ContextState, stencil_op_fail_back)} },
        {OpenGL::ContextProperty::Stencil_Back_Func,                          {OpenGL::GetSetArgumentType::StencilFunctionVKGL,           1, offsetof(OpenGL::ContextState, stencil_function_back)} },
        {OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Fail,               {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, offsetof(OpenGL::ContextState, stencil_op_pass_depth_fail_back)} },
        {OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Pass,               {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, offsetof(OpenGL::ContextState, stencil_op_pass_depth_pass_back)} },
        {OpenGL::ContextProperty::Stencil_Back_Ref,                           {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_reference_value_back)} },
        {OpenGL::ContextProperty::Stencil_Back_Value_Mask,                    {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_value_mask_back)} },
        {OpenGL::ContextProperty::Stencil_Back_Writemask,                     {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_writemask_back)} },
        {OpenGL::ContextProperty::Stencil_Clear_Value,                        {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_clear_value)} },
        {OpenGL::ContextProperty::Stencil_Fail,                               {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, offsetof(OpenGL::ContextState, stencil_op_fail_front)} },
        {OpenGL::ContextProperty::Stencil_Func,                               {OpenGL::GetSetArgumentType::StencilFunctionVKGL,           1, offsetof(OpenGL::ContextState, stencil_function_front)} },
        {OpenGL::ContextProperty::Stencil_Pass_Depth_Fail,                    {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, offsetof(OpenGL::ContextState, stencil_op_pass_depth_fail_front)} },
        {OpenGL::ContextProperty::Stencil_Pass_Depth_Pass,                    {OpenGL::GetSetArgumentType::StencilOperationVKGL,          1, offsetof(OpenGL::ContextState, stencil_op_pass_depth_pass_front)} },
        {OpenGL::ContextProperty::Stencil_Ref,                                {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_reference_value_front)} },
        {OpenGL::ContextProperty::Stencil_Test,                               {OpenGL::GetSetArgumentType::Boolean,                       1, offsetof(OpenGL::ContextState, is_stencil_test_enabled)} },
        {OpenGL::ContextProperty::Stencil_Value_Mask,                         {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_value_mask_front)} },
        {OpenGL::ContextProperty::Stencil_Writemask,                          {OpenGL::GetSetArgumentType::Int,                           1, offsetof(OpenGL::ContextState, stencil_writemask_front)} },
        {OpenGL::ContextProperty::Texture_Compression_Hint,                   {OpenGL::GetSetArgumentType::HintModeVKGL,                  1, offsetof(OpenGL::ContextState, hint_texture_compression)} },
        {OpenGL::ContextProperty::Viewport,                                   {OpenGL::GetSetArgumentType::Float,                         1, offsetof(OpenGL::ContextState, viewport)} }
    };

    m_pixel_store_prop_map =
    {
        {OpenGL::PixelStoreProperty::Pack_Alignment,      {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, pack_alignment)}    },
        {OpenGL::PixelStoreProperty::Pack_Image_Height,   {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, pack_image_height)} },
        {OpenGL::PixelStoreProperty::Pack_LSB_First,      {OpenGL::GetSetArgumentType::Boolean, 1, offsetof(OpenGL::ContextState, pack_lsb_first)}    },
        {OpenGL::PixelStoreProperty::Pack_Row_Length,     {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, pack_row_length)}   },
        {OpenGL::PixelStoreProperty::Pack_Skip_Images,    {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, pack_skip_images)}  },
        {OpenGL::PixelStoreProperty::Pack_Skip_Rows,      {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, pack_skip_rows)}    },
        {OpenGL::PixelStoreProperty::Pack_Swap_Bytes,     {OpenGL::GetSetArgumentType::Boolean, 1, offsetof(OpenGL::ContextState, pack_swap_bytes)}   },

        {OpenGL::PixelStoreProperty::Unpack_Alignment,    {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, unpack_alignment)}    },
        {OpenGL::PixelStoreProperty::Unpack_Image_Height, {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, unpack_image_height)} },
        {OpenGL::PixelStoreProperty::Unpack_LSB_First,    {OpenGL::GetSetArgumentType::Boolean, 1, offsetof(OpenGL::ContextState, unpack_lsb_first)}    },
        {OpenGL::PixelStoreProperty::Unpack_Row_Length,   {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, unpack_row_length)}   },
        {OpenGL::PixelStoreProperty::Unpack_Skip_Images,  {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, unpack_skip_images)}  },
        {OpenGL::PixelStoreProperty::Unpack_Skip_Rows,    {OpenGL::GetSetArgumentType::Int,     1, offsetof(OpenGL::ContextState, unpack_skip_rows)}    },
        {OpenGL::PixelStoreProperty::Unpack_Swap_Bytes,   {OpenGL::GetSetArgumentType::Boolean, 1, offsetof(OpenGL::ContextState, unpack_swap_bytes)}   },
    };

    m_point_prop_map =
    {
        {OpenGL::PointProperty::Fade_Threshold_Size, {OpenGL::GetSetArgumentType::Float,                      1, offsetof(OpenGL::ContextState, point_fade_threshold_size)} },
        {OpenGL::PointProperty::Sprite_Coord_Origin, {OpenGL::GetSetArgumentType::PointSpriteCoordOriginVKGL, 1, offsetof(OpenGL::ContextState, point_sprite_coord_origin)} },
    };
}

void OpenGL::GLStateManager::init_texture_units()
{
    const uint32_t n_texture_units = m_limits_ptr->get_max_texture_image_units();
    auto           state_ptr       = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    for (uint32_t n_texture_unit = 0;
                  n_texture_unit < n_texture_units;
                ++n_texture_unit)
    {
        state_ptr->texture_unit_to_state_ptr_map[n_texture_unit].reset(
            new TextureUnitState()
        );

        if (state_ptr->texture_unit_to_state_ptr_map[n_texture_unit] == nullptr)
        {
            vkgl_assert(state_ptr->texture_unit_to_state_ptr_map[n_texture_unit] != nullptr);
        }
    }
}

void OpenGL::GLStateManager::set_active_texture(const uint32_t& in_n_texture_unit)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->active_texture_unit != in_n_texture_unit)
    {
        state_ptr->active_texture_unit = in_n_texture_unit;

        m_snapshot_manager_ptr->update_last_modified_time();
    }

}

void OpenGL::GLStateManager::set_blend_color(const float& in_red,
                                             const float& in_green,
                                             const float& in_blue,
                                             const float& in_alpha)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->blend_color[0] - in_red)   > 1.0f / 255.0 /* r8 */ ||
        fabs(state_ptr->blend_color[1] - in_green) > 1.0f / 255.0 /* g8 */ ||
        fabs(state_ptr->blend_color[2] - in_blue)  > 1.0f / 255.0 /* b8 */ ||
        fabs(state_ptr->blend_color[3] - in_alpha) > 1.0f / 255.0 /* a8 */)
    {
        state_ptr->blend_color[0] = in_red;
        state_ptr->blend_color[1] = in_green;
        state_ptr->blend_color[2] = in_blue;
        state_ptr->blend_color[3] = in_alpha;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_blend_equation(const OpenGL::BlendEquation& in_blend_equation)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->blend_equation_alpha != in_blend_equation ||
        state_ptr->blend_equation_rgb   != in_blend_equation)
    {
        state_ptr->blend_equation_alpha = in_blend_equation;
        state_ptr->blend_equation_rgb   = in_blend_equation;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_blend_functions(const OpenGL::BlendFunction& in_src_rgba_function,
                                                 const OpenGL::BlendFunction& in_dst_rgba_function)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->blend_func_src_alpha != in_src_rgba_function ||
        state_ptr->blend_func_src_rgb   != in_src_rgba_function ||
        state_ptr->blend_func_dst_alpha != in_dst_rgba_function ||
        state_ptr->blend_func_dst_rgb   != in_dst_rgba_function)
    {
        state_ptr->blend_func_src_alpha = in_src_rgba_function;
        state_ptr->blend_func_src_rgb   = in_src_rgba_function;
        state_ptr->blend_func_dst_alpha = in_dst_rgba_function;
        state_ptr->blend_func_dst_rgb   = in_dst_rgba_function;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_blend_functions_separate(const OpenGL::BlendFunction& in_src_rgb_function,
                                                          const OpenGL::BlendFunction& in_dst_rgb_function,
                                                          const OpenGL::BlendFunction& in_src_alpha_function,
                                                          const OpenGL::BlendFunction& in_dst_alpha_function)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->blend_func_src_alpha != in_src_alpha_function ||
        state_ptr->blend_func_src_rgb   != in_src_rgb_function   ||
        state_ptr->blend_func_dst_alpha != in_dst_alpha_function ||
        state_ptr->blend_func_dst_rgb   != in_dst_rgb_function)
    {
        state_ptr->blend_func_src_alpha = in_src_alpha_function;
        state_ptr->blend_func_src_rgb   = in_src_rgb_function;
        state_ptr->blend_func_dst_alpha = in_dst_alpha_function;
        state_ptr->blend_func_dst_rgb   = in_dst_rgb_function;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_bound_buffer_object(const OpenGL::BufferTarget&  in_target,
                                                     OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr)
{
    auto state_ptr    = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );
    auto map_iterator = state_ptr->nonindexed_buffer_binding_ptrs.find(in_target);

    vkgl_assert(map_iterator != state_ptr->nonindexed_buffer_binding_ptrs.end() );

    if ((in_buffer_reference_ptr == nullptr && map_iterator->second != nullptr)                                                      ||
        (in_buffer_reference_ptr != nullptr && map_iterator->second == nullptr)                                                      ||
        (in_buffer_reference_ptr != nullptr && map_iterator->second != nullptr && *in_buffer_reference_ptr != *map_iterator->second) )
    {
        state_ptr->nonindexed_buffer_binding_ptrs[in_target] = std::move(in_buffer_reference_ptr);

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_bound_buffer_object(const OpenGL::BufferTarget&  in_target,
                                                     const uint32_t&              in_index,
                                                     OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                                                     const size_t&                in_start_offset,
                                                     const size_t&                in_size)
{
    auto state_ptr    = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );
    auto map_iterator = state_ptr->indexed_buffer_binding_ptrs.find(IndexedBufferTarget(in_target, in_index) );

    vkgl_assert(map_iterator != state_ptr->indexed_buffer_binding_ptrs.end() );

    if ((in_buffer_reference_ptr == nullptr && map_iterator->second.reference_ptr != nullptr)                                                                    ||
        (in_buffer_reference_ptr != nullptr && map_iterator->second.reference_ptr == nullptr)                                                                    ||
        (in_buffer_reference_ptr != nullptr && map_iterator->second.reference_ptr != nullptr && *in_buffer_reference_ptr != *map_iterator->second.reference_ptr) )
    {
        state_ptr->indexed_buffer_binding_ptrs[IndexedBufferTarget(in_target, in_index)] = IndexedBufferBinding(std::move(in_buffer_reference_ptr),
                                                                                                                in_start_offset,
                                                                                                                in_size);

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_bound_program_object(OpenGL::GLReferenceUniquePtr in_program_binding_ptr)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if ((in_program_binding_ptr == nullptr && state_ptr->program_reference_ptr != nullptr)                                                                 ||
        (in_program_binding_ptr != nullptr && state_ptr->program_reference_ptr == nullptr)                                                                 ||
        (in_program_binding_ptr != nullptr && state_ptr->program_reference_ptr != nullptr && *in_program_binding_ptr != *state_ptr->program_reference_ptr) )
    {
        state_ptr->program_reference_ptr = std::move(in_program_binding_ptr);

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}


void OpenGL::GLStateManager::set_bound_vertex_array_object(OpenGL::GLReferenceUniquePtr in_vao_binding_ptr)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if ((in_vao_binding_ptr == nullptr && state_ptr->vao_reference_ptr != nullptr)                                                         ||
        (in_vao_binding_ptr != nullptr && state_ptr->vao_reference_ptr == nullptr)                                                         ||
        (in_vao_binding_ptr != nullptr && state_ptr->vao_reference_ptr != nullptr && *in_vao_binding_ptr != *state_ptr->vao_reference_ptr) )
    {
        state_ptr->vao_reference_ptr = std::move(in_vao_binding_ptr);

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_clear_color_value(const float& in_red,
                                                   const float& in_green,
                                                   const float& in_blue,
                                                   const float& in_alpha)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->color_clear_value[0] - in_red)   > 1.0f / 255.0 /* r8 */ ||
        fabs(state_ptr->color_clear_value[1] - in_green) > 1.0f / 255.0 /* g8 */ ||
        fabs(state_ptr->color_clear_value[2] - in_blue)  > 1.0f / 255.0 /* b8 */ ||
        fabs(state_ptr->color_clear_value[3] - in_alpha) > 1.0f / 255.0 /* a8 */)
    {
        state_ptr->color_clear_value[0] = in_red;
        state_ptr->color_clear_value[1] = in_green;
        state_ptr->color_clear_value[2] = in_blue;
        state_ptr->color_clear_value[3] = in_alpha;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_clear_depth_value(const double& in_value)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->depth_clear_value - in_value) > 1e-5f)
    {
        state_ptr->depth_clear_value = in_value;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_clear_stencil_value(const int& in_value)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->stencil_clear_value != in_value)
    {
        state_ptr->stencil_clear_value = in_value;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
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
    auto           state_ptr  = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if ((red_mask | green_mask | blue_mask | alpha_mask) != state_ptr->color_writemask_for_draw_buffers)
    {
        state_ptr->color_writemask_for_draw_buffers = red_mask | green_mask | blue_mask | alpha_mask;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_cull_mode(const OpenGL::CullMode& in_mode)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->cull_face_mode != in_mode)
    {
        state_ptr->cull_face_mode = in_mode;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_depth_function(const OpenGL::DepthFunction& in_function)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->depth_function != in_function)
    {
        state_ptr->depth_function = in_function;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_depth_mask(const bool& in_flag)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->depth_writemask != in_flag)
    {
        state_ptr->depth_writemask = in_flag;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_depth_range(const double& in_near,
                                             const double& in_far)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->depth_range[0] - in_near) > 1e-5f ||
        fabs(state_ptr->depth_range[1] - in_far)  > 1e-5f)
    {
        state_ptr->depth_range[0] = in_near;
        state_ptr->depth_range[1] = in_far;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_draw_buffer(const OpenGL::DrawBuffer& in_draw_buffer)
{
    vkgl_not_implemented();

#if 0
    if (modified)
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
#endif
}

void OpenGL::GLStateManager::set_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->front_face != in_orientation)
    {
        state_ptr->front_face = in_orientation;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_hint(const OpenGL::HintTarget& in_target,
                                      const OpenGL::HintMode&   in_mode)
{
    bool modified  = false;
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    switch (in_target)
    {
        case OpenGL::HintTarget::Fragment_Shader_Derivative:
        {
            if (state_ptr->hint_fragment_shader_derivative != in_mode)
            {
                state_ptr->hint_fragment_shader_derivative = in_mode;
                modified                                   = true;
            }

            break;
        }

        case OpenGL::HintTarget::Line_Smooth:
        {
            if (state_ptr->hint_line_smooth != in_mode)
            {
                state_ptr->hint_line_smooth = in_mode;
                modified                    = true;
            }

            break;
        }

        case OpenGL::HintTarget::Polygon_Smooth:
        {
            if (state_ptr->hint_polygon_smooth != in_mode)
            {
                state_ptr->hint_polygon_smooth = in_mode;
                modified                       = true;
            }

            break;
        }

        case OpenGL::HintTarget::Texture_Compression:
        {
            if (state_ptr->hint_texture_compression != in_mode)
            {
                state_ptr->hint_texture_compression = in_mode;
                modified                            = true;
            }

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    if (modified)
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_line_width(const float& in_width)
{
    /* TODO: Use actually supported line granularity here. */
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->line_width - in_width) > 1e-5f)
    {
        state_ptr->line_width = in_width;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_logic_op(const OpenGL::LogicOpMode& in_mode)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->logic_op_mode != in_mode)
    {
        state_ptr->logic_op_mode = in_mode;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_pixel_store_property(const OpenGL::PixelStoreProperty& in_property,
                                                      const OpenGL::GetSetArgumentType& in_arg_type,
                                                      const void*                       in_arg_value_ptr)
{
    const auto prop_map_iterator = m_pixel_store_prop_map.find(in_property);
    auto       state_ptr         = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    vkgl_assert(prop_map_iterator != m_pixel_store_prop_map.end() );
    if (prop_map_iterator != m_pixel_store_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        OpenGL::Converters::convert(in_arg_type,
                                    in_arg_value_ptr,
                                    prop_props.n_value_components,
                                    prop_props.getter_value_type,
                                    reinterpret_cast<char*>(state_ptr) + prop_map_iterator->second.value_offset);
    }

    /* TODO: if (modified) */
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_point_property(const OpenGL::PointProperty&      in_property,
                                                const OpenGL::GetSetArgumentType& in_arg_type,
                                                const void*                       in_arg_value_ptr)
{
    const auto prop_map_iterator = m_point_prop_map.find(in_property);
    auto       state_ptr         = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    vkgl_assert(prop_map_iterator != m_point_prop_map.end() );
    if (prop_map_iterator != m_point_prop_map.end() )
    {
        const auto& prop_props = prop_map_iterator->second;

        OpenGL::Converters::convert(in_arg_type,
                                    in_arg_value_ptr,
                                    prop_props.n_value_components,
                                    prop_props.getter_value_type,
                                    reinterpret_cast<char*>(state_ptr) + prop_map_iterator->second.value_offset);
    }

    /* TODO: if (modified) */
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_point_size(const float& in_size)
{
    /* TODO: Use actually supported point granularity for the check below. */
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->point_size - in_size) > 1e-5f)
    {
        state_ptr->point_size = in_size;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_polygon_mode(const OpenGL::PolygonMode& in_mode)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->polygon_mode != in_mode)
    {
        state_ptr->polygon_mode = in_mode;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_polygon_offset(const float& in_factor,
                                                const float& in_units)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (fabs(state_ptr->polygon_offset_factor - in_factor) > 1e-5f ||
        fabs(state_ptr->polygon_offset_units  - in_units)  > 1e-5f)
    {
        state_ptr->polygon_offset_factor = in_factor;
        state_ptr->polygon_offset_units  = in_units;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_read_buffer(const OpenGL::ReadBuffer& in_read_buffer)
{
    vkgl_not_implemented();

#if 0
    if (modified)
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
#endif
}

void OpenGL::GLStateManager::set_sample_coverage(const float& in_value,
                                                 const bool&  in_invert)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->is_sample_coverage_invert_enabled      != in_invert ||
        fabs(state_ptr->sample_coverage_value - in_value) >  1e-5f)
    {
        state_ptr->is_sample_coverage_invert_enabled = in_invert;
        state_ptr->sample_coverage_value             = in_value;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_scissor(const int32_t& in_x,
                                         const int32_t& in_y,
                                         const size_t&  in_width,
                                         const size_t&  in_height)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->scissor_box[0] != in_x                            ||
        state_ptr->scissor_box[1] != in_y                            ||
        state_ptr->scissor_box[2] != static_cast<int32_t>(in_width)  ||
        state_ptr->scissor_box[3] != static_cast<int32_t>(in_height) )
    {
        state_ptr->scissor_box[0] = in_x;
        state_ptr->scissor_box[1] = in_y;
        state_ptr->scissor_box[2] = static_cast<int32_t>(in_width);
        state_ptr->scissor_box[3] = static_cast<int32_t>(in_height);

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_stencil_function(const OpenGL::StencilFunction& in_func,
                                                  const int32_t&                 in_ref,
                                                  const uint32_t&                in_mask)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->stencil_function_back         != in_func ||
        state_ptr->stencil_function_front        != in_func ||
        state_ptr->stencil_reference_value_back  != in_ref  ||
        state_ptr->stencil_reference_value_front != in_ref  ||
        state_ptr->stencil_value_mask_back       != in_mask ||
        state_ptr->stencil_value_mask_front      != in_mask)
    {
        state_ptr->stencil_function_back         = in_func;
        state_ptr->stencil_function_front        = in_func;
        state_ptr->stencil_reference_value_back  = in_ref;
        state_ptr->stencil_reference_value_front = in_ref;
        state_ptr->stencil_value_mask_back       = in_mask;
        state_ptr->stencil_value_mask_front      = in_mask;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_stencil_mask(const uint32_t& in_mask)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->stencil_writemask_back  != in_mask ||
        state_ptr->stencil_writemask_front != in_mask)
    {
        state_ptr->stencil_writemask_back  = in_mask;
        state_ptr->stencil_writemask_front = in_mask;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_stencil_operations(const OpenGL::StencilOperation& in_fail,
                                                    const OpenGL::StencilOperation& in_zfail,
                                                    const OpenGL::StencilOperation& in_zpass)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->stencil_op_fail_back             != in_fail  ||
        state_ptr->stencil_op_fail_front            != in_fail  ||
        state_ptr->stencil_op_pass_depth_fail_back  != in_zfail ||
        state_ptr->stencil_op_pass_depth_fail_front != in_zfail ||
        state_ptr->stencil_op_pass_depth_pass_back  != in_zpass ||
        state_ptr->stencil_op_pass_depth_pass_front != in_zpass)
    {
        state_ptr->stencil_op_fail_back             = in_fail;
        state_ptr->stencil_op_fail_front            = in_fail;
        state_ptr->stencil_op_pass_depth_fail_back  = in_zfail;
        state_ptr->stencil_op_pass_depth_fail_front = in_zfail;
        state_ptr->stencil_op_pass_depth_pass_back  = in_zpass;
        state_ptr->stencil_op_pass_depth_pass_front = in_zpass;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_texture_binding(const uint32_t&              in_n_texture_unit,
                                                 const OpenGL::TextureTarget& in_texture_target,
                                                 const GLuint&                in_texture_id)
{
    bool modified               = false;
    auto state_ptr              = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );
    auto texture_unit_state_ptr = state_ptr->texture_unit_to_state_ptr_map.at(in_n_texture_unit).get();

    vkgl_assert(texture_unit_state_ptr != nullptr);
    if (texture_unit_state_ptr != nullptr)
    {
        switch (in_texture_target)
        {
            case OpenGL::TextureTarget::_1D:
            {
                if (texture_unit_state_ptr->binding_1d != in_texture_id)
                {
                    texture_unit_state_ptr->binding_1d = in_texture_id;
                    modified                           = true;
                }

                break;
            }

            case OpenGL::TextureTarget::_1D_Array:
            {
                if (texture_unit_state_ptr->binding_1d_array != in_texture_id)
                {
                    texture_unit_state_ptr->binding_1d_array = in_texture_id;
                    modified                                 = true;
                }

                break;
            }

            case OpenGL::TextureTarget::_2D:
            {
                if (texture_unit_state_ptr->binding_2d != in_texture_id)
                {
                    texture_unit_state_ptr->binding_2d = in_texture_id;
                    modified                           = true;
                }

                break;
            }

            case OpenGL::TextureTarget::_2D_Array:
            {
                if (texture_unit_state_ptr->binding_2d_array != in_texture_id)
                {
                    texture_unit_state_ptr->binding_2d_array = in_texture_id;
                    modified                                 = true;
                }

                break;
            }

            case OpenGL::TextureTarget::_2D_Multisample:
            {
                if (texture_unit_state_ptr->binding_2d_multisample != in_texture_id)
                {
                    texture_unit_state_ptr->binding_2d_multisample = in_texture_id;
                    modified                                       = true;
                }

                break;
            }

            case OpenGL::TextureTarget::_2D_Multisample_Array:
            {
                if (texture_unit_state_ptr->binding_2d_multisample_array != in_texture_id)
                {
                    texture_unit_state_ptr->binding_2d_multisample_array = in_texture_id;
                    modified                                             = true;
                }

                break;
            }

            case OpenGL::TextureTarget::_3D:
            {
                if (texture_unit_state_ptr->binding_3d != in_texture_id)
                {
                    texture_unit_state_ptr->binding_3d = in_texture_id;
                    modified                           = true;
                }

                break;
            }

            case OpenGL::TextureTarget::Cube_Map:
            {
                texture_unit_state_ptr->binding_cube_map = in_texture_id;
                modified                                 = true;

                break;
            }

            case OpenGL::TextureTarget::Rectangle:
            {
                if (texture_unit_state_ptr->binding_rectangle != in_texture_id)
                {
                    texture_unit_state_ptr->binding_rectangle = in_texture_id;
                    modified                                  = true;
                }

                break;
            }

            case OpenGL::TextureTarget::Texture_Buffer:
            {
                if (texture_unit_state_ptr->binding_texture_buffer != in_texture_id)
                {
                    texture_unit_state_ptr->binding_texture_buffer = in_texture_id;
                    modified                                       = true;
                }

                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }

    if (modified)
    {
        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::GLStateManager::set_viewport(const int32_t& in_x,
                                          const int32_t& in_y,
                                          const size_t&  in_width,
                                          const size_t&  in_height)
{
    auto state_ptr = reinterpret_cast<OpenGL::ContextState*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    if (state_ptr->viewport[0] != in_x                            ||
        state_ptr->viewport[1] != in_y                            ||
        state_ptr->viewport[2] != static_cast<int32_t>(in_width)  ||
        state_ptr->viewport[3] != static_cast<int32_t>(in_height) )
    {
        state_ptr->viewport[0] = in_x;
        state_ptr->viewport[1] = in_y;
        state_ptr->viewport[2] = static_cast<int32_t>(in_width);
        state_ptr->viewport[3] = static_cast<int32_t>(in_height);

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

bool OpenGL::GLStateManager::is_enabled(const OpenGL::Capability& in_capability) const
{
    bool result    = false;
    auto state_ptr = reinterpret_cast<const OpenGL::ContextState*>(m_snapshot_manager_ptr->get_readonly_snapshot(OpenGL::LATEST_SNAPSHOT_AVAILABLE) );

    switch (in_capability)
    {
        case OpenGL::Capability::Blend:                     result = (state_ptr->is_blend_enabled_for_draw_buffers & (1 << 0) ); break;
        case OpenGL::Capability::Color_Logic_Op:            result = state_ptr->is_color_logic_op_enabled;                       break;
        case OpenGL::Capability::Cull_Face:                 result = state_ptr->is_cull_face_enabled;                            break;
        case OpenGL::Capability::Depth_Clamp:               result = state_ptr->is_depth_clamp_enabled;                          break;
        case OpenGL::Capability::Depth_Test:                result = state_ptr->is_depth_test_enabled;                           break;
        case OpenGL::Capability::Dither:                    result = state_ptr->is_dither_enabled;                               break;
        case OpenGL::Capability::Framebuffer_SRGB:          result = state_ptr->is_framebuffer_srgb_enabled;                     break;
        case OpenGL::Capability::Line_Smooth:               result = state_ptr->is_line_smooth_enabled;                          break;
        case OpenGL::Capability::Multisample:               result = state_ptr->is_multisample_enabled;                          break;
        case OpenGL::Capability::Polygon_Offset_Fill:       result = state_ptr->is_polygon_offset_fill_enabled;                  break;
        case OpenGL::Capability::Polygon_Offset_Line:       result = state_ptr->is_polygon_offset_line_enabled;                  break;
        case OpenGL::Capability::Polygon_Offset_Point:      result = state_ptr->is_polygon_offset_point_enabled;                 break;
        case OpenGL::Capability::Polygon_Smooth:            result = state_ptr->is_polygon_smooth_enabled;                       break;
        case OpenGL::Capability::Primitive_Restart:         result = state_ptr->is_primitive_restart_enabled;                    break;
        case OpenGL::Capability::Program_Point_Size:        result = state_ptr->is_program_point_size_enabled;                   break;
        case OpenGL::Capability::Sample_Alpha_To_Coverage:  result = state_ptr->is_sample_alpha_to_coverage_enabled;             break;
        case OpenGL::Capability::Sample_Alpha_To_One:       result = state_ptr->is_sample_alpha_to_one_enabled;                  break;
        case OpenGL::Capability::Sample_Coverage:           result = state_ptr->is_sample_coverage_enabled;                      break;
        case OpenGL::Capability::Scissor_Test:              result = state_ptr->is_scissor_test_enabled;                         break;
        case OpenGL::Capability::Stencil_Test:              result = state_ptr->is_stencil_test_enabled;                         break;
        case OpenGL::Capability::Texture_Cube_Map_Seamless: result = state_ptr->is_texture_cube_map_seamless_enabled;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

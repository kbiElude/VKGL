/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/gl_limits.h"

OpenGL::GLLimits::GLLimits()
{
    /* todo */

    m_aliased_line_width_range[0]                   = 0;
    m_aliased_line_width_range[1]                   = 0;
    m_max_3d_texture_size                           = 0;
    m_max_array_texture_layers                      = 0;
    m_max_clip_distances                            = 0;
    m_max_color_attachments                         = 0;
    m_max_color_texture_samples                     = 0;
    m_max_combined_fragment_uniform_components      = 0;
    m_max_combined_geometry_uniform_components      = 0;
    m_max_combined_texture_image_units              = 0;
    m_max_combined_uniform_blocks                   = 0;
    m_max_combined_vertex_uniform_components        = 0;
    m_max_cube_map_texture_size                     = 0;
    m_max_depth_texture_samples                     = 0;
    m_max_draw_buffers                              = 0;
    m_max_elements_indices                          = 0;
    m_max_elements_vertices                         = 0;
    m_max_fragment_input_components                 = 0;
    m_max_fragment_uniform_blocks                   = 0;
    m_max_fragment_uniform_components               = 0;
    m_max_geometry_input_components                 = 0;
    m_max_geometry_output_components                = 0;
    m_max_geometry_output_vertices                  = 0;
    m_max_geometry_texture_image_units              = 0;
    m_max_geometry_total_output_components          = 0;
    m_max_geometry_uniform_blocks                   = 0;
    m_max_geometry_uniform_components               = 0;
    m_max_integer_samples                           = 0;
    m_max_program_texel_offset                      = 0;
    m_max_rectangle_texture_size                    = 0;
    m_max_renderbuffer_size                         = 0;
    m_max_sample_mask_words                         = 0;
    m_max_samples                                   = 0;
    m_max_server_wait_timeout                       = 0;
    m_max_texture_buffer_size                       = 0;
    m_max_texture_image_units                       = 0;
    m_max_texture_lod_bias                          = 0;
    m_max_texture_size                              = 0;
    m_max_transform_feedback_buffers                = 0;
    m_max_transform_feedback_interleaved_components = 0;
    m_max_transform_feedback_separate_attribs       = 0;
    m_max_transform_feedback_separate_components    = 0;
    m_max_uniform_block_size                        = 0;
    m_max_uniform_buffer_bindings                   = 0;
    m_max_varying_components                        = 0;
    m_max_vertex_attribs                            = 0;
    m_max_vertex_output_components                  = 0;
    m_max_vertex_texture_image_units                = 0;
    m_max_vertex_uniform_blocks                     = 0;
    m_max_vertex_uniform_components                 = 0;
    m_max_viewport_dims[0]                          = 0;
    m_max_viewport_dims[1]                          = 0;
    m_min_program_texel_offset                      = 0;
    m_point_fade_threshold_size                     = 0.0f;
    m_point_size_granularity                        = 0;
    m_point_size_range[0]                           = 0;
    m_point_size_range[1]                           = 0;
    m_query_counter_bits                            = 0;
    m_smooth_line_width_granularity                 = 0;
    m_smooth_line_width_range[0]                    = 0;
    m_smooth_line_width_range[1]                    = 0;
    m_subpixel_bits                                 = 0;
    m_uniform_buffer_offset_alignment               = 0;

    m_prop_map =
    {
        /* NOTE: This must stay in sync with OpenGL::Utils::is_context_property_gl_limit() ! */
        {OpenGL::ContextProperty::Aliased_Line_Width_Range,                      PropertyData(OpenGL::GetSetArgumentType::Float,        2, m_aliased_line_width_range)},
        {OpenGL::ContextProperty::Max_3D_Texture_Size,                           PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_3d_texture_size)},
        {OpenGL::ContextProperty::Max_Array_Texture_Layers,                      PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_array_texture_layers)},
        {OpenGL::ContextProperty::Max_Clip_Distances,                            PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_clip_distances)},
        {OpenGL::ContextProperty::Max_Color_Attachments,                         PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_color_attachments)},
        {OpenGL::ContextProperty::Max_Color_Texture_Samples,                     PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_color_texture_samples)},
        {OpenGL::ContextProperty::Max_Combined_Fragment_Uniform_Components,      PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_combined_fragment_uniform_components)},
        {OpenGL::ContextProperty::Max_Combined_Geometry_Uniform_Components,      PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_combined_geometry_uniform_components)},
        {OpenGL::ContextProperty::Max_Combined_Texture_Image_Units,              PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_combined_texture_image_units)},
        {OpenGL::ContextProperty::Max_Combined_Vertex_Uniform_Components,        PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_combined_vertex_uniform_components)},
        {OpenGL::ContextProperty::Max_Combined_Uniform_Blocks,                   PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_combined_uniform_blocks)},
        {OpenGL::ContextProperty::Max_Cube_Map_Texture_Size,                     PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_cube_map_texture_size)},
        {OpenGL::ContextProperty::Max_Depth_Texture_Samples,                     PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_depth_texture_samples)},
        {OpenGL::ContextProperty::Max_Draw_Buffers,                              PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_draw_buffers)},
        {OpenGL::ContextProperty::Max_Elements_Indices,                          PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_elements_indices)},
        {OpenGL::ContextProperty::Max_Elements_Vertices,                         PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_elements_vertices)},
        {OpenGL::ContextProperty::Max_Fragment_Input_Components,                 PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_fragment_input_components)},
        {OpenGL::ContextProperty::Max_Fragment_Uniform_Blocks,                   PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_fragment_uniform_blocks)},
        {OpenGL::ContextProperty::Max_Fragment_Uniform_Components,               PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_fragment_uniform_components)},
        {OpenGL::ContextProperty::Max_Geometry_Input_Components,                 PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_input_components)},
        {OpenGL::ContextProperty::Max_Geometry_Output_Components,                PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_output_components)},
        {OpenGL::ContextProperty::Max_Geometry_Output_Vertices,                  PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_output_vertices)},
        {OpenGL::ContextProperty::Max_Geometry_Texture_Image_Units,              PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_texture_image_units)},
        {OpenGL::ContextProperty::Max_Geometry_Total_Output_Components,          PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_total_output_components)},
        {OpenGL::ContextProperty::Max_Geometry_Uniform_Blocks,                   PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_uniform_blocks)},
        {OpenGL::ContextProperty::Max_Geometry_Uniform_Components,               PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_geometry_uniform_components)},
        {OpenGL::ContextProperty::Max_Integer_Samples,                           PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_integer_samples)},
        {OpenGL::ContextProperty::Max_Program_Texel_Offset,                      PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_program_texel_offset)},
        {OpenGL::ContextProperty::Max_Rectangle_Texture_Size,                    PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_rectangle_texture_size)},
        {OpenGL::ContextProperty::Max_Renderbuffer_Size,                         PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_renderbuffer_size)},
        {OpenGL::ContextProperty::Max_Sample_Mask_Words,                         PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_sample_mask_words)},
        {OpenGL::ContextProperty::Max_Samples,                                   PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_samples)},
        {OpenGL::ContextProperty::Max_Server_Wait_Timeout,                       PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_server_wait_timeout)},
        {OpenGL::ContextProperty::Max_Texture_Buffer_Size,                       PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_texture_buffer_size)},
        {OpenGL::ContextProperty::Max_Texture_Image_Units,                       PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_texture_image_units)},
        {OpenGL::ContextProperty::Max_Texture_LOD_Bias,                          PropertyData(OpenGL::GetSetArgumentType::Float,        1, &m_max_texture_lod_bias)},
        {OpenGL::ContextProperty::Max_Texture_Size,                              PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_texture_size)},
        {OpenGL::ContextProperty::Max_Transform_Feedback_Buffers,                PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_transform_feedback_buffers)},
        {OpenGL::ContextProperty::Max_Transform_Feedback_Interleaved_Components, PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_transform_feedback_interleaved_components)},
        {OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Attribs,       PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_transform_feedback_separate_attribs)},
        {OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Components,    PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_transform_feedback_separate_components)},
        {OpenGL::ContextProperty::Max_Uniform_Block_Size,                        PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_uniform_block_size)},
        {OpenGL::ContextProperty::Max_Uniform_Buffer_Bindings,                   PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_uniform_buffer_bindings)},
        {OpenGL::ContextProperty::Max_Varying_Components,                        PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_varying_components)},
        {OpenGL::ContextProperty::Max_Vertex_Attribs,                            PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_vertex_attribs)},
        {OpenGL::ContextProperty::Max_Vertex_Output_Components,                  PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_vertex_output_components)},
        {OpenGL::ContextProperty::Max_Vertex_Texture_Image_Units,                PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_vertex_texture_image_units)},
        {OpenGL::ContextProperty::Max_Vertex_Uniform_Blocks,                     PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_vertex_uniform_blocks)},
        {OpenGL::ContextProperty::Max_Vertex_Uniform_Components,                 PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_max_vertex_uniform_components)},
        {OpenGL::ContextProperty::Max_Viewport_Dims,                             PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 2, m_max_viewport_dims)},
        {OpenGL::ContextProperty::Min_Program_Texel_Offset,                      PropertyData(OpenGL::GetSetArgumentType::Int,          1, &m_min_program_texel_offset)},
        {OpenGL::ContextProperty::Point_Fade_Threshold_Size,                     PropertyData(OpenGL::GetSetArgumentType::Float,        1, &m_point_fade_threshold_size)},
        {OpenGL::ContextProperty::Point_Size_Granularity,                        PropertyData(OpenGL::GetSetArgumentType::Float,        1, &m_point_size_granularity)},
        {OpenGL::ContextProperty::Point_Size_Range,                              PropertyData(OpenGL::GetSetArgumentType::Float,        2, m_point_size_range)},
        {OpenGL::ContextProperty::Query_Counter_Bits,                            PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_query_counter_bits)},
        {OpenGL::ContextProperty::Smooth_Line_Width_Granularity,                 PropertyData(OpenGL::GetSetArgumentType::Float,        1, &m_smooth_line_width_granularity)},
        {OpenGL::ContextProperty::Smooth_Line_Width_Range,                       PropertyData(OpenGL::GetSetArgumentType::Float,        2, m_smooth_line_width_range)},
        {OpenGL::ContextProperty::Subpixel_Bits,                                 PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_subpixel_bits)},
        {OpenGL::ContextProperty::Uniform_Buffer_Offset_Alignment,               PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_uniform_buffer_offset_alignment)},

    };
}

OpenGL::GLLimits::~GLLimits()
{
    vkgl_not_implemented();
}

void OpenGL::GLLimits::get_parameter(const OpenGL::ContextProperty&    in_pname,
                                     const OpenGL::GetSetArgumentType& in_arg_type,
                                     void*                             out_arg_value_ptr) const
{
    vkgl_not_implemented();
}
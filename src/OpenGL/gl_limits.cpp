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
    m_max_combined_vertex_uniform_components        = 0;
    m_max_combined_uniform_blocks                   = 0;
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
    m_point_size_granularity                        = 0;
    m_point_size_range[0]                           = 0;
    m_point_size_range[1]                           = 0;
    m_query_counter_bits                            = 0;
    m_smooth_line_width_granularity                 = 0;
    m_smooth_line_width_range[0]                    = 0;
    m_smooth_line_width_range[1]                    = 0;
    m_subpixel_bits                                 = 0;
    m_uniform_buffer_offset_alignment               = 0;
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
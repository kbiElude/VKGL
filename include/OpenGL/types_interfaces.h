/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_INTERFACES_H
#define VKGL_TYPES_INTERFACES_H

#include "OpenGL/types.h"

namespace OpenGL
{
    class IContext
    {
    public:
        virtual ~IContext()
        {
            /* Stub */
        }

        virtual const OpenGL::DispatchTable*    get_dispatch_table      () const = 0;
        virtual const std::vector<std::string>& get_supported_extensions() const = 0;
    };

    class IGLConstants
    {
    public:
        virtual ~IGLConstants()
        {
            /* Stub */
        }

        virtual const uint32_t& get_context_flags           () const = 0;
        virtual const uint32_t& get_context_profile_mask    () const = 0;
        virtual const char*     get_extensions              () const = 0;
        virtual const uint32_t& get_major_version           () const = 0;
        virtual const uint32_t& get_minor_version           () const = 0;
        virtual const char*     get_renderer                () const = 0;
        virtual const char*     get_shading_language_version() const = 0;
        virtual const char*     get_vendor                  () const = 0;
    };

    class IGLLimits
    {
    public:
        virtual ~IGLLimits()
        {
            /* Stub */
        }

        virtual const float*                               get_aliased_line_width_range_vec2                () const = 0;
        virtual const std::vector<OpenGL::InternalFormat>& get_compressed_texture_formats                   () const = 0;
        virtual uint32_t                                   get_max_3d_texture_size                          () const = 0;
        virtual uint32_t                                   get_max_array_texture_layers                     () const = 0;
        virtual uint32_t                                   get_max_clip_distances                           () const = 0;
        virtual uint32_t                                   get_max_color_attachments                        () const = 0;
        virtual uint32_t                                   get_max_color_texture_samples                    () const = 0;
        virtual uint32_t                                   get_max_combined_fragment_uniform_components     () const = 0;
        virtual uint32_t                                   get_max_combined_geometry_uniform_components     () const = 0;
        virtual uint32_t                                   get_max_combined_texture_image_units             () const = 0;
        virtual uint32_t                                   get_max_combined_vertex_uniform_components       () const = 0;
        virtual uint32_t                                   get_max_combined_uniform_blocks                  () const = 0;
        virtual uint32_t                                   get_max_cube_map_texture_size                    () const = 0;
        virtual uint32_t                                   get_max_depth_texture_samples                    () const = 0;
        virtual uint32_t                                   get_max_draw_buffers                             () const = 0;
        virtual uint32_t                                   get_max_elements_indices                         () const = 0;
        virtual uint32_t                                   get_max_elements_vertices                        () const = 0;
        virtual uint32_t                                   get_max_fragment_input_components                () const = 0;
        virtual uint32_t                                   get_max_fragment_uniform_blocks                  () const = 0;
        virtual uint32_t                                   get_max_fragment_uniform_components              () const = 0;
        virtual uint32_t                                   get_max_geometry_input_components                () const = 0;
        virtual uint32_t                                   get_max_geometry_output_components               () const = 0;
        virtual uint32_t                                   get_max_geometry_output_vertices                 () const = 0;
        virtual uint32_t                                   get_max_geometry_texture_image_units             () const = 0;
        virtual uint32_t                                   get_max_geometry_total_output_components         () const = 0;
        virtual uint32_t                                   get_max_geometry_uniform_blocks                  () const = 0;
        virtual uint32_t                                   get_max_integer_samples                          () const = 0;
        virtual uint32_t                                   get_max_program_texel_offset                     () const = 0;
        virtual uint32_t                                   get_max_rectangle_texture_size                   () const = 0;
        virtual uint32_t                                   get_max_renderbuffer_size                        () const = 0;
        virtual uint32_t                                   get_max_sample_mask_words                        () const = 0;
        virtual uint32_t                                   get_max_samples                                  () const = 0;
        virtual uint32_t                                   get_max_server_wait_timeout                      () const = 0;
        virtual uint32_t                                   get_max_texture_buffer_size                      () const = 0;
        virtual uint32_t                                   get_max_texture_image_units                      () const = 0;
        virtual float                                      get_max_texture_lod_bias                         () const = 0;
        virtual uint32_t                                   get_max_texture_size                             () const = 0;
        virtual uint32_t                                   get_max_transform_feedback_buffers               () const = 0;
        virtual uint32_t                                   get_max_transform_feedback_interleaved_components() const = 0;
        virtual uint32_t                                   get_max_transform_feedback_separate_attribs      () const = 0;
        virtual uint32_t                                   get_max_transform_feedback_separate_components   () const = 0;
        virtual uint32_t                                   get_max_uniform_block_size                       () const = 0;
        virtual uint32_t                                   get_max_uniform_buffer_bindings                  () const = 0;
        virtual uint32_t                                   get_max_varying_components                       () const = 0;
        virtual uint32_t                                   get_max_vertex_attribs                           () const = 0;
        virtual uint32_t                                   get_max_vertex_output_components                 () const = 0;
        virtual uint32_t                                   get_max_vertex_texture_image_units               () const = 0;
        virtual uint32_t                                   get_max_vertex_uniform_blocks                    () const = 0;
        virtual uint32_t                                   get_max_vertex_uniform_components                () const = 0;
        virtual const uint32_t*                            get_max_viewport_dims_uvec2                      () const = 0;
        virtual int32_t                                    get_min_program_texel_offset                     () const = 0;
        virtual float                                      get_point_size_granularity                       () const = 0;
        virtual const float*                               get_point_size_range_vec2                        () const = 0;
        virtual uint32_t                                   get_query_counter_bits                           () const = 0;
        virtual float                                      get_smooth_line_width_granularity                () const = 0;
        virtual const float*                               get_smooth_line_width_range_vec2                 () const = 0;
        virtual uint32_t                                   get_subpixel_bits                                () const = 0;
        virtual uint32_t                                   get_uniform_buffer_offset_alignment              () const = 0;
    };
};

#endif /* VKGL_TYPES_INTERFACES_H */
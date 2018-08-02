#ifndef VKGL_GL_LIMITS_H
#define VKGL_GL_LIMITS_H

#include "OpenGL/types.h"

namespace VKGL
{
    class GLLimits : public VKGL::IGLLimits
    {
    public:
         GLLimits();
        ~GLLimits();

        void get_parameter(const VKGL::ContextProperty&    in_pname,
                           const VKGL::GetSetArgumentType& in_arg_type,
                           void*                           out_arg_value_ptr) const;

        /* IGLLimits interface impl */

        const float* get_aliased_line_width_range_vec2() const final
        {
            return m_aliased_line_width_range;
        }

        const std::vector<VKGL::InternalFormat>& get_compressed_texture_formats() const final
        {
            return m_compressed_texture_formats;
        }

        uint32_t get_max_3d_texture_size() const final
        {
            return m_max_3d_texture_size;
        }

        uint32_t get_max_array_texture_layers() const final
        {
            return m_max_array_texture_layers;
        }

        uint32_t get_max_clip_distances() const final
        {
            return m_max_clip_distances;
        }

        uint32_t get_max_color_attachments() const final
        {
            return m_max_color_attachments;
        }

        uint32_t get_max_color_texture_samples() const final
        {
            return m_max_color_texture_samples;
        }

        uint32_t get_max_combined_fragment_uniform_components() const final
        {
            return m_max_combined_fragment_uniform_components;
        }

        uint32_t get_max_combined_geometry_uniform_components() const final
        {
            return m_max_combined_geometry_uniform_components;
        }

        uint32_t get_max_combined_texture_image_units() const final
        {
            return m_max_combined_texture_image_units;
        }

        uint32_t get_max_combined_vertex_uniform_components() const final
        {
            return m_max_combined_vertex_uniform_components;
        }

        uint32_t get_max_combined_uniform_blocks() const final
        {
            return m_max_combined_uniform_blocks;
        }

        uint32_t get_max_cube_map_texture_size() const final
        {
            return m_max_cube_map_texture_size;
        }

        uint32_t get_max_depth_texture_samples() const final
        {
            return m_max_depth_texture_samples;
        }

        uint32_t get_max_draw_buffers() const final
        {
            return m_max_draw_buffers;
        }

        uint32_t get_max_elements_indices() const final
        {
            return m_max_elements_indices;
        }

        uint32_t get_max_elements_vertices() const final
        {
            return m_max_elements_vertices;
        }

        uint32_t get_max_fragment_input_components() const final
        {
            return m_max_fragment_input_components;
        }

        uint32_t get_max_fragment_uniform_blocks() const final
        {
            return m_max_fragment_uniform_blocks;
        }

        uint32_t get_max_fragment_uniform_components() const final
        {
            return m_max_fragment_uniform_components;
        }

        uint32_t get_max_geometry_input_components() const final
        {
            return m_max_geometry_input_components;
        }

        uint32_t get_max_geometry_output_components() const final
        {
            return m_max_geometry_output_components;
        }

        uint32_t get_max_geometry_output_vertices() const final
        {
            return m_max_geometry_output_vertices;
        }

        uint32_t get_max_geometry_texture_image_units() const final
        {
            return m_max_geometry_texture_image_units;
        }

        uint32_t get_max_geometry_total_output_components() const final
        {
            return m_max_geometry_total_output_components;
        }

        uint32_t get_max_geometry_uniform_blocks() const final
        {
            return m_max_geometry_uniform_blocks;
        }

        uint32_t get_max_integer_samples() const final
        {
            return m_max_integer_samples;
        }

        uint32_t get_max_program_texel_offset() const final
        {
            return m_max_program_texel_offset;
        }

        uint32_t get_max_rectangle_texture_size() const final
        {
            return m_max_rectangle_texture_size;
        }

        uint32_t get_max_renderbuffer_size() const final
        {
            return m_max_renderbuffer_size;
        }

        uint32_t get_max_sample_mask_words() const final
        {
            return m_max_sample_mask_words;
        }

        uint32_t get_max_samples() const final
        {
            return m_max_samples;
        }

        uint32_t get_max_server_wait_timeout() const final
        {
            return m_max_server_wait_timeout;
        }

        uint32_t get_max_texture_buffer_size() const final
        {
            return m_max_texture_buffer_size;
        }

        uint32_t get_max_texture_image_units() const final
        {
            return m_max_texture_image_units;
        }

        float get_max_texture_lod_bias() const final
        {
            return m_max_texture_lod_bias;
        }

        uint32_t get_max_texture_size() const final
        {
            return m_max_texture_size;
        }

        uint32_t get_max_transform_feedback_interleaved_components() const final
        {
            return m_max_transform_feedback_interleaved_components;
        }

        uint32_t get_max_transform_feedback_separate_attribs() const final
        {
            return m_max_transform_feedback_separate_attribs;
        }

        uint32_t get_max_transform_feedback_separate_components() const final
        {
            return m_max_transform_feedback_separate_components;
        }

        uint32_t get_max_uniform_block_size() const final
        {
            return m_max_uniform_block_size;
        }

        uint32_t get_max_uniform_buffer_bindings() const final
        {
            return m_max_uniform_buffer_bindings;
        }

        uint32_t get_max_varying_components() const final
        {
            return m_max_varying_components;
        }

        uint32_t get_max_vertex_attribs() const final
        {
            return m_max_vertex_attribs;
        }

        uint32_t get_max_vertex_output_components() const final
        {
            return m_max_vertex_output_components;
        }

        uint32_t get_max_vertex_texture_image_units() const final
        {
            return m_max_vertex_texture_image_units;
        }

        uint32_t get_max_vertex_uniform_blocks() const final
        {
            return m_max_vertex_uniform_blocks;
        }

        uint32_t get_max_vertex_uniform_components() const final
        {
            return m_max_vertex_uniform_components;
        }

        const uint32_t* get_max_viewport_dims_uvec2() const final
        {
            return m_max_viewport_dims;
        }

        int32_t get_min_program_texel_offset() const final
        {
            return m_min_program_texel_offset;
        }

        float get_point_size_granularity() const final
        {
            return m_point_size_granularity;
        }

        const float* get_point_size_range_vec2() const final
        {
            return m_point_size_range;
        }

        uint32_t get_query_counter_bits() const final
        {
            return m_query_counter_bits;
        }

        float get_smooth_line_width_granularity() const final
        {
            return m_smooth_line_width_granularity;
        }

        const float* get_smooth_line_width_range_vec2() const final
        {
            return m_smooth_line_width_range;
        }

        uint32_t get_subpixel_bits() const final
        {
            return m_subpixel_bits;
        }

        uint32_t get_uniform_buffer_offset_alignment() const final
        {
            return m_uniform_buffer_offset_alignment;
        }

    private:
        /* Private functions */

        /* Private variables */
        float                             m_aliased_line_width_range[2];
        std::vector<VKGL::InternalFormat> m_compressed_texture_formats;
        uint32_t                          m_max_3d_texture_size;
        uint32_t                          m_max_array_texture_layers;
        uint32_t                          m_max_clip_distances;
        uint32_t                          m_max_color_attachments;
        uint32_t                          m_max_color_texture_samples;
        uint32_t                          m_max_combined_fragment_uniform_components;
        uint32_t                          m_max_combined_geometry_uniform_components;
        uint32_t                          m_max_combined_texture_image_units;
        uint32_t                          m_max_combined_vertex_uniform_components;
        uint32_t                          m_max_combined_uniform_blocks;
        uint32_t                          m_max_cube_map_texture_size;
        uint32_t                          m_max_depth_texture_samples;
        uint32_t                          m_max_draw_buffers;
        uint32_t                          m_max_elements_indices;
        uint32_t                          m_max_elements_vertices;
        uint32_t                          m_max_fragment_input_components;
        uint32_t                          m_max_fragment_uniform_blocks;
        uint32_t                          m_max_fragment_uniform_components;
        uint32_t                          m_max_geometry_input_components;
        uint32_t                          m_max_geometry_output_components;
        uint32_t                          m_max_geometry_output_vertices;
        uint32_t                          m_max_geometry_texture_image_units;
        uint32_t                          m_max_geometry_total_output_components;
        uint32_t                          m_max_geometry_uniform_blocks;
        uint32_t                          m_max_integer_samples;
        uint32_t                          m_max_program_texel_offset;
        uint32_t                          m_max_rectangle_texture_size;
        uint32_t                          m_max_renderbuffer_size;
        uint32_t                          m_max_sample_mask_words;
        uint32_t                          m_max_samples;
        uint32_t                          m_max_server_wait_timeout;
        uint32_t                          m_max_texture_buffer_size;
        uint32_t                          m_max_texture_image_units;
        float                             m_max_texture_lod_bias;
        uint32_t                          m_max_texture_size;
        uint32_t                          m_max_transform_feedback_interleaved_components;
        uint32_t                          m_max_transform_feedback_separate_attribs;
        uint32_t                          m_max_transform_feedback_separate_components;
        uint32_t                          m_max_uniform_block_size;
        uint32_t                          m_max_uniform_buffer_bindings;
        uint32_t                          m_max_varying_components;
        uint32_t                          m_max_vertex_attribs;
        uint32_t                          m_max_vertex_output_components;
        uint32_t                          m_max_vertex_texture_image_units;
        uint32_t                          m_max_vertex_uniform_blocks;
        uint32_t                          m_max_vertex_uniform_components;
        uint32_t                          m_max_viewport_dims[2];
        int32_t                           m_min_program_texel_offset;
        float                             m_point_size_granularity;
        float                             m_point_size_range[2];
        uint32_t                          m_query_counter_bits;
        float                             m_smooth_line_width_granularity;
        float                             m_smooth_line_width_range[2];
        uint32_t                          m_subpixel_bits;
        uint32_t                          m_uniform_buffer_offset_alignment;
    };

    typedef std::unique_ptr<GLLimits> GLLimitsUniquePtr;
}

#endif /* VKGL_GL_LIMITS_H */
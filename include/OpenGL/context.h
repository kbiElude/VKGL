/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_CONTEXT_H
#define VKGL_CONTEXT_H

#include "OpenGL/gl_limits.h"
#include "OpenGL/gl_state_manager.h"
#include "OpenGL/gl_texture_manager.h"
#include "OpenGL/scheduler.h"

namespace OpenGL
{
    typedef std::unique_ptr<OpenGL::Context> ContextUniquePtr;

    class Context
    {
    public:
        /* Public functions */

        static ContextUniquePtr create();

        ~Context();

        void gen_buffers (const uint32_t& in_n,
                          uint32_t*       out_ids_ptr);
        void gen_queries (const uint32_t& in_n,
                          uint32_t*       out_ids_ptr);
        void gen_textures(const GLsizei&  in_n,
                          GLuint*         out_ids_ptr);

        void delete_buffers (const GLsizei&  in_n,
                             const uint32_t* in_ids_ptr);
        void delete_queries (const GLsizei&  in_n,
                             const uint32_t* in_ids_ptr);
        void delete_textures(const GLsizei&  in_n,
                             const GLuint*   in_ids_ptr);

        void get_buffer_property(const OpenGL::BufferTarget&          in_target,
                                 const OpenGL::BufferProperty&        in_pname,
                                 const OpenGL::GetSetArgumentType&    in_arg_type,
                                 const uint32_t&                      in_n_args,
                                 void*                                out_result_ptr);
        void get_buffer_pointerv(const OpenGL::BufferTarget&          in_target,
                                 const OpenGL::BufferPointerProperty& in_pname,
                                 void**                               out_params_ptr);
        bool is_buffer          (const GLuint&                        in_id);

        void get_query_property       (const uint32_t&                    in_id,
                                       const OpenGL::QueryProperty&       in_pname,
                                       const OpenGL::GetSetArgumentType&  in_arg_type,
                                       const uint32_t&                    in_n_args,
                                       void*                              out_result_ptr);
        void get_query_target_property(const OpenGL::QueryTarget&         in_target,
                                       const OpenGL::QueryTargetProperty& in_pname,
                                       int32_t*                           out_params_ptr);
        bool is_query                 (const GLuint&                      in_id);

        void get_texture_level_parameter(const OpenGL::TextureTarget&        in_target,
                                         const int32_t&                      in_level,
                                         const OpenGL::TextureLevelProperty& in_pname,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         void*                               out_params_ptr) const;
        void get_texture_parameter      (const OpenGL::TextureTarget&        in_target,
                                         const OpenGL::TextureProperty&      in_property,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         void*                               out_arg_value_ptr) const;
        bool is_texture                 (const GLuint&                       in_texture);

        OpenGL::ErrorCode get_error    ();
        void              get_parameter(const OpenGL::ContextProperty&      in_pname,
                                        const OpenGL::GetSetArgumentType&   in_arg_type,
                                        void*                               out_arg_value_ptr) const;
        bool              is_enabled   (const OpenGL::Capability&           in_capability) const;

        void disable                     (const OpenGL::Capability&           in_capability);
        void enable                      (const OpenGL::Capability&           in_capability);
        void set_active_texture          (const uint32_t&                     in_n_texture_unit);
        void set_blend_color             (const float&                        in_red,
                                          const float&                        in_green,
                                          const float&                        in_blue,
                                          const float&                        in_alpha);
        void set_blend_equation          (const OpenGL::BlendEquation&        in_blend_equation);
        void set_blend_functions         (const OpenGL::BlendFunction&        in_src_rgba_function,
                                          const OpenGL::BlendFunction&        in_dst_rgba_function);
        void set_blend_functions_separate(const OpenGL::BlendFunction&        in_src_rgb_function,
                                          const OpenGL::BlendFunction&        in_dst_rgb_function,
                                          const OpenGL::BlendFunction&        in_src_alpha_function,
                                          const OpenGL::BlendFunction&        in_dst_alpha_function);
        void set_clear_color_value       (const float&                        in_red,
                                          const float&                        in_green,
                                          const float&                        in_blue,
                                          const float&                        in_alpha);
        void set_clear_depth_value       (const double&                       in_value);
        void set_clear_stencil_value     (const int&                          in_value);
        void set_color_mask              (const bool&                         in_red,
                                          const bool&                         in_green,
                                          const bool&                         in_blue,
                                          const bool&                         in_alpha);
        void set_cull_mode               (const OpenGL::CullMode&             in_mode);
        void set_depth_function          (const OpenGL::DepthFunction&        in_function);
        void set_depth_mask              (const bool&                         in_flag);
        void set_depth_range             (const double&                       in_near,
                                          const double&                       in_far);
        void set_draw_buffer             (const OpenGL::DrawBuffer&           in_draw_buffer);
        void set_front_face_orientation  (const OpenGL::FrontFaceOrientation& in_orientation);
        void set_hint                    (const OpenGL::HintTarget&           in_target,
                                          const OpenGL::HintMode&             in_mode);
        void set_line_width              (const float&                        in_width);
        void set_logic_op                (const OpenGL::LogicOpMode&          in_mode);
        void set_pixel_store_property    (const OpenGL::PixelStoreProperty&   in_property,
                                          const OpenGL::GetSetArgumentType&   in_arg_type,
                                          const void*                         in_arg_value_ptr);
        void set_point_property          (const OpenGL::PointProperty&        in_property,
                                          const OpenGL::GetSetArgumentType&   in_arg_type,
                                          const void*                         in_arg_value_ptr);
        void set_point_size              (const float&                        in_size);
        void set_polygon_mode            (const OpenGL::PolygonMode&          in_mode);
        void set_polygon_offset          (const GLfloat&                      in_factor,
                                          const GLfloat&                      in_units);
        void set_read_buffer             (const OpenGL::ReadBuffer&           in_read_buffer);
        void set_sample_coverage         (const GLfloat&                      in_value,
                                          const GLboolean&                    in_invert);
        void set_scissor                 (const int32_t&                      in_x,
                                          const int32_t&                      in_y,
                                          const size_t&                       in_width,
                                          const size_t&                       in_height);
        void set_stencil_function        (const OpenGL::StencilFunction&      in_func,
                                          const int32_t&                      in_ref,
                                          const uint32_t&                     in_mask);
        void set_stencil_mask            (const uint32_t&                     in_mask);
        void set_stencil_operations      (const OpenGL::StencilOperation&     in_fail,
                                          const OpenGL::StencilOperation&     in_zfail,
                                          const OpenGL::StencilOperation&     in_zpass);
        void set_texture_parameter       (const OpenGL::TextureTarget&        in_target,
                                          const OpenGL::TextureProperty&      in_property,
                                          const OpenGL::GetSetArgumentType&   in_arg_type,
                                          const void*                         in_arg_value_ptr);
        void set_viewport                (const int32_t&                      in_x,
                                          const int32_t&                      in_y,
                                          const size_t&                       in_width,
                                          const size_t&                       in_height);

        void  begin_query                (const OpenGL::QueryTarget&       in_target,
                                          const uint32_t&                  in_id);
        void  bind_buffer                (const OpenGL::BufferTarget&      in_target,
                                          const uint32_t&                  in_id);
        void  bind_texture               (const OpenGL::TextureTarget&     in_target,
                                          const uint32_t&                  in_texture);
        void  buffer_data                (const OpenGL::BufferTarget&      in_target,
                                          const GLsizeiptr&                in_size,
                                          const void*                      in_data_ptr,
                                          const OpenGL::BufferUsage&       in_usage);
        void  buffer_sub_data            (const OpenGL::BufferTarget&      in_target,
                                          const GLintptr&                  in_offset,
                                          const GLsizeiptr&                in_size,
                                          const void*                      in_data_ptr);
        void  clear                      (const OpenGL::ClearBufferBits&   in_buffers_to_clear);
        void  compressed_tex_image_1d    (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLsizei                    in_width,
                                          const GLint                      in_border,
                                          const GLsizei                    in_image_size,
                                          const void*                      in_data);
        void  compressed_tex_image_2d    (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLint&                     in_border,
                                          const GLsizei&                   in_image_size,
                                          const void*                      in_data);
        void  compressed_tex_image_3d    (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLsizei&                   in_depth,
                                          const GLint&                     in_border,
                                          const GLsizei&                   in_image_size,
                                          const void*                      in_data);
        void  compressed_tex_sub_image_1d(const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLsizei&                   in_width,
                                          const OpenGL::PixelFormat&       in_format,
                                          const GLsizei&                   in_image_size,
                                          const void*                      in_data);
        void  compressed_tex_sub_image_2d(const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_yoffset,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const OpenGL::PixelFormat&       in_format,
                                          const GLsizei&                   in_image_size,
                                          const void*                      in_data);
        void  compressed_tex_sub_image_3d(const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_yoffset,
                                          const GLint&                     in_zoffset,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLsizei&                   in_depth,
                                          const OpenGL::PixelFormat&       in_format,
                                          const GLsizei&                   in_image_size,
                                          const void*                      in_data);
        void  copy_tex_image_1d          (const OpenGL::TextureTarget&     in_target,
                                          const GLint                      in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLint&                     in_x,
                                          const GLint&                     in_y,
                                          const GLsizei&                   in_width,
                                          const GLint&                     in_border);
        void  copy_tex_image_2d          (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLint&                     in_x,
                                          const GLint&                     in_y,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLint&                     in_border);
        void  copy_tex_sub_image_1d      (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_x,
                                          const GLint&                     in_y,
                                          const GLsizei&                   in_width);
        void  copy_tex_sub_image_2d      (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_yoffset,
                                          const GLint&                     in_x,
                                          const GLint&                     in_y,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height);
        void  copy_tex_sub_image_3d      (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_yoffset,
                                          const GLint&                     in_zoffset,
                                          const GLint&                     in_x,
                                          const GLint&                     in_y,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height);
        void  draw_arrays                (const OpenGL::DrawCallMode&      in_mode,
                                          const GLint&                     in_first,
                                          const GLsizei&                   in_count);
        void  draw_elements              (const OpenGL::DrawCallMode&      in_mode,
                                          const GLsizei&                   in_count,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void*                      in_indices);
        void  draw_range_elements        (const OpenGL::DrawCallMode&      in_mode,
                                          const GLuint&                    in_start,
                                          const GLuint&                    in_end,
                                          const GLsizei&                   in_count,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void*                      in_indices);
        void  end_query                  (const OpenGL::QueryTarget&       in_target);
        void  finish                     ();
        void  flush                      ();
        void  get_buffer_sub_data        (const OpenGL::BufferTarget&      in_target,
                                          const GLintptr&                  in_offset,
                                          const GLsizeiptr&                in_size,
                                          void*                            out_data_ptr);
        void  get_compressed_tex_image   (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          void*                            in_img);
        void  get_texture_image          (const OpenGL::TextureTarget&     in_target,
                                          const uint32_t&                  in_level,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          void*                            out_pixels_ptr);
        void* map_buffer                 (const OpenGL::BufferTarget&      in_target,
                                          const OpenGL::BufferAccess&      in_access);
        void  multi_draw_arrays          (const OpenGL::DrawCallMode&      in_mode,
                                          const GLint*                     in_first_ptr,
                                          const GLsizei*                   in_count_ptr,
                                          const GLsizei&                   in_drawcount);
        void  multi_draw_elements        (const OpenGL::DrawCallMode&      in_mode,
                                          const GLsizei*                   in_count_ptr,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void* const*               in_indices_ptr,
                                          const GLsizei&                   in_drawcount);
        void  read_pixels                (const int32_t&                   in_x,
                                          const int32_t&                   in_y,
                                          const size_t&                    in_width,
                                          const size_t&                    in_height,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          void*                            out_pixels_ptr);
        void  tex_image_1d               (const OpenGL::TextureTarget&     in_target,
                                          const int32_t&                   in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const int32_t&                   in_width,
                                          const int32_t&                   in_border,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          const void*                      in_pixels_ptr);
        void  tex_image_2d               (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLint&                     in_border,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          const void*                      in_pixels_ptr);
        void  tex_image_3d               (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const OpenGL::InternalFormat&    in_internalformat,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLsizei&                   in_depth,
                                          const GLint&                     in_border,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          const void*                      in_pixels_ptr);
        void  tex_sub_image_1d           (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLsizei&                   in_width,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          const void*                      in_pixels);
        void  tex_sub_image_2d           (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_yoffset,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          const void*                      in_pixels);
        void  tex_sub_image_3d           (const OpenGL::TextureTarget&     in_target,
                                          const GLint&                     in_level,
                                          const GLint&                     in_xoffset,
                                          const GLint&                     in_yoffset,
                                          const GLint&                     in_zoffset,
                                          const GLsizei&                   in_width,
                                          const GLsizei&                   in_height,
                                          const GLsizei&                   in_depth,
                                          const OpenGL::PixelFormat&       in_format,
                                          const OpenGL::PixelType&         in_type,
                                          const void*                      in_pixels);
        bool  unmap_buffer               (const OpenGL::BufferTarget&      in_target);

    private:
        /* Private functions */

        Context();

        bool init();

        /* Private variables */
        GLLimitsUniquePtr         m_gl_limits_ptr;
        GLStateManagerUniquePtr   m_gl_state_manager_ptr;
        GLTextureManagerUniquePtr m_gl_texture_manager_ptr;
        SchedulerUniquePtr        m_scheduler_ptr;
    };
}

#endif /* VKGL_CONTEXT_H */
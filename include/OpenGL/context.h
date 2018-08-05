/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_CONTEXT_H
#define VKGL_CONTEXT_H

#include "OpenGL/gl_limits.h"
#include "OpenGL/gl_state_manager.h"
#include "OpenGL/scheduler.h"

namespace VKGL
{
    typedef std::unique_ptr<VKGL::Context> ContextUniquePtr;

    class Context
    {
    public:
        /* Public functions */

        static ContextUniquePtr create();

        ~Context();

        VKGL::ErrorCode get_error                  ();
        void            get_parameter              (const VKGL::ContextProperty&      in_pname,
                                                    const VKGL::GetSetArgumentType&   in_arg_type,
                                                    void*                             out_arg_value_ptr) const;
        void            get_texture_image          (const VKGL::TextureTarget&        in_target,
                                                    const uint32_t&                   in_level,
                                                    const VKGL::PixelFormat&          in_format,
                                                    const VKGL::PixelType&            in_type,
                                                    void*                             out_pixels_ptr);
        void            get_texture_level_parameter(const VKGL::TextureTarget&        in_target,
                                                    const int32_t&                    in_level,
                                                    const VKGL::TextureLevelProperty& in_pname,
                                                    const VKGL::GetSetArgumentType&   in_arg_type,
                                                    void*                             out_params_ptr) const;
        void            get_texture_parameter      (const VKGL::TextureTarget&        in_target,
                                                    const VKGL::TextureProperty&      in_property,
                                                    const VKGL::GetSetArgumentType&   in_arg_type,
                                                    void*                             out_arg_value_ptr) const;

        void set_blend_functions       (const VKGL::BlendFunction&        in_src_rgba_function,
                                        const VKGL::BlendFunction&        in_dst_rgba_function);
        void set_clear_color_value     (const float&                      in_red,
                                        const float&                      in_green,
                                        const float&                      in_blue,
                                        const float&                      in_alpha);
        void set_clear_depth_value     (const double&                     in_value);
        void set_clear_stencil_value   (const int&                        in_value);
        void set_color_mask            (const bool&                       in_red,
                                        const bool&                       in_green,
                                        const bool&                       in_blue,
                                        const bool&                       in_alpha);
        void set_cull_mode             (const VKGL::CullMode&             in_mode);
        void set_depth_function        (const VKGL::DepthFunction&        in_function);
        void set_depth_mask            (const bool&                       in_flag);
        void set_depth_range           (const double&                     in_near,
                                        const double&                     in_far);
        void set_draw_buffer           (const VKGL::DrawBuffer&           in_draw_buffer);
        void set_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation);
        void set_hint                  (const VKGL::HintTarget&           in_target,
                                        const VKGL::HintMode&             in_mode);
        void set_line_width            (const float&                      in_width);
        void set_logic_op              (const VKGL::LogicOpMode&          in_mode);
        void set_pixel_store_property  (const VKGL::PixelStoreProperty&   in_property,
                                        const VKGL::GetSetArgumentType&   in_arg_type,
                                        const void*                       in_arg_value_ptr);
        void set_point_size            (const float&                      in_size);
        void set_polygon_mode          (const VKGL::PolygonMode&          in_mode);
        void set_polygon_offset        (const GLfloat&                    in_factor,
                                        const GLfloat&                    in_units);
        void set_read_buffer           (const VKGL::ReadBuffer&           in_read_buffer);
        void set_scissor               (const int32_t&                    in_x,
                                        const int32_t&                    in_y,
                                        const size_t&                     in_width,
                                        const size_t&                     in_height);
        void set_stencil_function      (const VKGL::StencilFunction&      in_func,
                                        const int32_t&                    in_ref,
                                        const uint32_t&                   in_mask);
        void set_stencil_mask          (const uint32_t&                   in_mask);
        void set_stencil_operations    (const VKGL::StencilOperation&     in_fail,
                                        const VKGL::StencilOperation&     in_zfail,
                                        const VKGL::StencilOperation&     in_zpass);
        void set_texture_parameter     (const VKGL::TextureTarget&        in_target,
                                        const VKGL::TextureProperty&      in_property,
                                        const VKGL::GetSetArgumentType&   in_arg_type,
                                        const void*                       in_arg_value_ptr);
        void set_viewport              (const int32_t&                    in_x,
                                        const int32_t&                    in_y,
                                        const size_t&                     in_width,
                                        const size_t&                     in_height);

        bool is_enabled(const VKGL::Capability& in_capability) const;

        void bind_texture         (const VKGL::TextureTarget&   in_target,
                                   const GLuint&                in_texture);
        void clear                (const VKGL::ClearBufferBits& in_buffers_to_clear);
        void copy_tex_image_1d    (const VKGL::TextureTarget&   in_target,
                                   const GLint                  in_level,
                                   const VKGL::InternalFormat&  in_internalformat,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width,
                                   const GLint&                 in_border);
        void copy_tex_image_2d    (const VKGL::TextureTarget&   in_target,
                                   const GLint&                 in_level,
                                   const VKGL::InternalFormat&  in_internalformat,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width,
                                   const GLsizei&               in_height,
                                   const GLint&                 in_border);
        void copy_tex_sub_image_1d(const VKGL::TextureTarget&   in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width);
        void copy_tex_sub_image_2d(const VKGL::TextureTarget&   in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLint&                 in_yoffset,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width,
                                   const GLsizei&               in_height);
        void delete_textures      (const GLsizei&               in_n,
                                   const GLuint*                in_textures);
        void disable              (const VKGL::Capability&      in_capability);
        void draw_arrays          (const VKGL::DrawCallMode&    in_mode,
                                   const GLint&                 in_first,
                                   const GLsizei&               in_count);
        void draw_elements        (const VKGL::DrawCallMode&    in_mode,
                                   const GLsizei&               in_count,
                                   const GLenum&                in_type,
                                   const void*                  in_indices);
        void enable               (const VKGL::Capability&      in_capability);
        void finish               ();
        void flush                ();
        void gen_textures         (const GLsizei&               in_n,
                                   GLuint*                      in_textures);
        void get_pointerv         (const VKGL::ContextProperty& in_pname,
                                   void**                       in_params);
        bool is_texture           (const GLuint&                in_texture);
        void read_pixels          (const int32_t&               in_x,
                                   const int32_t&               in_y,
                                   const size_t&                in_width,
                                   const size_t&                in_height,
                                   const VKGL::PixelFormat&     in_format,
                                   const VKGL::PixelType&       in_type,
                                   void*                        out_pixels_ptr);
        void tex_image_1d         (const VKGL::TextureTarget&   in_target,
                                   const int32_t&               in_level,
                                   const VKGL::InternalFormat&  in_internalformat,
                                   const int32_t&               in_width,
                                   const int32_t&               in_border,
                                   const VKGL::PixelFormat&     in_format,
                                   const VKGL::PixelType&       in_type,
                                   const void*                  in_pixels_ptr);
        void tex_image_2d         (const VKGL::TextureTarget&   in_target,
                                   const GLint&                 in_level,
                                   const VKGL::InternalFormat&  in_internalformat,
                                   const GLsizei&               in_width,
                                   const GLsizei&               in_height,
                                   const GLint&                 in_border,
                                   const VKGL::PixelFormat&     in_format,
                                   const VKGL::PixelType&       in_type,
                                   const void*                  in_pixels_ptr);
        void tex_sub_image_1d     (const VKGL::TextureTarget&   in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLsizei&               in_width,
                                   const VKGL::PixelFormat&     in_format,
                                   const VKGL::PixelType&       in_type,
                                   const void*                  in_pixels);
        void tex_sub_image_2d     (const VKGL::TextureTarget&   in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLint&                 in_yoffset,
                                   const GLsizei&               in_width,
                                   const GLsizei&               in_height,
                                   const VKGL::PixelFormat&     in_format,
                                   const VKGL::PixelType&       in_type,
                                   const void*                  in_pixels);

    private:
        /* Private functions */

        Context();

        bool init();

        /* Private variables */
        GLLimitsUniquePtr       m_gl_limits_ptr;
        GLStateManagerUniquePtr m_gl_state_manager_ptr;
        SchedulerUniquePtr      m_scheduler_ptr;
    };
}

#endif /* VKGL_CONTEXT_H */
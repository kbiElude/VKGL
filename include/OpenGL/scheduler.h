/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_SCHEDULER_H
#define VKGL_SCHEDULER_H

#include "OpenGL/types.h"

namespace VKGL
{
    typedef std::unique_ptr<Scheduler> SchedulerUniquePtr;

    class Scheduler
    {
    public:
        /* Public functions */
        static SchedulerUniquePtr create();

        ~Scheduler();

        void draw_arrays        (const VKGL::DrawCallMode&      in_mode,
                                 const GLint&                   in_first,
                                 const GLsizei&                 in_count);
        void draw_elements      (const VKGL::DrawCallMode&      in_mode,
                                 const GLsizei&                 in_count,
                                 const VKGL::DrawCallIndexType& in_type,
                                 const void*                    in_indices);
        void draw_range_elements(const VKGL::DrawCallMode&      in_mode,
                                 const GLuint&                  in_start,
                                 const GLuint&                  in_end,
                                 const GLsizei&                 in_count,
                                 const VKGL::DrawCallIndexType& in_type,
                                 const void*                    in_indices);
        void multi_draw_arrays  (const VKGL::DrawCallMode&      in_mode,
                                 const GLint*                   in_first_ptr,
                                 const GLsizei*                 in_count_ptr,
                                 const GLsizei&                 in_drawcount);
        void multi_draw_elements(const VKGL::DrawCallMode&      in_mode,
                                 const GLsizei*                 in_count_ptr,
                                 const VKGL::DrawCallIndexType& in_type,
                                 const void* const*             in_indices_ptr,
                                 const GLsizei&                 in_drawcount);

        void finish           ();
        void flush            ();

        void clear                   (const VKGL::ClearBufferBits& in_buffers_to_clear);
        void get_compressed_tex_image(const GLuint&                in_id,
                                      const GLint&                 in_level,
                                      void*                        in_img);
        void get_texture_image       (const GLuint&                in_id,
                                      const uint32_t&              in_level,
                                      const VKGL::PixelFormat&     in_format,
                                      const VKGL::PixelType&       in_type,
                                      void*                        out_pixels_ptr);
        void read_pixels             (const int32_t&               in_x,
                                      const int32_t&               in_y,
                                      const size_t&                in_width,
                                      const size_t&                in_height,
                                      const VKGL::PixelFormat&     in_format,
                                      const VKGL::PixelType&       in_type,
                                      void*                        out_pixels_ptr);

        void copy_tex_image_1d(const GLuint&               in_id,
                               const GLint                 in_level,
                               const VKGL::InternalFormat& in_internalformat,
                               const GLint&                in_x,
                               const GLint&                in_y,
                               const GLsizei&              in_width,
                               const GLint&                in_border);
        void copy_tex_image_2d(const GLuint&               in_id,
                               const GLint&                in_level,
                               const VKGL::InternalFormat& in_internalformat,
                               const GLint&                in_x,
                               const GLint&                in_y,
                               const GLsizei&              in_width,
                               const GLsizei&              in_height,
                               const GLint&                in_border);

        void copy_tex_sub_image_1d(const GLuint&  in_id,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width);
        void copy_tex_sub_image_2d(const GLuint&  in_id,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_yoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width,
                                   const GLsizei& in_height);
        void copy_tex_sub_image_3d(const GLuint&  in_id,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_yoffset,
                                   const GLint&   in_zoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width,
                                   const GLsizei& in_height);

        void compressed_tex_image_1d(const GLuint&                in_id,
                                     const GLint&                 in_level,
                                     const VKGL::InternalFormat&  in_internalformat,
                                     const GLsizei                in_width,
                                     const GLint                  in_border,
                                     const GLsizei                in_image_size,
                                     const void*                  in_data);
        void compressed_tex_image_2d(const GLuint&                in_id,
                                     const GLint&                 in_level,
                                     const VKGL::InternalFormat&  in_internalformat,
                                     const GLsizei&               in_width,
                                     const GLsizei&               in_height,
                                     const GLint&                 in_border,
                                     const GLsizei&               in_image_size,
                                     const void*                  in_data);
        void compressed_tex_image_3d(const GLuint&                in_id,
                                     const GLint&                 in_level,
                                     const VKGL::InternalFormat&  in_internalformat,
                                     const GLsizei&               in_width,
                                     const GLsizei&               in_height,
                                     const GLsizei&               in_depth,
                                     const GLint&                 in_border,
                                     const GLsizei&               in_image_size,
                                     const void*                  in_data);

        void compressed_tex_sub_image_1d(const GLuint&                in_id,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLsizei&               in_width,
                                         const VKGL::PixelFormat&     in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data);
        void compressed_tex_sub_image_2d(const GLuint&                in_id,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLint&                 in_yoffset,
                                         const GLsizei&               in_width,
                                         const GLsizei&               in_height,
                                         const VKGL::PixelFormat&     in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data);
        void compressed_tex_sub_image_3d(const GLuint&                in_id,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLint&                 in_yoffset,
                                         const GLint&                 in_zoffset,
                                         const GLsizei&               in_width,
                                         const GLsizei&               in_height,
                                         const GLsizei&               in_depth,
                                         const VKGL::PixelFormat&     in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data);

        void tex_image_1d(const GLuint&               in_id,
                          const int32_t&              in_level,
                          const VKGL::InternalFormat& in_internalformat,
                          const int32_t&              in_width,
                          const int32_t&              in_border,
                          const VKGL::PixelFormat&    in_format,
                          const VKGL::PixelType&      in_type,
                          const void*                 in_pixels_ptr);
        void tex_image_2d(const GLuint&               in_id,
                          const GLint&                in_level,
                          const VKGL::InternalFormat& in_internalformat,
                          const GLsizei&              in_width,
                          const GLsizei&              in_height,
                          const GLint&                in_border,
                          const VKGL::PixelFormat&    in_format,
                          const VKGL::PixelType&      in_type,
                          const void*                 in_pixels_ptr);
        void tex_image_3d(const GLuint&               in_id,
                          const GLint&                in_level,
                          const VKGL::InternalFormat& in_internalformat,
                          const GLsizei&              in_width,
                          const GLsizei&              in_height,
                          const GLsizei&              in_depth,
                          const GLint&                in_border,
                          const VKGL::PixelFormat&    in_format,
                          const VKGL::PixelType&      in_type,
                          const void*                 in_pixels_ptr);

        void tex_sub_image_1d(const GLuint&              in_id,
                              const GLint&               in_level,
                              const GLint&               in_xoffset,
                              const GLsizei&             in_width,
                              const VKGL::PixelFormat&   in_format,
                              const VKGL::PixelType&     in_type,
                              const void*                in_pixels);
        void tex_sub_image_2d(const GLuint&              in_id,
                              const GLint&               in_level,
                              const GLint&               in_xoffset,
                              const GLint&               in_yoffset,
                              const GLsizei&             in_width,
                              const GLsizei&             in_height,
                              const VKGL::PixelFormat&   in_format,
                              const VKGL::PixelType&     in_type,
                              const void*                in_pixels);
        void tex_sub_image_3d(const GLuint&              in_id,
                              const GLint&               in_level,
                              const GLint&               in_xoffset,
                              const GLint&               in_yoffset,
                              const GLint&               in_zoffset,
                              const GLsizei&             in_width,
                              const GLsizei&             in_height,
                              const GLsizei&             in_depth,
                              const VKGL::PixelFormat&   in_format,
                              const VKGL::PixelType&     in_type,
                              const void*                in_pixels);

    private:
        /* Private functions */

        Scheduler();

        bool init();


        /* Private variables */

    };
}

#endif /* VKGL_SCHEDULER_H */
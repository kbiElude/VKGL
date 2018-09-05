/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/scheduler.h"

OpenGL::Scheduler::Scheduler()
{
    /* Stub */
}

OpenGL::Scheduler::~Scheduler()
{
    /* Stub */
}

void OpenGL::Scheduler::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
    todo;
}

void OpenGL::Scheduler::compressed_tex_image_1d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei                 in_width,
                                                const GLint                   in_border,
                                                const GLsizei                 in_image_size,
                                                const void*                   in_data)
{
    todo;
}

void OpenGL::Scheduler::compressed_tex_image_2d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei&                in_width,
                                                const GLsizei&                in_height,
                                                const GLint&                  in_border,
                                                const GLsizei&                in_image_size,
                                                const void*                   in_data)
{
    todo;
}

void OpenGL::Scheduler::compressed_tex_image_3d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei&                in_width,
                                                const GLsizei&                in_height,
                                                const GLsizei&                in_depth,
                                                const GLint&                  in_border,
                                                const GLsizei&                in_image_size,
                                                const void*                   in_data)
{
    todo;
}

void OpenGL::Scheduler::compressed_tex_sub_image_1d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLsizei&             in_width,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    todo;
}

void OpenGL::Scheduler::compressed_tex_sub_image_2d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLint&               in_yoffset,
                                                    const GLsizei&             in_width,
                                                    const GLsizei&             in_height,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    todo;
}

void OpenGL::Scheduler::compressed_tex_sub_image_3d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLint&               in_yoffset,
                                                    const GLint&               in_zoffset,
                                                    const GLsizei&             in_width,
                                                    const GLsizei&             in_height,
                                                    const GLsizei&             in_depth,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    todo;
}

void OpenGL::Scheduler::copy_tex_image_1d(const GLuint&                 in_id,
                                          const GLint                   in_level,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const GLint&                  in_x,
                                          const GLint&                  in_y,
                                          const GLsizei&                in_width,
                                          const GLint&                  in_border)
{
    todo;
}

void OpenGL::Scheduler::copy_tex_image_2d(const GLuint&                 in_id,
                                          const GLint&                  in_level,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const GLint&                  in_x,
                                          const GLint&                  in_y,
                                          const GLsizei&                in_width,
                                          const GLsizei&                in_height,
                                          const GLint&                  in_border)
{
    todo;
}

void OpenGL::Scheduler::copy_tex_sub_image_1d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width)
{
    todo;
}

void OpenGL::Scheduler::copy_tex_sub_image_2d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_yoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width,
                                              const GLsizei& in_height)
{
    todo;
}

void OpenGL::Scheduler::copy_tex_sub_image_3d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_yoffset,
                                              const GLint&   in_zoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width,
                                              const GLsizei& in_height)
{
    todo;
}

OpenGL::SchedulerUniquePtr OpenGL::Scheduler::create()
{
    OpenGL::SchedulerUniquePtr result_ptr;

    result_ptr.reset(
        new OpenGL::Scheduler()
    );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

void OpenGL::Scheduler::finish()
{
    todo;
}

void OpenGL::Scheduler::flush()
{
    todo;
}

void OpenGL::Scheduler::get_texture_image(const GLuint&              in_id,
                                          const uint32_t&            in_level,
                                          const OpenGL::PixelFormat& in_format,
                                          const OpenGL::PixelType&   in_type,
                                          void*                      out_pixels_ptr)
{
    todo;
}

bool OpenGL::Scheduler::init()
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void OpenGL::Scheduler::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                          const GLint*                in_first_ptr,
                                          const GLsizei*              in_count_ptr,
                                          const GLsizei&              in_drawcount)
{
    todo;
}

void OpenGL::Scheduler::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                            const GLsizei*                   in_count_ptr,
                                            const OpenGL::DrawCallIndexType& in_type,
                                            const void* const*               in_indices_ptr,
                                            const GLsizei&                   in_drawcount)
{
    todo;
}

void OpenGL::Scheduler::read_pixels(const int32_t&             in_x,
                                    const int32_t&             in_y,
                                    const size_t&              in_width,
                                    const size_t&              in_height,
                                    const OpenGL::PixelFormat& in_format,
                                    const OpenGL::PixelType&   in_type,
                                    void*                      out_pixels_ptr)
{
    todo;
}

void OpenGL::Scheduler::tex_image_1d(const GLuint&                 in_id,
                                     const int32_t&                in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const int32_t&                in_width,
                                     const int32_t&                in_border,
                                     const OpenGL::PixelFormat&    in_format,
                                     const OpenGL::PixelType&      in_type,
                                     const void*                   in_pixels_ptr)
{
    todo;
}

void OpenGL::Scheduler::tex_image_2d(const GLuint&                 in_id,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei&                in_width,
                                     const GLsizei&                in_height,
                                     const GLint&                  in_border,
                                     const OpenGL::PixelFormat&    in_format,
                                     const OpenGL::PixelType&      in_type,
                                     const void*                   in_pixels_ptr)
{
    todo;
}

void OpenGL::Scheduler::tex_sub_image_1d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLsizei&             in_width,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    todo;
}

void OpenGL::Scheduler::tex_sub_image_2d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLint&               in_yoffset,
                                         const GLsizei&             in_width,
                                         const GLsizei&             in_height,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    todo;
}

void OpenGL::Scheduler::tex_sub_image_3d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLint&               in_yoffset,
                                         const GLint&               in_zoffset,
                                         const GLsizei&             in_width,
                                         const GLsizei&             in_height,
                                         const GLsizei&             in_depth,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    todo;
}
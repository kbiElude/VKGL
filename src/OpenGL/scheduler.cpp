/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/scheduler.h"

OpenGL::Scheduler::Scheduler()
{
    /* Stub */
}

OpenGL::Scheduler::~Scheduler()
{
    /* Stub */
}

void OpenGL::Scheduler::buffer_data(const GLuint&     in_id,
                                    const GLsizeiptr& in_size,
                                    const void*       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::buffer_sub_data(const GLuint&     in_id,
                                        const GLsizeiptr& in_start_offset,
                                        const GLsizeiptr& in_size,
                                        const void*       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::compile_shader(const GLuint& in_id)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::compressed_tex_image_1d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei                 in_width,
                                                const GLint                   in_border,
                                                const GLsizei                 in_image_size,
                                                const void*                   in_data)
{
    vkgl_not_implemented();
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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

void OpenGL::Scheduler::compressed_tex_sub_image_1d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLsizei&             in_width,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    vkgl_not_implemented();
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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

void OpenGL::Scheduler::copy_buffer_sub_data(const GLuint&     in_read_buffer_id,
                                             const GLuint&     in_write_buffer_id,
                                             const GLintptr&   in_read_offset,
                                             const GLintptr&   in_write_offset,
                                             const GLsizeiptr& in_size)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::copy_tex_image_1d(const GLuint&                 in_id,
                                          const GLint                   in_level,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const GLint&                  in_x,
                                          const GLint&                  in_y,
                                          const GLsizei&                in_width,
                                          const GLint&                  in_border)
{
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

void OpenGL::Scheduler::copy_tex_sub_image_1d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width)
{
    vkgl_not_implemented();
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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

void OpenGL::Scheduler::flush()
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::flush_mapped_buffer_range(const GLuint&     in_id,
                                                  const GLintptr&   in_offset,
                                                  const GLsizeiptr& in_length)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::get_buffer_sub_data(const GLuint&     in_id,
                                            const GLintptr&   in_offset,
                                            const GLsizeiptr& in_size,
                                            void*             out_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::get_texture_image(const GLuint&              in_id,
                                          const uint32_t&            in_level,
                                          const OpenGL::PixelFormat& in_format,
                                          const OpenGL::PixelType&   in_type,
                                          void*                      out_pixels_ptr)
{
    vkgl_not_implemented();
}

bool OpenGL::Scheduler::init()
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void* OpenGL::Scheduler::map_buffer(const GLuint&               in_id,
                                    const OpenGL::BufferAccess& in_access,
                                    const GLintptr&             in_start_offset,
                                    const GLsizeiptr&           in_length)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::Scheduler::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                          const GLint*                in_first_ptr,
                                          const GLsizei*              in_count_ptr,
                                          const GLsizei&              in_drawcount)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                            const GLsizei*                   in_count_ptr,
                                            const OpenGL::DrawCallIndexType& in_type,
                                            const void* const*               in_indices_ptr,
                                            const GLsizei&                   in_drawcount)
{
    vkgl_not_implemented();
}

void OpenGL::Scheduler::read_pixels(const int32_t&             in_x,
                                    const int32_t&             in_y,
                                    const size_t&              in_width,
                                    const size_t&              in_height,
                                    const OpenGL::PixelFormat& in_format,
                                    const OpenGL::PixelType&   in_type,
                                    void*                      out_pixels_ptr)
{
    vkgl_not_implemented();
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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

void OpenGL::Scheduler::tex_sub_image_1d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLsizei&             in_width,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    vkgl_not_implemented();
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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

bool OpenGL::Scheduler::unmap_buffer(const GLuint& in_id)
{
    vkgl_not_implemented();

    return false;
}
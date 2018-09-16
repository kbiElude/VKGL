/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/types.h"
#include "OpenGL/backend/vk_backend.h"

OpenGL::VKBackend::VKBackend()
{
    // todo
}

OpenGL::VKBackend::~VKBackend()
{
    // todo
}

void OpenGL::VKBackend::buffer_data(const GLuint&     in_id,
                                    const GLsizeiptr& in_size,
                                    const void*       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::buffer_sub_data(const GLuint&     in_id,
                                        const GLsizeiptr& in_start_offset,
                                        const GLsizeiptr& in_size,
                                        const void*       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compile_shader(const GLuint& in_id)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_image_1d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei                 in_width,
                                                const GLint                   in_border,
                                                const GLsizei                 in_image_size,
                                                const void*                   in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_image_2d(const GLuint&                 in_id,
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

void OpenGL::VKBackend::compressed_tex_image_3d(const GLuint&                 in_id,
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

void OpenGL::VKBackend::compressed_tex_sub_image_1d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLsizei&             in_width,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_sub_image_2d(const GLuint&              in_id,
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

void OpenGL::VKBackend::compressed_tex_sub_image_3d(const GLuint&              in_id,
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

void OpenGL::VKBackend::copy_buffer_sub_data(const GLuint&     in_read_buffer_id,
                                             const GLuint&     in_write_buffer_id,
                                             const GLintptr&   in_read_offset,
                                             const GLintptr&   in_write_offset,
                                             const GLsizeiptr& in_size)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_image_1d(const GLuint&                 in_id,
                                          const GLint                   in_level,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const GLint&                  in_x,
                                          const GLint&                  in_y,
                                          const GLsizei&                in_width,
                                          const GLint&                  in_border)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_image_2d(const GLuint&                 in_id,
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

void OpenGL::VKBackend::copy_tex_sub_image_1d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_sub_image_2d(const GLuint&  in_id,
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

void OpenGL::VKBackend::copy_tex_sub_image_3d(const GLuint&  in_id,
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

OpenGL::VKBackendUniquePtr OpenGL::VKBackend::create()
{
    OpenGL::VKBackendUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::VKBackend() );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

void OpenGL::VKBackend::draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                    const GLint&                in_first,
                                    const GLsizei&              in_count)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                      const GLsizei&                   in_count,
                                      const OpenGL::DrawCallIndexType& in_type,
                                      const void*                      in_indices)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                            const GLuint&                    in_start,
                                            const GLuint&                    in_end,
                                            const GLsizei&                   in_count,
                                            const OpenGL::DrawCallIndexType& in_type,
                                            const void*                      in_indices)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::finish()
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::flush()
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::flush_mapped_buffer_range(const GLuint&     in_id,
                                                  const GLintptr&   in_offset,
                                                  const GLsizeiptr& in_length)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::get_buffer_sub_data(const GLuint&     in_id,
                                            const GLintptr&   in_offset,
                                            const GLsizeiptr& in_size,
                                            void*             out_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::get_compressed_tex_image(const GLuint& in_id,
                                                 const GLint&  in_level,
                                                 void*         in_img)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::get_texture_image(const GLuint&              in_id,
                                          const uint32_t&            in_level,
                                          const OpenGL::PixelFormat& in_format,
                                          const OpenGL::PixelType&   in_type,
                                          void*                      out_pixels_ptr)
{
    vkgl_not_implemented();
}

bool OpenGL::VKBackend::init()
{
    // todo

    return true;
}

void OpenGL::VKBackend::link_program(const GLuint& in_program_id)
{
    vkgl_not_implemented();
}

void* OpenGL::VKBackend::map_buffer(const GLuint&               in_id,
                                    const OpenGL::BufferAccess& in_access,
                                    const GLintptr&             in_start_offset,
                                    const GLsizeiptr&           in_length)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::VKBackend::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                          const GLint*                in_first_ptr,
                                          const GLsizei*              in_count_ptr,
                                          const GLsizei&              in_drawcount)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                            const GLsizei*                   in_count_ptr,
                                            const OpenGL::DrawCallIndexType& in_type,
                                            const void* const*               in_indices_ptr,
                                            const GLsizei&                   in_drawcount)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::read_pixels(const int32_t&             in_x,
                                    const int32_t&             in_y,
                                    const size_t&              in_width,
                                    const size_t&              in_height,
                                    const OpenGL::PixelFormat& in_format,
                                    const OpenGL::PixelType&   in_type,
                                    void*                      out_pixels_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_image_1d(const GLuint&                 in_id,
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

void OpenGL::VKBackend::tex_image_2d(const GLuint&                 in_id,
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

void OpenGL::VKBackend::tex_image_3d(const GLuint&                 in_id,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei&                in_width,
                                     const GLsizei&                in_height,
                                     const GLsizei&                in_depth,
                                     const GLint&                  in_border,
                                     const OpenGL::PixelFormat&    in_format,
                                     const OpenGL::PixelType&      in_type,
                                     const void*                   in_pixels_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_sub_image_1d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLsizei&             in_width,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_sub_image_2d(const GLuint&              in_id,
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

void OpenGL::VKBackend::tex_sub_image_3d(const GLuint&              in_id,
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

bool OpenGL::VKBackend::unmap_buffer(const GLuint& in_id)
{
    vkgl_not_implemented();

    return false;
}

void OpenGL::VKBackend::validate_program(const GLuint& in_program_id)
{
    vkgl_not_implemented();
}


/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/scheduler.h"

VKGL::Scheduler::Scheduler()
{
    /* Stub */
}

VKGL::Scheduler::~Scheduler()
{
    /* Stub */
}

void VKGL::Scheduler::clear(const VKGL::ClearBufferBits& in_buffers_to_clear)
{
    todo;
}

void VKGL::Scheduler::compressed_tex_image_1d(const GLuint&               in_id,
                                              const GLint&                in_level,
                                              const VKGL::InternalFormat& in_internalformat,
                                              const GLsizei               in_width,
                                              const GLint                 in_border,
                                              const GLsizei               in_image_size,
                                              const void*                 in_data)
{
    todo;
}

void VKGL::Scheduler::compressed_tex_image_2d(const GLuint&               in_id,
                                              const GLint&                in_level,
                                              const VKGL::InternalFormat& in_internalformat,
                                              const GLsizei&              in_width,
                                              const GLsizei&              in_height,
                                              const GLint&                in_border,
                                              const GLsizei&              in_image_size,
                                              const void*                 in_data)
{
    todo;
}

void VKGL::Scheduler::compressed_tex_image_3d(const GLuint&               in_id,
                                              const GLint&                in_level,
                                              const VKGL::InternalFormat& in_internalformat,
                                              const GLsizei&              in_width,
                                              const GLsizei&              in_height,
                                              const GLsizei&              in_depth,
                                              const GLint&                in_border,
                                              const GLsizei&              in_image_size,
                                              const void*                 in_data)
{
    todo;
}

void VKGL::Scheduler::compressed_tex_sub_image_1d(const GLuint&            in_id,
                                                  const GLint&             in_level,
                                                  const GLint&             in_xoffset,
                                                  const GLsizei&           in_width,
                                                  const VKGL::PixelFormat& in_format,
                                                  const GLsizei&           in_image_size,
                                                  const void*              in_data)
{
    todo;
}

void VKGL::Scheduler::compressed_tex_sub_image_2d(const GLuint&            in_id,
                                                  const GLint&             in_level,
                                                  const GLint&             in_xoffset,
                                                  const GLint&             in_yoffset,
                                                  const GLsizei&           in_width,
                                                  const GLsizei&           in_height,
                                                  const VKGL::PixelFormat& in_format,
                                                  const GLsizei&           in_image_size,
                                                  const void*              in_data)
{
    todo;
}

void VKGL::Scheduler::compressed_tex_sub_image_3d(const GLuint&            in_id,
                                                  const GLint&             in_level,
                                                  const GLint&             in_xoffset,
                                                  const GLint&             in_yoffset,
                                                  const GLint&             in_zoffset,
                                                  const GLsizei&           in_width,
                                                  const GLsizei&           in_height,
                                                  const GLsizei&           in_depth,
                                                  const VKGL::PixelFormat& in_format,
                                                  const GLsizei&           in_image_size,
                                                  const void*              in_data)
{
    todo;
}

void VKGL::Scheduler::copy_tex_image_1d(const GLuint&               in_id,
                                        const GLint                 in_level,
                                        const VKGL::InternalFormat& in_internalformat,
                                        const GLint&                in_x,
                                        const GLint&                in_y,
                                        const GLsizei&              in_width,
                                        const GLint&                in_border)
{
    todo;
}

void VKGL::Scheduler::copy_tex_image_2d(const GLuint&               in_id,
                                        const GLint&                in_level,
                                        const VKGL::InternalFormat& in_internalformat,
                                        const GLint&                in_x,
                                        const GLint&                in_y,
                                        const GLsizei&              in_width,
                                        const GLsizei&              in_height,
                                        const GLint&                in_border)
{
    todo;
}

void VKGL::Scheduler::copy_tex_sub_image_1d(const GLuint&  in_id,
                                            const GLint&   in_level,
                                            const GLint&   in_xoffset,
                                            const GLint&   in_x,
                                            const GLint&   in_y,
                                            const GLsizei& in_width)
{
    todo;
}

void VKGL::Scheduler::copy_tex_sub_image_2d(const GLuint&  in_id,
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

void VKGL::Scheduler::copy_tex_sub_image_3d(const GLuint&  in_id,
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

VKGL::SchedulerUniquePtr VKGL::Scheduler::create()
{
    VKGL::SchedulerUniquePtr result_ptr;

    result_ptr.reset(
        new VKGL::Scheduler()
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

void VKGL::Scheduler::finish()
{
    todo;
}

void VKGL::Scheduler::flush()
{
    todo;
}

void VKGL::Scheduler::get_texture_image(const GLuint&            in_id,
                                        const uint32_t&          in_level,
                                        const VKGL::PixelFormat& in_format,
                                        const VKGL::PixelType&   in_type,
                                        void*                    out_pixels_ptr)
{
    todo;
}

bool VKGL::Scheduler::init()
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL::Scheduler::multi_draw_arrays(const VKGL::DrawCallMode& in_mode,
                                        const GLint*              in_first_ptr,
                                        const GLsizei*            in_count_ptr,
                                        const GLsizei&            in_drawcount)
{
    todo;
}

void VKGL::Scheduler::multi_draw_elements(const VKGL::DrawCallMode&      in_mode,
                                          const GLsizei*                 in_count_ptr,
                                          const VKGL::DrawCallIndexType& in_type,
                                          const void* const*             in_indices_ptr,
                                          const GLsizei&                 in_drawcount)
{
    todo;
}

void VKGL::Scheduler::read_pixels(const int32_t&           in_x,
                                  const int32_t&           in_y,
                                  const size_t&            in_width,
                                  const size_t&            in_height,
                                  const VKGL::PixelFormat& in_format,
                                  const VKGL::PixelType&   in_type,
                                  void*                    out_pixels_ptr)
{
    todo;
}

void VKGL::Scheduler::tex_image_1d(const GLuint&               in_id,
                                   const int32_t&              in_level,
                                   const VKGL::InternalFormat& in_internalformat,
                                   const int32_t&              in_width,
                                   const int32_t&              in_border,
                                   const VKGL::PixelFormat&    in_format,
                                   const VKGL::PixelType&      in_type,
                                   const void*                 in_pixels_ptr)
{
    todo;
}

void VKGL::Scheduler::tex_image_2d(const GLuint&               in_id,
                                   const GLint&                in_level,
                                   const VKGL::InternalFormat& in_internalformat,
                                   const GLsizei&              in_width,
                                   const GLsizei&              in_height,
                                   const GLint&                in_border,
                                   const VKGL::PixelFormat&    in_format,
                                   const VKGL::PixelType&      in_type,
                                   const void*                 in_pixels_ptr)
{
    todo;
}

void VKGL::Scheduler::tex_sub_image_1d(const GLuint&            in_id,
                                       const GLint&             in_level,
                                       const GLint&             in_xoffset,
                                       const GLsizei&           in_width,
                                       const VKGL::PixelFormat& in_format,
                                       const VKGL::PixelType&   in_type,
                                       const void*              in_pixels)
{
    todo;
}

void VKGL::Scheduler::tex_sub_image_2d(const GLuint&            in_id,
                                       const GLint&             in_level,
                                       const GLint&             in_xoffset,
                                       const GLint&             in_yoffset,
                                       const GLsizei&           in_width,
                                       const GLsizei&           in_height,
                                       const VKGL::PixelFormat& in_format,
                                       const VKGL::PixelType&   in_type,
                                       const void*              in_pixels)
{
    todo;
}

void VKGL::Scheduler::tex_sub_image_3d(const GLuint&            in_id,
                                       const GLint&             in_level,
                                       const GLint&             in_xoffset,
                                       const GLint&             in_yoffset,
                                       const GLint&             in_zoffset,
                                       const GLsizei&           in_width,
                                       const GLsizei&           in_height,
                                       const GLsizei&           in_depth,
                                       const VKGL::PixelFormat& in_format,
                                       const VKGL::PixelType&   in_type,
                                       const void*              in_pixels)
{
    todo;
}
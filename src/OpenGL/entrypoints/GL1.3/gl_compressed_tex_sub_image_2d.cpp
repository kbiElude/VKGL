/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_2d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLint&     in_level,
                     const GLint&     in_xoffset,
                     const GLint&     in_yoffset,
                     const GLsizei&   in_width,
                     const GLsizei&   in_height,
                     const GLenum&    in_format,
                     const GLsizei&   in_image_size,
                     const void*      in_data)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglCompressedTexSubImage2D(GLenum      target,
                                                       GLint       level,
                                                       GLint       xoffset,
                                                       GLint       yoffset,
                                                       GLsizei     width,
                                                       GLsizei     height,
                                                       GLenum      format,
                                                       GLsizei     imageSize,
                                                       const void* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCompressedTexSubImage2D(target=[%s] level=[%d] xoffset=[%d] yoffset=[%d] width=[%d] height=[%d] format=[%s] imageSize=[%d] data=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               level,
               xoffset,
               yoffset,
               static_cast<int32_t>(width),
               static_cast<int32_t>(height),
               OpenGL::Utils::get_raw_string_for_gl_enum(format),
               static_cast<int32_t>(imageSize),
               data);

    dispatch_table_ptr->pGLCompressedTexSubImage2D(dispatch_table_ptr->bound_context_ptr,
                                                   target,
                                                   level,
                                                   xoffset,
                                                   yoffset,
                                                   width,
                                                   height,
                                                   format,
                                                   imageSize,
                                                   data);
}

static void vkglCompressedTexSubImage2D_execute(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLint&     in_level,
                                                const GLint&     in_xoffset,
                                                const GLint&     in_yoffset,
                                                const GLsizei&   in_width,
                                                const GLsizei&   in_height,
                                                const GLenum&    in_format,
                                                const GLsizei&   in_image_size,
                                                const void*      in_data)
{
    const auto format_vkgl = OpenGL::Utils::get_pixel_format_for_gl_enum  (in_format);
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum(in_target);

    in_context_ptr->compressed_tex_sub_image_2d(target_vkgl,
                                                in_level,
                                                in_xoffset,
                                                in_yoffset,
                                                in_width,
                                                in_height,
                                                format_vkgl,
                                                in_image_size,
                                                in_data);
}

void OpenGL::vkglCompressedTexSubImage2D_with_validation(OpenGL::Context* in_context_ptr,
                                                         const GLenum&    in_target,
                                                         const GLint&     in_level,
                                                         const GLint&     in_xoffset,
                                                         const GLint&     in_yoffset,
                                                         const GLsizei&   in_width,
                                                         const GLsizei&   in_height,
                                                         const GLenum&    in_format,
                                                         const GLsizei&   in_image_size,
                                                         const void*      in_data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_xoffset,
                 in_yoffset,
                 in_width,
                 in_height,
                 in_format,
                 in_image_size,
                 in_data) )
    {
        vkglCompressedTexSubImage2D_execute(dispatch_table_ptr->bound_context_ptr,
                                            in_target,
                                            in_level,
                                            in_xoffset,
                                            in_yoffset,
                                            in_width,
                                            in_height,
                                            in_format,
                                            in_image_size,
                                            in_data);
    }
}

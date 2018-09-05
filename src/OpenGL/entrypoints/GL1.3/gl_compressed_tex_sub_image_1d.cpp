/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLint&     in_level,
                     const GLint&     in_xoffset,
                     const GLsizei&   in_width,
                     const GLenum&    in_format,
                     const GLsizei&   in_image_size,
                     const void*      in_data)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglCompressedTexSubImage1D(GLenum      target,
                                                       GLint       level,
                                                       GLint       xoffset,
                                                       GLsizei     width,
                                                       GLenum      format,
                                                       GLsizei     imageSize,
                                                       const void* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCompressedTexSubImage1D(target=[%s] level=[%d] xoffset=[%d] width=[%d] format=[%s] imageSize=[%d] data=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               level,
               xoffset,
               static_cast<int32_t>(width),
               OpenGL::Utils::get_raw_string_for_gl_enum(format),
               static_cast<int32_t>(imageSize),
               data);

    dispatch_table_ptr->pGLCompressedTexSubImage1D(dispatch_table_ptr->bound_context_ptr,
                                                   target,
                                                   level,
                                                   xoffset,
                                                   width,
                                                   format,
                                                   imageSize,
                                                   data);
}

static void vkglCompressedTexSubImage1D_execute(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLint&     in_level,
                                                const GLint&     in_xoffset,
                                                const GLsizei&   in_width,
                                                const GLenum&    in_format,
                                                const GLsizei&   in_image_size,
                                                const void*      in_data)
{
    const auto format_vkgl = OpenGL::Utils::get_pixel_format_for_gl_enum  (in_format);
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum(in_target);

    in_context_ptr->compressed_tex_sub_image_1d(target_vkgl,
                                                in_level,
                                                in_xoffset,
                                                in_width,
                                                format_vkgl,
                                                in_image_size,
                                                in_data);
}

void OpenGL::vkglCompressedTexSubImage1D_with_validation(OpenGL::Context* in_context_ptr,
                                                         const GLenum&    in_target,
                                                         const GLint&     in_level,
                                                         const GLint&     in_xoffset,
                                                         const GLsizei&   in_width,
                                                         const GLenum&    in_format,
                                                         const GLsizei&   in_image_size,
                                                         const void*      in_data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_xoffset,
                 in_width,
                 in_format,
                 in_image_size,
                 in_data) )
    {
        dispatch_table_ptr->pGLCompressedTexSubImage1D(dispatch_table_ptr->bound_context_ptr,
                                                       in_target,
                                                       in_level,
                                                       in_xoffset,
                                                       in_width,
                                                       in_format,
                                                       in_image_size,
                                                       in_data);
    }
}

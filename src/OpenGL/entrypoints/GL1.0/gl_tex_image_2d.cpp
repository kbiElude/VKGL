/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_tex_image_2d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLint&     in_level,
                     const GLint&     in_internalformat,
                     const GLsizei&   in_width,
                     const GLsizei&   in_height,
                     const GLint&     in_border,
                     const GLenum&    in_format,
                     const GLenum&    in_type,
                     const void*      in_pixels_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglTexImage2D(GLenum      target,
                                          GLint       level,
                                          GLint       internalformat,
                                          GLsizei     width,
                                          GLsizei     height,
                                          GLint       border,
                                          GLenum      format,
                                          GLenum      type,
                                          const void* pixels)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glTexImage2D(target=[%s] level={%d] internalformat=[%s] width=[%d] height=[%d] border=[%d] format=[%s] type=[%s] pixels=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               level,
               OpenGL::Utils::get_raw_string_for_gl_enum(internalformat),
               static_cast<int32_t>(width),
               static_cast<int32_t>(height),
               border,
               OpenGL::Utils::get_raw_string_for_gl_enum(format),
               OpenGL::Utils::get_raw_string_for_gl_enum(type),
               pixels);

    dispatch_table_ptr->pGLTexImage2D(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      level,
                                      internalformat,
                                      width,
                                      height,
                                      border,
                                      format,
                                      type,
                                      pixels);
}

static void vkglTexImage2D_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_target,
                                   const GLint&     in_level,
                                   const GLint&     in_internalformat,
                                   const GLsizei&   in_width,
                                   const GLsizei&   in_height,
                                   const GLint&     in_border,
                                   const GLenum&    in_format,
                                   const GLenum&    in_type,
                                   const void*      in_pixels_ptr)
{
    const auto format_vkgl         = OpenGL::Utils::get_pixel_format_for_gl_enum   (in_format);
    const auto internalformat_vkgl = OpenGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = OpenGL::Utils::get_texture_target_for_gl_enum (in_target);
    const auto type_vkgl           = OpenGL::Utils::get_pixel_type_for_gl_enum     (in_type);

    in_context_ptr->tex_image_2d(target_vkgl,
                                 in_level,
                                 internalformat_vkgl,
                                 in_width,
                                 in_height,
                                 in_border,
                                 format_vkgl,
                                 type_vkgl,
                                 in_pixels_ptr);
}

void OpenGL::vkglTexImage2D_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_target,
                                            const GLint&     in_level,
                                            const GLint&     in_internalformat,
                                            const GLsizei&   in_width,
                                            const GLsizei&   in_height,
                                            const GLint&     in_border,
                                            const GLenum&    in_format,
                                            const GLenum&    in_type,
                                            const void*      in_pixels_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_internalformat,
                 in_width,
                 in_height,
                 in_border,
                 in_format,
                 in_type,
                 in_pixels_ptr) )
    {
        vkglTexImage2D_execute(in_context_ptr,
                               in_target,
                               in_level,
                               in_internalformat,
                               in_width,
                               in_height,
                               in_border,
                               in_format,
                               in_type,
                               in_pixels_ptr);
    }
}
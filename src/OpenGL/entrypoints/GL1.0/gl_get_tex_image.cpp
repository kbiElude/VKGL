/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_image.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_format,
                     const GLenum&  in_type,
                     void*          out_pixels_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glGetTexImage(GLenum target,
                                          GLint  level,
                                          GLenum format,
                                          GLenum type,
                                          void*  pixels)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexImage(dispatch_table_ptr->bound_context_ptr,
                                       target,
                                       level,
                                       format,
                                       type,
                                       pixels);
}

void vkglGetTexImage_execute(VKGL::Context* in_context_ptr,
                             const GLenum&  in_target,
                             const GLint&   in_level,
                             const GLenum&  in_format,
                             const GLenum&  in_type,
                             void*          out_pixels_ptr)
{
    const auto target_vkgl       = VKGL::Utils::get_texture_target_for_gl_enum(in_target);
    const auto pixel_format_vkgl = VKGL::Utils::get_pixel_format_for_gl_enum  (in_format);
    const auto pixel_type_vkgl   = VKGL::Utils::get_pixel_type_for_gl_enum    (in_type);

    in_context_ptr->get_texture_image(target_vkgl,
                                      in_level,
                                      pixel_format_vkgl,
                                      pixel_type_vkgl,
                                      out_pixels_ptr);
}

void vkglGetTexImage_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_target,
                                     const GLint&   in_level,
                                     const GLenum&  in_format,
                                     const GLenum&  in_type,
                                     void*          out_pixels_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_format,
                 in_type,
                 out_pixels_ptr) )
    {
        vkglGetTexImage_execute(in_context_ptr,
                                in_target,
                                in_level,
                                in_format,
                                in_type,
                                out_pixels_ptr);
    }
}
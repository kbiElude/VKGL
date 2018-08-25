/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.2/gl_tex_sub_image_3d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLint&   in_xoffset,
                     const GLint&   in_yoffset,
                     const GLint&   in_zoffset,
                     const GLsizei& in_width,
                     const GLsizei& in_height,
                     const GLsizei& in_depth,
                     const GLenum&  in_format,
                     const GLenum&  in_type,
                     const void*    in_pixels)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void vkglTexSubImage3D_execute(VKGL::Context* in_context_ptr,
                               const GLenum&  in_target,
                               const GLint&   in_level,
                               const GLint&   in_xoffset,
                               const GLint&   in_yoffset,
                               const GLint&   in_zoffset,
                               const GLsizei& in_width,
                               const GLsizei& in_height,
                               const GLsizei& in_depth,
                               const GLenum&  in_format,
                               const GLenum&  in_type,
                               const void*    in_pixels)
{
    const auto format_vkgl = VKGL::Utils::get_pixel_format_for_gl_enum  (in_format);
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum(in_target);
    const auto type_vkgl   = VKGL::Utils::get_pixel_type_for_gl_enum    (in_type);

    in_context_ptr->tex_sub_image_3d(target_vkgl,
                                     in_level,
                                     in_xoffset,
                                     in_yoffset,
                                     in_zoffset,
                                     in_width,
                                     in_height,
                                     in_depth,
                                     format_vkgl,
                                     type_vkgl,
                                     in_pixels);
}

void vkglTexSubImage3D_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_target,
                                       const GLint&   in_level,
                                       const GLint&   in_xoffset,
                                       const GLint&   in_yoffset,
                                       const GLint&   in_zoffset,
                                       const GLsizei& in_width,
                                       const GLsizei& in_height,
                                       const GLsizei& in_depth,
                                       const GLenum&  in_format,
                                       const GLenum&  in_type,
                                       const void*    in_pixels)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_xoffset,
                 in_yoffset,
                 in_zoffset,
                 in_width,
                 in_height,
                 in_depth,
                 in_format,
                 in_type,
                 in_pixels) )
    {
        vkglTexSubImage3D_execute(in_context_ptr,
                                  in_target,
                                  in_level,
                                  in_xoffset,
                                  in_yoffset,
                                  in_zoffset,
                                  in_width,
                                  in_height,
                                  in_depth,
                                  in_format,
                                  in_type,
                                  in_pixels);
    }
}

void VKGL_APIENTRY vkglTexSubImage3D(GLenum      target,
                                     GLint       level,
                                     GLint       xoffset,
                                     GLint       yoffset,
                                     GLint       zoffset,
                                     GLsizei     width,
                                     GLsizei     height,
                                     GLsizei     depth,
                                     GLenum      format,
                                     GLenum      type,
                                     const void* pixels)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexSubImage3D(dispatch_table_ptr->bound_context_ptr,
                                         target,
                                         level,
                                         xoffset,
                                         yoffset,
                                         zoffset,
                                         width,
                                         height,
                                         depth,
                                         format,
                                         type,
                                         pixels);
}
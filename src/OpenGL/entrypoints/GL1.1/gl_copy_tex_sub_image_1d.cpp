/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLint&   in_xoffset,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLsizei& in_width)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glCopyTexSubImage1D(GLenum  target,
                                                GLint   level,
                                                GLint   xoffset,
                                                GLint   x,
                                                GLint   y,
                                                GLsizei width)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCopyTexSubImage1D(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             level,
                                             xoffset,
                                             x,
                                             y,
                                             width);
}

void vkglCopyTexSubImage1D_execute(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_target,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width)
{
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum(in_target);

    in_context_ptr->copy_tex_sub_image_1d(target_vkgl,
                                          in_level,
                                          in_xoffset,
                                          in_x,
                                          in_y,
                                          in_width);
}

void vkglCopyTexSubImage1D_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_target,
                                           const GLint&   in_level,
                                           const GLint&   in_xoffset,
                                           const GLint&   in_x,
                                           const GLint&   in_y,
                                           const GLsizei& in_width)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_xoffset,
                 in_x,
                 in_y,
                 in_width) )
    {
        vkglCopyTexSubImage1D_execute(in_context_ptr,
                                      in_target,
                                      in_level,
                                      in_xoffset,
                                      in_x,
                                      in_y,
                                      in_width);
    }
}
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLint&     in_level,
                     const GLint&     in_xoffset,
                     const GLint&     in_x,
                     const GLint&     in_y,
                     const GLsizei&   in_width)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglCopyTexSubImage1D(GLenum  target,
                                                 GLint   level,
                                                 GLint   xoffset,
                                                 GLint   x,
                                                 GLint   y,
                                                 GLsizei width)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCopyTexSubImage1D(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             level,
                                             xoffset,
                                             x,
                                             y,
                                             width);
}

static void vkglCopyTexSubImage1D_execute(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_target,
                                          const GLint&     in_level,
                                          const GLint&     in_xoffset,
                                          const GLint&     in_x,
                                          const GLint&     in_y,
                                          const GLsizei&   in_width)
{
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum(in_target);

    in_context_ptr->copy_tex_sub_image_1d(target_vkgl,
                                          in_level,
                                          in_xoffset,
                                          in_x,
                                          in_y,
                                          in_width);
}

void OpenGL::vkglCopyTexSubImage1D_with_validation(OpenGL::Context* in_context_ptr,
                                                   const GLenum&    in_target,
                                                   const GLint&     in_level,
                                                   const GLint&     in_xoffset,
                                                   const GLint&     in_x,
                                                   const GLint&     in_y,
                                                   const GLsizei&   in_width)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

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
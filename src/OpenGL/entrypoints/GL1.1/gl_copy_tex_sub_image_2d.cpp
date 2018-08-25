/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_2d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLint&   in_xoffset,
                     const GLint&   in_yoffset,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLsizei& in_width,
                     const GLsizei& in_height)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglCopyTexSubImage2D(GLenum  target,
                                         GLint   level,
                                         GLint   xoffset,
                                         GLint   yoffset,
                                         GLint   x,
                                         GLint   y,
                                         GLsizei width,
                                         GLsizei height)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCopyTexSubImage2D(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             level,
                                             xoffset,
                                             yoffset,
                                             x,
                                             y,
                                             width,
                                             height);
}

void vkglCopyTexSubImage2D_execute(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_target,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_yoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width,
                                   const GLsizei& in_height)
{
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum(in_target);

    in_context_ptr->copy_tex_sub_image_2d(target_vkgl,
                                          in_level,
                                          in_xoffset,
                                          in_yoffset,
                                          in_x,
                                          in_y,
                                          in_width,
                                          in_height);
}

void vkglCopyTexSubImage2D_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_target,
                                           const GLint&   in_level,
                                           const GLint&   in_xoffset,
                                           const GLint&   in_yoffset,
                                           const GLint&   in_x,
                                           const GLint&   in_y,
                                           const GLsizei& in_width,
                                           const GLsizei& in_height)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_xoffset,
                 in_yoffset,
                 in_x,
                 in_y,
                 in_width,
                 in_height) )
    {
        vkglCopyTexSubImage2D_execute(in_context_ptr,
                                      in_target,
                                      in_level,
                                      in_xoffset,
                                      in_yoffset,
                                      in_x,
                                      in_y,
                                      in_width,
                                      in_height);
    }
}
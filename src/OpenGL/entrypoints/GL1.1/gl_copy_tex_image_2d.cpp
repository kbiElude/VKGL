/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_2d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_internalformat,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLsizei& in_width,
                     const GLsizei& in_height,
                     const GLint&   in_border)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglCopyTexImage2D(GLenum  target,
                                               GLint   level,
                                               GLenum  internalformat,
                                               GLint   x,
                                               GLint   y,
                                               GLsizei width,
                                               GLsizei height,
                                               GLint   border)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCopyTexImage2D(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          level,
                                          internalformat,
                                          x,
                                          y,
                                          width,
                                          height,
                                          border);
}

void vkglCopyTexImage2D_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_target,
                                const GLint&   in_level,
                                const GLenum&  in_internalformat,
                                const GLint&   in_x,
                                const GLint&   in_y,
                                const GLsizei& in_width,
                                const GLsizei& in_height,
                                const GLint&   in_border)
{
    const auto internalformat_vkgl = VKGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = VKGL::Utils::get_texture_target_for_gl_enum (in_target);

    in_context_ptr->copy_tex_image_2d(target_vkgl,
                                      in_level,
                                      internalformat_vkgl,
                                      in_x,
                                      in_y,
                                      in_width,
                                      in_height,
                                      in_border);
}

void vkglCopyTexImage2D_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLint&   in_level,
                                        const GLenum&  in_internalformat,
                                        const GLint&   in_x,
                                        const GLint&   in_y,
                                        const GLsizei& in_width,
                                        const GLsizei& in_height,
                                        const GLint&   in_border)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_internalformat,
                 in_x,
                 in_y,
                 in_width,
                 in_height,
                 in_border) )
    {
        vkglCopyTexImage2D_execute(in_context_ptr,
                                   in_target,
                                   in_level,
                                   in_internalformat,
                                   in_x,
                                   in_y,
                                   in_width,
                                   in_height,
                                   in_border);
    }
}
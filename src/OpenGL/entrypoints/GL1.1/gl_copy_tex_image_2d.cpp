/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_2d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLint&     in_level,
                     const GLenum&    in_internalformat,
                     const GLint&     in_x,
                     const GLint&     in_y,
                     const GLsizei&   in_width,
                     const GLsizei&   in_height,
                     const GLint&     in_border)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglCopyTexImage2D(GLenum  target,
                                              GLint   level,
                                              GLenum  internalformat,
                                              GLint   x,
                                              GLint   y,
                                              GLsizei width,
                                              GLsizei height,
                                              GLint   border)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCopyTexImage2D(target=[%s] level=[%d] internalformat=[%s] x=[%d] y=[%d] width=[%d] height={%d] border=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               level,
               OpenGL::Utils::get_raw_string_for_gl_enum(internalformat),
               x,
               y,
               static_cast<int32_t>(width),
               static_cast<int32_t>(height),
               border);

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

static void vkglCopyTexImage2D_execute(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_target,
                                       const GLint&     in_level,
                                       const GLenum&    in_internalformat,
                                       const GLint&     in_x,
                                       const GLint&     in_y,
                                       const GLsizei&   in_width,
                                       const GLsizei&   in_height,
                                       const GLint&     in_border)
{
    const auto internalformat_vkgl = OpenGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = OpenGL::Utils::get_texture_target_for_gl_enum (in_target);

    in_context_ptr->copy_tex_image_2d(target_vkgl,
                                      in_level,
                                      internalformat_vkgl,
                                      in_x,
                                      in_y,
                                      in_width,
                                      in_height,
                                      in_border);
}

void OpenGL::vkglCopyTexImage2D_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLint&     in_level,
                                                const GLenum&    in_internalformat,
                                                const GLint&     in_x,
                                                const GLint&     in_y,
                                                const GLsizei&   in_width,
                                                const GLsizei&   in_height,
                                                const GLint&     in_border)
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
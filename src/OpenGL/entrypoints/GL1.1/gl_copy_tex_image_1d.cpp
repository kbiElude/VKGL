/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_1d.h"
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
                     const GLint&     in_border)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglCopyTexImage1D(GLenum  target,
                                              GLint   level,
                                              GLenum  internalformat,
                                              GLint   x,
                                              GLint   y,
                                              GLsizei width,
                                              GLint   border)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCopyTexImage1D(target=[%s] level=[%d] internalformat=[%s] x=[%d] y=[%d] width=[%d] border=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               level,
               OpenGL::Utils::get_raw_string_for_gl_enum(internalformat),
               x,
               y,
               static_cast<int32_t>(width),
               border);

    dispatch_table_ptr->pGLCopyTexImage1D(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          level,
                                          internalformat,
                                          x,
                                          y,
                                          width,
                                          border);
}

static void vkglCopyTexImage1D_execute(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_target,
                                       const GLint&     in_level,
                                       const GLenum&    in_internalformat,
                                       const GLint&     in_x,
                                       const GLint&     in_y,
                                       const GLsizei&   in_width,
                                       const GLint&     in_border)
{
    const auto internalformat_vkgl = OpenGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = OpenGL::Utils::get_texture_target_for_gl_enum (in_target);

    in_context_ptr->copy_tex_image_1d(target_vkgl,
                                      in_level,
                                      internalformat_vkgl,
                                      in_x,
                                      in_y,
                                      in_width,
                                      in_border);
}

void OpenGL::vkglCopyTexImage1D_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLint&     in_level,
                                                const GLenum&    in_internalformat,
                                                const GLint&     in_x,
                                                const GLint&     in_y,
                                                const GLsizei&   in_width,
                                                const GLint&     in_border)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_internalformat,
                 in_x,
                 in_y,
                 in_width,
                 in_border) )
    {
        vkglCopyTexImage1D_execute(in_context_ptr,
                                   in_target,
                                   in_level,
                                   in_internalformat,
                                   in_x,
                                   in_y,
                                   in_width,
                                   in_border);
    }
}
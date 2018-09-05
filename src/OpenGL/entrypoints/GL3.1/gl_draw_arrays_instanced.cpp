/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_draw_arrays_instanced.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode,
                     const GLint&     in_first,
                     const GLsizei&   in_count,
                     const GLsizei&   in_instancecount)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDrawArraysInstanced(GLenum  mode,
                                                   GLint   first,
                                                   GLsizei count,
                                                   GLsizei instancecount)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDrawArraysInstanced(mode=[%s] first=[%d] count=[%d] instancecount=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(mode),
               first,
               static_cast<int32_t>(count),
               static_cast<int32_t>(instancecount) );

    dispatch_table_ptr->pGLDrawArraysInstanced(dispatch_table_ptr->bound_context_ptr,
                                               mode,
                                               first,
                                               count,
                                               instancecount);
}

static void vkglDrawArraysInstanced_execute(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_mode,
                                            const GLint&     in_first,
                                            const GLsizei&   in_count,
                                            const GLsizei&   in_instancecount)
{
    const auto mode_vkgl = OpenGL::Utils::get_draw_call_mode_for_gl_enum(in_mode);

    in_context_ptr->draw_arrays_instanced(mode_vkgl,
                                          in_first,
                                          in_count,
                                          in_instancecount);
}

void OpenGL::vkglDrawArraysInstanced_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_mode,
                                                     const GLint&     in_first,
                                                     const GLsizei&   in_count,
                                                     const GLsizei&   in_instancecount)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_first,
                 in_count,
                 in_instancecount) )
    {
        vkglDrawArraysInstanced_execute(in_context_ptr,
                                        in_mode,
                                        in_first,
                                        in_count,
                                        in_instancecount);
    }
}

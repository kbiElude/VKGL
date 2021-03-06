/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_draw_arrays.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode,
                     const GLint&     in_first,
                     const GLsizei&   in_count)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDrawArrays(GLenum  mode,
                                          GLint   first,
                                          GLsizei count)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDrawArrays(mode=[%s] first=[%d] count=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(mode),
               first,
               static_cast<int32_t>(count) );

    dispatch_table_ptr->pGLDrawArrays(dispatch_table_ptr->bound_context_ptr,
                                      mode,
                                      first,
                                      count);
}

static void vkglDrawArrays_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_mode,
                                   const GLint&     in_first,
                                   const GLsizei&   in_count)
{
    const auto mode_vkgl = OpenGL::Utils::get_draw_call_mode_for_gl_enum(in_mode);

    in_context_ptr->draw_arrays(mode_vkgl,
                                in_first,
                                in_count);
}

void OpenGL::vkglDrawArrays_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_mode,
                                            const GLint&     in_first,
                                            const GLsizei&   in_count)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_first,
                 in_count) )
    {
        vkglDrawArrays_execute(in_context_ptr,
                               in_mode,
                               in_first,
                               in_count);
    }
}
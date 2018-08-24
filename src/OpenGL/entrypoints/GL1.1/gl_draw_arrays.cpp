/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_draw_arrays.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode,
                     const GLint&   in_first,
                     const GLsizei& in_count)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglDrawArrays(GLenum  mode,
                                           GLint   first,
                                           GLsizei count)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawArrays(dispatch_table_ptr->bound_context_ptr,
                                      mode,
                                      first,
                                      count);
}

void vkglDrawArrays_execute(VKGL::Context* in_context_ptr,
                            const GLenum&  in_mode,
                            const GLint&   in_first,
                            const GLsizei& in_count)
{
    const auto mode_vkgl = VKGL::Utils::get_draw_call_mode_for_gl_enum(in_mode);

    in_context_ptr->draw_arrays(mode_vkgl,
                                in_first,
                                in_count);
}

void vkglDrawArrays_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_mode,
                                    const GLint&   in_first,
                                    const GLsizei& in_count)
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
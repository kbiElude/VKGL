/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_multi_draw_arrays.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode,
                     const GLint*   in_first_ptr,
                     const GLsizei* in_count_ptr,
                     const GLsizei& in_drawcount)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glMultiDrawArrays(GLenum         mode,
                                              const GLint*   first,
                                              const GLsizei* count,
                                              GLsizei        drawcount)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLMultiDrawArrays(dispatch_table_ptr->bound_context_ptr,
                                           mode,
                                           first,
                                           count,
                                           drawcount);
}

void vkglMultiDrawArrays_execute(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_mode,
                                 const GLint*   in_first_ptr,
                                 const GLsizei* in_count_ptr,
                                 const GLsizei& in_drawcount)
{
    const auto mode_vkgl = VKGL::Utils::get_draw_call_mode_for_gl_enum(in_mode);

    in_context_ptr->multi_draw_arrays(mode_vkgl,
                                      in_first_ptr,
                                      in_count_ptr,
                                      in_drawcount);
}

void vkglMultiDrawArrays_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_mode,
                                         const GLint*   in_first_ptr,
                                         const GLsizei* in_count_ptr,
                                         const GLsizei& in_drawcount)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_first_ptr,
                 in_count_ptr,
                 in_drawcount) )
    {
        vkglMultiDrawArrays_execute(in_context_ptr,
                                    in_mode,
                                    in_first_ptr,
                                    in_count_ptr,
                                    in_drawcount);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_draw_elements.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode,
                     const GLsizei& in_count,
                     const GLenum&  in_type,
                     const void*    in_indices)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDrawElements(GLenum      mode,
                                            GLsizei     count,
                                            GLenum      type,
                                            const void* indices)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawElements(dispatch_table_ptr->bound_context_ptr,
                                        mode,
                                        count,
                                        type,
                                        indices);
}

static void vkglDrawElements_execute(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_mode,
                                     const GLsizei& in_count,
                                     const GLenum&  in_type,
                                     const void*    in_indices)
{
    const auto mode_vkgl = VKGL::Utils::get_draw_call_mode_for_gl_enum      (in_mode);
    const auto type_vkgl = VKGL::Utils::get_draw_call_index_type_for_gl_enum(in_type);

    in_context_ptr->draw_elements(mode_vkgl,
                                  in_count,
                                  type_vkgl,
                                  in_indices);
}

void OpenGL::vkglDrawElements_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_mode,
                                              const GLsizei& in_count,
                                              const GLenum&  in_type,
                                              const void*    in_indices)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_count,
                 in_type,
                 in_indices) )
    {
        todo;
    }
}
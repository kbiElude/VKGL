/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.2/gl_draw_range_elements.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode,
                     const GLuint&  in_start,
                     const GLuint&  in_end,
                     const GLsizei& in_count,
                     const GLenum&  in_type,
                     const void*    in_indices)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

static void vkglDrawRangeElements_execute(VKGL::Context* in_context_ptr,
                                          const GLenum&  in_mode,
                                          const GLuint&  in_start,
                                          const GLuint&  in_end,
                                          const GLsizei& in_count,
                                          const GLenum&  in_type,
                                          const void*    in_indices)
{
    const auto mode_vkgl = VKGL::Utils::get_draw_call_mode_for_gl_enum      (in_mode);
    const auto type_vkgl = VKGL::Utils::get_draw_call_index_type_for_gl_enum(in_type);

    in_context_ptr->draw_range_elements(mode_vkgl,
                                        in_start,
                                        in_end,
                                        in_count,
                                        type_vkgl,
                                        in_indices);
}

void OpenGL::vkglDrawRangeElements_with_validation(VKGL::Context* in_context_ptr,
                                                   const GLenum&  in_mode,
                                                   const GLuint&  in_start,
                                                   const GLuint&  in_end,
                                                   const GLsizei& in_count,
                                                   const GLenum&  in_type,
                                                   const void*    in_indices)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_start,
                 in_end,
                 in_count,
                 in_type,
                 in_indices) )
    {
        vkglDrawRangeElements_execute(in_context_ptr,
                                      in_mode,
                                      in_start,
                                      in_end,
                                      in_count,
                                      in_type,
                                      in_indices);
    }
}

void VKGL_APIENTRY OpenGL::vkglDrawRangeElements(GLenum      mode,
                                                 GLuint      start,
                                                 GLuint      end,
                                                 GLsizei     count,
                                                 GLenum      type,
                                                 const void* indices)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawRangeElements(dispatch_table_ptr->bound_context_ptr,
                                             mode,
                                             start,
                                             end,
                                             count,
                                             type,
                                             indices);
}
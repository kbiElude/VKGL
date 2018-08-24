/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_draw_range_elements_base_vertex.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode,
                     const GLuint&  in_start,
                     const GLuint&  in_end,
                     const GLsizei& in_count,
                     const GLenum&  in_type,
                     const void*    in_indices,
                     const GLint&   in_basevertex)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglDrawRangeElementsBaseVertex(GLenum      mode,
                                                            GLuint      start,
                                                            GLuint      end,
                                                            GLsizei     count,
                                                            GLenum      type,
                                                            const void* indices,
                                                            GLint       basevertex)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawRangeElementsBaseVertex(dispatch_table_ptr->bound_context_ptr,
                                                       mode,
                                                       start,
                                                       end,
                                                       count,
                                                       type,
                                                       indices,
                                                       basevertex);
}


void vkglDrawRangeElementsBaseVertex_execute(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_mode,
                                             const GLuint&  in_start,
                                             const GLuint&  in_end,
                                             const GLsizei& in_count,
                                             const GLenum&  in_type,
                                             const void*    in_indices,
                                             const GLint&   in_basevertex)
{
    const auto mode_vkgl = VKGL::Utils::get_draw_call_mode_for_gl_enum      (in_mode);
    const auto type_vkgl = VKGL::Utils::get_draw_call_index_type_for_gl_enum(in_type);

    in_context_ptr->draw_range_elements_base_vertex(mode_vkgl,
                                                    in_start,
                                                    in_end,
                                                    in_count,
                                                    type_vkgl,
                                                    in_indices,
                                                    in_basevertex);
}

void vkglDrawRangeElementsBaseVertex_with_validation(VKGL::Context* in_context_ptr,
                                                     const GLenum&  in_mode,
                                                     const GLuint&  in_start,
                                                     const GLuint&  in_end,
                                                     const GLsizei& in_count,
                                                     const GLenum&  in_type,
                                                     const void*    in_indices,
                                                     const GLint&   in_basevertex)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_start,
                 in_end,
                 in_count,
                 in_type,
                 in_indices,
                 in_basevertex) )
    {
        vkglDrawRangeElementsBaseVertex_execute(in_context_ptr,
                                                in_mode,
                                                in_start,
                                                in_end,
                                                in_count,
                                                in_type,
                                                in_indices,
                                                in_basevertex);
    }
}

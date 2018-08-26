/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_draw_elements_instanced_base_vertex.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode,
                     const GLsizei& in_count,
                     const GLenum&  in_type,
                     const void*    in_indices_ptr,
                     const GLsizei& in_instancecount,
                     const GLint&   in_basevertex)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglDrawElementsInstancedBaseVertex(GLenum      mode,
                                                       GLsizei     count,
                                                       GLenum      type,
                                                       const void* indices,
                                                       GLsizei     instancecount,
                                                       GLint       basevertex)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawElementsInstancedBaseVertex(dispatch_table_ptr->bound_context_ptr,
                                                           mode,
                                                           count,
                                                           type,
                                                           indices,
                                                           instancecount,
                                                           basevertex);
}

void vkglDrawElementsInstancedBaseVertex_execute(VKGL::Context* in_context_ptr,
                                                 const GLenum&  in_mode,
                                                 const GLsizei& in_count,
                                                 const GLenum&  in_type,
                                                 const void*    in_indices_ptr,
                                                 const GLsizei& in_instancecount,
                                                 const GLint&   in_basevertex)
{
    const auto mode_vkgl = VKGL::Utils::get_draw_call_mode_for_gl_enum      (in_mode);
    const auto type_vkgl = VKGL::Utils::get_draw_call_index_type_for_gl_enum(in_type);

    in_context_ptr->draw_elements_instanced_base_vertex(mode_vkgl,
                                                        in_count,
                                                        type_vkgl,
                                                        in_indices_ptr,
                                                        in_instancecount,
                                                        in_basevertex);
}

void vkglDrawElementsInstancedBaseVertex_with_validation(VKGL::Context* in_context_ptr,
                                                         const GLenum&  in_mode,
                                                         const GLsizei& in_count,
                                                         const GLenum&  in_type,
                                                         const void*    in_indices_ptr,
                                                         const GLsizei& in_instancecount,
                                                         const GLint&   in_basevertex)
{
    if (validate(in_context_ptr,
                 in_mode,
                 in_count,
                 in_type,
                 in_indices_ptr,
                 in_instancecount,
                 in_basevertex) )
    {
        vkglDrawElementsInstancedBaseVertex_execute(in_context_ptr,
                                                    in_mode,
                                                    in_count,
                                                    in_type,
                                                    in_indices_ptr,
                                                    in_instancecount,
                                                    in_basevertex);
    }
}

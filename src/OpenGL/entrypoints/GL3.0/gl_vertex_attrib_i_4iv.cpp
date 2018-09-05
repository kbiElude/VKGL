/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4iv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLint*     in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI4iv(GLuint       index,
                                                const GLint* v)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glVertexAttribI4iv(index=[%u] v=[%p])",
               index,
               v);

    dispatch_table_ptr->pGLVertexAttribI4iv(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            v);
}

static void vkglVertexAttribI4iv_execute(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_index,
                                         const GLint*     in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Int,
                                         OpenGL::GetSetArgumentType::Int,
                                         4,     /* in_n_components */
                                         false, /* in_normalized   */
                                         in_v_ptr);
}

void OpenGL::vkglVertexAttribI4iv_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLuint&    in_index,
                                                  const GLint*     in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttribI4iv_execute(in_context_ptr,
                                     in_index,
                                     in_v_ptr);
    }
}

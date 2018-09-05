/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLint&     in_x)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI1i(GLuint index,
                                               GLint  x)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttribI1i(index=[%u] x=[%d])",
               index,
               x);

    dispatch_table_ptr->pGLVertexAttribI1i(dispatch_table_ptr->bound_context_ptr,
                                           index,
                                           x);
}

static void vkglVertexAttribI1i_execute(OpenGL::Context* in_context_ptr,
                                        const GLuint&    in_index,
                                        const GLint&     in_x)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Float,
                                         OpenGL::GetSetArgumentType::Int,
                                         1,     /* in_n_components */
                                         false, /* in_normalized   */
                                        &in_x);
}

void OpenGL::vkglVertexAttribI1i_with_validation(OpenGL::Context* in_context_ptr,
                                                 const GLuint&    in_index,
                                                 const GLint&     in_x)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x) )
    {
        vkglVertexAttribI1i_execute(in_context_ptr,
                                    in_index,
                                    in_x);
    }
}

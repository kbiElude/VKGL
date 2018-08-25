/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nsv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLshort* in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglVertexAttrib4Nsv(GLuint         index,
                                        const GLshort* v)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib4Nsv(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            v);
}

void vkglVertexAttrib4Nsv_execute(VKGL::Context* in_context_ptr,
                                  const GLuint&  in_index,
                                  const GLshort* in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Short,
                                         VKGL::GetSetArgumentType::Float,
                                         4,
                                         true, /* in_normalized */
                                         in_v_ptr);
}

void vkglVertexAttrib4Nsv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_index,
                                          const GLshort* in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttrib4Nsv_execute(in_context_ptr,
                                     in_index,
                                     in_v_ptr);
    }
}

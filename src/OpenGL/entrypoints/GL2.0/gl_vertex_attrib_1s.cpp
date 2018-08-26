/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1s.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLshort& in_x)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglVertexAttrib1s(GLuint  index,
                                      GLshort x)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib1s(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x);
}

void vkglVertexAttrib1s_execute(VKGL::Context* in_context_ptr,
                                const GLuint&  in_index,
                                const GLshort& in_x)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Short,
                                         VKGL::GetSetArgumentType::Float,
                                         1,
                                         false, /* in_normalized */
                                        &in_x);
}

void vkglVertexAttrib1s_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLshort& in_x)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x) )
    {
        vkglVertexAttrib1s_execute(in_context_ptr,
                                   in_index,
                                   in_x);
    }
}

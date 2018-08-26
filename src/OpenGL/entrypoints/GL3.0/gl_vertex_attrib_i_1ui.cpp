/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLuint&  in_x)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglVertexAttribI1ui(GLuint index,
                                        GLuint x)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI1ui(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x);
}

void vkglVertexAttribI1ui_execute(VKGL::Context* in_context_ptr,
                                  const GLuint&  in_index,
                                  const GLuint&  in_x)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Float,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         1,
                                         false, /* in_normalized */
                                        &in_x);
}

void vkglVertexAttribI1ui_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_index,
                                          const GLuint&  in_x)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x) )
    {
        vkglVertexAttribI1ui_execute(in_context_ptr,
                                     in_index,
                                     in_x);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLfloat& in_x,
                     const GLfloat& in_y)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttrib2f(GLuint  index,
                                             GLfloat x,
                                             GLfloat y)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib2f(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y);
}

void vkglVertexAttrib2f_execute(VKGL::Context* in_context_ptr,
                                const GLuint&  in_index,
                                const GLfloat& in_x,
                                const GLfloat& in_y)
{
    const float data[] =
    {
        in_x,
        in_y
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Float,
                                         VKGL::GetSetArgumentType::Float,
                                         2,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttrib2f_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLfloat& in_x,
                                        const GLfloat& in_y)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y) )
    {
        vkglVertexAttrib2f_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y);
    }
}

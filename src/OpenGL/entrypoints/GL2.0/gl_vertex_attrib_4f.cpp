/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLfloat& in_x,
                     const GLfloat& in_y,
                     const GLfloat& in_z,
                     const GLfloat& in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttrib4f(GLuint  index,
                                             GLfloat x,
                                             GLfloat y,
                                             GLfloat z,
                                             GLfloat w)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib4f(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z,
                                          w);
}

void vkglVertexAttrib4f_execute(VKGL::Context* in_context_ptr,
                                const GLuint&  in_index,
                                const GLfloat& in_x,
                                const GLfloat& in_y,
                                const GLfloat& in_z,
                                const GLfloat& in_w)
{
    const float data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Float,
                                         4,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttrib4f_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLfloat& in_x,
                                        const GLfloat& in_y,
                                        const GLfloat& in_z,
                                        const GLfloat& in_w)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z,
                 in_w) )
    {
        vkglVertexAttrib4f_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y,
                                   in_z,
                                   in_w);
    }
}

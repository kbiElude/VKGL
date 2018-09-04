/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLfloat&   in_x,
                     const GLfloat&   in_y,
                     const GLfloat&   in_z)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib3f(GLuint  index,
                                              GLfloat x,
                                              GLfloat y,
                                              GLfloat z)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttrib3f(index=[%u] x=[%.4f] y=[%.4f] z=[%.4f])",
               index,
               x,
               y,
               z);

    dispatch_table_ptr->pGLVertexAttrib3f(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z);
}

static void vkglVertexAttrib3f_execute(OpenGL::Context* in_context_ptr,
                                       const GLuint&    in_index,
                                       const GLfloat&   in_x,
                                       const GLfloat&   in_y,
                                       const GLfloat&   in_z)
{
    const float data[] =
    {
        in_x,
        in_y,
        in_z
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Float,
                                         OpenGL::GetSetArgumentType::Float,
                                         3,
                                         false, /* in_normalized */
                                         data);
}

void OpenGL::vkglVertexAttrib3f_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_index,
                                                const GLfloat&   in_x,
                                                const GLfloat&   in_y,
                                                const GLfloat&   in_z)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z) )
    {
        vkglVertexAttrib3f_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y,
                                   in_z);
    }
}

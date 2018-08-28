/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*  in_context_ptr,
                     const GLuint&   in_index,
                     const GLdouble& in_x)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib1d(GLuint   index,
                                              GLdouble x)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib1d(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x);
}

static void vkglVertexAttrib1d_execute(VKGL::Context*  in_context_ptr,
                                       const GLuint&   in_index,
                                       const GLdouble& in_x)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Double,
                                         VKGL::GetSetArgumentType::Float,
                                         1,
                                         false, /* in_normalized */
                                        &in_x);
}

void OpenGL::vkglVertexAttrib1d_with_validation(VKGL::Context*  in_context_ptr,
                                                const GLuint&   in_index,
                                                const GLdouble& in_x)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x) )
    {
        vkglVertexAttrib1d_execute(in_context_ptr,
                                   in_index,
                                   in_x);
    }
}

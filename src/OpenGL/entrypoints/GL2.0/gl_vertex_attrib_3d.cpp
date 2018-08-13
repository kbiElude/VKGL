/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*  in_context_ptr,
                     const GLuint&   in_index,
                     const GLdouble& in_x,
                     const GLdouble& in_y,
                     const GLdouble& in_z)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttrib3d(GLuint   index,
                                             GLdouble x,
                                             GLdouble y,
                                             GLdouble z)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib3d(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z);
}

void vkglVertexAttrib3d_execute(VKGL::Context*  in_context_ptr,
                                const GLuint&   in_index,
                                const GLdouble& in_x,
                                const GLdouble& in_y,
                                const GLdouble& in_z)
{
    const double data[] =
    {
        in_x,
        in_y,
        in_z
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Double,
                                         3,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttrib3d_with_validation(VKGL::Context*  in_context_ptr,
                                        const GLuint&   in_index,
                                        const GLdouble& in_x,
                                        const GLdouble& in_y,
                                        const GLdouble& in_z)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z) )
    {
        vkglVertexAttrib3d_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y,
                                   in_z);
    }
}

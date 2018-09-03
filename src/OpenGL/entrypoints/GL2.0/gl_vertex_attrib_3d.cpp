/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLdouble&  in_x,
                     const GLdouble&  in_y,
                     const GLdouble&  in_z)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib3d(GLuint   index,
                                              GLdouble x,
                                              GLdouble y,
                                              GLdouble z)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib3d(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z);
}

static void vkglVertexAttrib3d_execute(OpenGL::Context* in_context_ptr,
                                       const GLuint&    in_index,
                                       const GLdouble&  in_x,
                                       const GLdouble&  in_y,
                                       const GLdouble&  in_z)
{
    const double data[] =
    {
        in_x,
        in_y,
        in_z
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Double,
                                         OpenGL::GetSetArgumentType::Float,
                                         3,
                                         false, /* in_normalized */
                                         data);
}

void OpenGL::vkglVertexAttrib3d_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_index,
                                                const GLdouble&  in_x,
                                                const GLdouble&  in_y,
                                                const GLdouble&  in_z)
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

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context*  in_context_ptr,
                     const GLuint&     in_index,
                     const GLdouble&   in_x,
                     const GLdouble&   in_y,
                     const GLdouble&   in_z,
                     const GLdouble&   in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib4d(GLuint   index,
                                              GLdouble x,
                                              GLdouble y,
                                              GLdouble z,
                                              GLdouble w)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttrib4d(index=[%u] x=[%.4f] y=[%.4f] z=[%.4f] w=[%.4f])",
               index,
               static_cast<float>(x),
               static_cast<float>(y),
               static_cast<float>(z),
               static_cast<float>(w) );

    dispatch_table_ptr->pGLVertexAttrib4d(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z,
                                          w);
}

static void vkglVertexAttrib4d_execute(OpenGL::Context* in_context_ptr,
                                       const GLuint&    in_index,
                                       const GLdouble&  in_x,
                                       const GLdouble&  in_y,
                                       const GLdouble&  in_z,
                                       const GLdouble&  in_w)
{
    const double data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Double,
                                         OpenGL::GetSetArgumentType::Float,
                                         4,
                                         false, /* in_normalized */
                                         data);
}

void OpenGL::vkglVertexAttrib4d_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_index,
                                                const GLdouble&  in_x,
                                                const GLdouble&  in_y,
                                                const GLdouble&  in_z,
                                                const GLdouble&  in_w)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z,
                 in_w) )
    {
        vkglVertexAttrib4d_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y,
                                   in_z,
                                   in_w);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2dv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*  in_context_ptr,
                     const GLuint&   in_index,
                     const GLdouble* in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglVertexAttrib2dv(GLuint          index,
                                       const GLdouble* v)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib2dv(dispatch_table_ptr->bound_context_ptr,
                                           index,
                                           v);
}

void vkglVertexAttrib2dv_execute(VKGL::Context*  in_context_ptr,
                                 const GLuint&   in_index,
                                 const GLdouble* in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Double,
                                         VKGL::GetSetArgumentType::Float,
                                         2,
                                         false, /* in_normalized */
                                         in_v_ptr);
}

void vkglVertexAttrib2dv_with_validation(VKGL::Context*  in_context_ptr,
                                         const GLuint&   in_index,
                                         const GLdouble* in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttrib2dv_execute(in_context_ptr,
                                    in_index,
                                    in_v_ptr);
    }
}

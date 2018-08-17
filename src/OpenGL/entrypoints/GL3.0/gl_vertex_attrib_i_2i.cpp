/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLint&   in_x,
                     const GLint&   in_y)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttribI2i(GLuint index,
                                              GLint  x,
                                              GLint  y)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI2i(dispatch_table_ptr->bound_context_ptr,
                                           index,
                                           x,
                                           y);
}

void vkglVertexAttribI2i_execute(VKGL::Context* in_context_ptr,
                                 const GLuint&  in_index,
                                 const GLint&   in_x,
                                 const GLint&   in_y)
{
    const GLint data[] =
    {
        in_x,
        in_y
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Int,
                                         VKGL::GetSetArgumentType::Int,
                                         2,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttribI2i_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLint&   in_x,
                                         const GLint&   in_y)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y) )
    {
        vkglVertexAttribI2i_execute(in_context_ptr,
                                    in_index,
                                    in_x,
                                    in_y);
    }
}

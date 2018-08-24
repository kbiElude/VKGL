/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLint&   in_z,
                     const GLint&   in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglVertexAttribI4i(GLuint index,
                                                GLint  x,
                                                GLint  y,
                                                GLint  z,
                                                GLint  w)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI4i(dispatch_table_ptr->bound_context_ptr,
                                           index,
                                           x,
                                           y,
                                           z,
                                           w);
}

void vkglVertexAttribI4i_execute(VKGL::Context* in_context_ptr,
                                 const GLuint&  in_index,
                                 const GLint&   in_x,
                                 const GLint&   in_y,
                                 const GLint&   in_z,
                                 const GLint&   in_w)
{
    const GLint data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w,
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Int,
                                         VKGL::GetSetArgumentType::Int,
                                         4,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttribI4i_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLint&   in_x,
                                         const GLint&   in_y,
                                         const GLint&   in_z,
                                         const GLint&   in_w)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z,
                 in_w) )
    {
        vkglVertexAttribI4i_execute(in_context_ptr,
                                    in_index,
                                    in_x,
                                    in_y,
                                    in_z,
                                    in_w);
    }
}

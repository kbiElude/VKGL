/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLint&     in_x,
                     const GLint&     in_y,
                     const GLint&     in_z,
                     const GLint&     in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI4i(GLuint index,
                                               GLint  x,
                                               GLint  y,
                                               GLint  z,
                                               GLint  w)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttribI4i(index=[%u] x=[%d] y=[%d] z=[%d] w=[%d])",
               index,
               x,
               y,
               z,
               w);

    dispatch_table_ptr->pGLVertexAttribI4i(dispatch_table_ptr->bound_context_ptr,
                                           index,
                                           x,
                                           y,
                                           z,
                                           w);
}

static void vkglVertexAttribI4i_execute(OpenGL::Context* in_context_ptr,
                                        const GLuint&    in_index,
                                        const GLint&     in_x,
                                        const GLint&     in_y,
                                        const GLint&     in_z,
                                        const GLint&     in_w)
{
    const GLint data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w,
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Int,
                                         OpenGL::GetSetArgumentType::Int,
                                         4,     /* in_n_components */
                                         false, /* in_normalized   */
                                         data);
}

void OpenGL::vkglVertexAttribI4i_with_validation(OpenGL::Context* in_context_ptr,
                                                 const GLuint&    in_index,
                                                 const GLint&     in_x,
                                                 const GLint&     in_y,
                                                 const GLint&     in_z,
                                                 const GLint&     in_w)
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

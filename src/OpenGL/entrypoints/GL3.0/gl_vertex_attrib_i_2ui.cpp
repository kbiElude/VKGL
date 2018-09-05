/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLuint&    in_x,
                     const GLuint&    in_y)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI2ui(GLuint index,
                                                GLuint x,
                                                GLuint y)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttribI2ui(index=[%u] x=[%u] y=[%u])",
               index,
               x,
               y);

    dispatch_table_ptr->pGLVertexAttribI2ui(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x,
                                            y);
}

static void vkglVertexAttribI2ui_execute(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_index,
                                         const GLuint&    in_x,
                                         const GLuint&    in_y)
{
    const GLuint data[] =
    {
        in_x,
        in_y
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         2,     /* in_n_components */
                                         false, /* in_normalized   */
                                         data);
}

void OpenGL::vkglVertexAttribI2ui_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLuint&    in_index,
                                                  const GLuint&    in_x,
                                                  const GLuint&    in_y)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y) )
    {
        vkglVertexAttribI2ui_execute(in_context_ptr,
                                     in_index,
                                     in_x,
                                     in_y);
    }
}

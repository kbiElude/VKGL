/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLuint&    in_x,
                     const GLuint&    in_y,
                     const GLuint&    in_z)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI3ui(GLuint index,
                                                GLuint x,
                                                GLuint y,
                                                GLuint z)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttribI3ui(index=[%u] x=[%u] y=[%u] z=[%u])",
               index,
               x,
               y,
               z);

    dispatch_table_ptr->pGLVertexAttribI3ui(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x,
                                            y,
                                            z);
}

static void vkglVertexAttribI3ui_execute(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_index,
                                         const GLuint&    in_x,
                                         const GLuint&    in_y,
                                         const GLuint&    in_z)
{
    const GLuint data[] =
    {
        in_x,
        in_y,
        in_z,
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         3,
                                         false, /* in_normalized */
                                         data);
}

void OpenGL::vkglVertexAttribI3ui_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLuint&    in_index,
                                                  const GLint&     in_x,
                                                  const GLint&     in_y,
                                                  const GLint&     in_z)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z) )
    {
        vkglVertexAttribI3ui_execute(in_context_ptr,
                                     in_index,
                                     in_x,
                                     in_y,
                                     in_z);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLuint&  in_x,
                     const GLuint&  in_y,
                     const GLuint&  in_z,
                     const GLuint&  in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI4ui(GLuint index,
                                                GLuint x,
                                                GLuint y,
                                                GLuint z,
                                                GLuint w)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI4ui(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x,
                                            y,
                                            z,
                                            w);
}

static void vkglVertexAttribI4ui_execute(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLuint&  in_x,
                                         const GLuint&  in_y,
                                         const GLuint&  in_z,
                                         const GLuint&  in_w)
{
    const GLuint data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w,
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         4,
                                         false, /* in_normalized */
                                         data);
}

void OpenGL::vkglVertexAttribI4ui_with_validation(VKGL::Context* in_context_ptr,
                                                  const GLuint&  in_index,
                                                  const GLuint&  in_x,
                                                  const GLuint&  in_y,
                                                  const GLuint&  in_z,
                                                  const GLuint&  in_w)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z,
                 in_w) )
    {
        vkglVertexAttribI4ui_execute(in_context_ptr,
                                     in_index,
                                     in_x,
                                     in_y,
                                     in_z,
                                     in_w);
    }
}

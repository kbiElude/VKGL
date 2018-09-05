/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLuint&    in_x)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI1ui(GLuint index,
                                                GLuint x)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttribI1ui(index=[%u] x=[%u])",
               index,
               x);

    dispatch_table_ptr->pGLVertexAttribI1ui(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x);
}

static void vkglVertexAttribI1ui_execute(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_index,
                                         const GLuint&    in_x)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Float,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         1,     /* in_n_components */
                                         false, /* in_normalized   */
                                        &in_x);
}

void OpenGL::vkglVertexAttribI1ui_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLuint&    in_index,
                                                  const GLuint&    in_x)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x) )
    {
        vkglVertexAttribI1ui_execute(in_context_ptr,
                                     in_index,
                                     in_x);
    }
}

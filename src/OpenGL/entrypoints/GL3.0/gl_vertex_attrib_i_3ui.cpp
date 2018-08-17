/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLuint&  in_x,
                     const GLuint&  in_y,
                     const GLuint&  in_z)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttribI3ui(GLuint index,
                                               GLuint x,
                                               GLuint y,
                                               GLuint z)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI3ui(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x,
                                            y,
                                            z);
}

void vkglVertexAttribI3ui_execute(VKGL::Context* in_context_ptr,
                                  const GLuint&  in_index,
                                  const GLuint&  in_x,
                                  const GLuint&  in_y,
                                  const GLuint&  in_z)
{
    const GLuint data[] =
    {
        in_x,
        in_y,
        in_z,
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         3,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttribI3i_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLint&   in_x,
                                         const GLint&   in_y,
                                         const GLint&   in_z)
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

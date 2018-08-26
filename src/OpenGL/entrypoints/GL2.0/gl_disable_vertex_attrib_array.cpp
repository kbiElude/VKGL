/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_disable_vertex_attrib_array.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglDisableVertexAttribArray(GLuint index)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDisableVertexAttribArray(dispatch_table_ptr->bound_context_ptr,
                                                    index);
}

void vkglDisableVertexAttribArray_execute(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_index)
{
    in_context_ptr->disable_vertex_attrib_array(in_index);
}

void vkglDisableVertexAttribArray_with_validation(VKGL::Context* in_context_ptr,
                                                  const GLuint&  in_index)
{
    if (validate(in_context_ptr,
                 in_index) )
    {
        vkglDisableVertexAttribArray_execute(in_context_ptr,
                                             in_index);
    }
}

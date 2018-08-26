/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_bind_vertex_array.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_array)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglBindVertexArray(GLuint array)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindVertexArray(dispatch_table_ptr->bound_context_ptr,
                                           array);
}

void vkglBindVertexArray_execute(VKGL::Context* in_context_ptr,
                                 const GLuint&  in_array)
{
    in_context_ptr->bind_vertex_array(in_array);
}

void vkglBindVertexArray_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_array)
{
    if (validate(in_context_ptr,
                 in_array) )
    {
        vkglBindVertexArray_execute(in_context_ptr,
                                    in_array);
    }
}

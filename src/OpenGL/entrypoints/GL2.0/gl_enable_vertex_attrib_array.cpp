/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_enable_vertex_attrib_array.h"
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

VKGL_API void VKGL_APIENTRY glEnableVertexAttribArray(GLuint index)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEnableVertexAttribArray(dispatch_table_ptr->bound_context_ptr,
                                                   index);
}

void vkglEnableVertexAttribArray_execute(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index)
{
    in_context_ptr->enable_vertex_attrib_array(in_index);
}

void vkglEnableVertexAttribArray_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLuint&  in_index)
{
    if (validate(in_context_ptr,
                 in_index) )
    {
        vkglEnableVertexAttribArray_execute(in_context_ptr,
                                            in_index);
    }
}

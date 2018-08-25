/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_gen_vertex_arrays.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     GLuint*        out_arrays_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGenVertexArrays(GLsizei n,
                                       GLuint* arrays)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenVertexArrays(dispatch_table_ptr->bound_context_ptr,
                                           n,
                                           arrays);
}

void vkglGenVertexArrays_execute(VKGL::Context* in_context_ptr,
                                 const GLsizei& in_n,
                                 GLuint*        out_arrays_ptr)
{
    in_context_ptr->gen_vertex_arrays(in_n,
                                      out_arrays_ptr);
}

void vkglGenVertexArrays_with_validation(VKGL::Context* in_context_ptr,
                                         const GLsizei& in_n,
                                         GLuint*        out_arrays_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 out_arrays_ptr) )
    {
        vkglGenVertexArrays_execute(in_context_ptr,
                                    in_n,
                                    out_arrays_ptr);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_delete_vertex_arrays.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLsizei&   in_n,
                     const GLuint*    in_arrays_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteVertexArrays(GLsizei       n,
                                                  const GLuint* arrays)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDeleteVertexArrays(n=[%d] arrays=[%p])",
               static_cast<int32_t>(n),
               arrays);

    dispatch_table_ptr->pGLDeleteVertexArrays(dispatch_table_ptr->bound_context_ptr,
                                              n,
                                              arrays);
}

static void vkglDeleteVertexArrays_execute(OpenGL::Context* in_context_ptr,
                                           const GLsizei&   in_n,
                                           const GLuint*    in_arrays_ptr)
{
    in_context_ptr->delete_vertex_arrays(in_n,
                                         in_arrays_ptr);
}

void OpenGL::vkglDeleteVertexArrays_with_validation(OpenGL::Context* in_context_ptr,
                                                    const GLsizei&   in_n,
                                                    const GLuint*    in_arrays_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_arrays_ptr) )
    {
        vkglDeleteVertexArrays_execute(in_context_ptr,
                                       in_n,
                                       in_arrays_ptr);
    }
}

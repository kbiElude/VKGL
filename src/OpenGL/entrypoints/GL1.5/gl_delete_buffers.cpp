/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_delete_buffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     const GLuint*  in_buffers)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glDeleteBuffers(GLsizei       n,
                                            const GLuint* buffers)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDeleteBuffers(dispatch_table_ptr->bound_context_ptr,
                                         n,
                                         buffers);
}

void vkglDeleteBuffers_execute(VKGL::Context* in_context_ptr,
                               const GLsizei& in_n,
                               const GLuint*  in_buffers)
{
    in_context_ptr->delete_buffers(in_n,
                                   in_buffers);
}

void vkglDeleteBuffers_with_validation(VKGL::Context* in_context_ptr,
                                       const GLsizei& in_n,
                                       const GLuint*  in_buffers)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_buffers) )
    {
        vkglDeleteBuffers_execute(in_context_ptr,
                                  in_n,
                                  in_buffers);
    }
}
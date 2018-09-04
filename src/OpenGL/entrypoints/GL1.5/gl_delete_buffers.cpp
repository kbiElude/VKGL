/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_delete_buffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLsizei&   in_n,
                     const GLuint*    in_buffers)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteBuffers(GLsizei       n,
                                             const GLuint* buffers)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDeleteBuffers(n=[%d] buffers=[%p])",
               static_cast<int32_t>(n),
               buffers);

    dispatch_table_ptr->pGLDeleteBuffers(dispatch_table_ptr->bound_context_ptr,
                                         n,
                                         buffers);
}

static void vkglDeleteBuffers_execute(OpenGL::Context* in_context_ptr,
                                      const GLsizei&   in_n,
                                      const GLuint*    in_buffers)
{
    in_context_ptr->delete_buffers(in_n,
                                   in_buffers);
}

void OpenGL::vkglDeleteBuffers_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLsizei&   in_n,
                                               const GLuint*    in_buffers)
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
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_delete_renderbuffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     const GLuint*  in_renderbuffers_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteRenderbuffers(GLsizei      n,
                                                   const GLuint* renderbuffers)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDeleteRenderbuffers(dispatch_table_ptr->bound_context_ptr,
                                               n,
                                               renderbuffers);
}

static void vkglDeleteRenderbuffers_execute(VKGL::Context* in_context_ptr,
                                            const GLsizei& in_n,
                                            const GLuint*  in_renderbuffers_ptr)
{
    in_context_ptr->delete_renderbuffers(in_n,
                                         in_renderbuffers_ptr);
}

void OpenGL::vkglDeleteRenderbuffers_with_validation(VKGL::Context* in_context_ptr,
                                                     const GLsizei& in_n,
                                                     const GLuint*  in_renderbuffers_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_renderbuffers_ptr) )
    {
        vkglDeleteRenderbuffers_execute(in_context_ptr,
                                        in_n,
                                        in_renderbuffers_ptr);
    }
}

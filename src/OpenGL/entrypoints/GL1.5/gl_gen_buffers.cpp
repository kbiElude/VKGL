/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_gen_buffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     GLuint*        out_buffers_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGenBuffers(GLsizei n,
                                          GLuint* buffers)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenBuffers(dispatch_table_ptr->bound_context_ptr,
                                      n,
                                      buffers);
}

static void vkglGenBuffers_execute(VKGL::Context* in_context_ptr,
                                   const GLsizei& in_n,
                                   GLuint*        out_buffers_ptr)
{
    in_context_ptr->gen_buffers(in_n,
                                out_buffers_ptr);
}

void OpenGL::vkglGenBuffers_with_validation(VKGL::Context* in_context_ptr,
                                            const GLsizei& in_n,
                                            GLuint*        out_buffers_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 out_buffers_ptr) )
    {
        vkglGenBuffers_execute(in_context_ptr,
                               in_n,
                               out_buffers_ptr);
    }
}

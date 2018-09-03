/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_gen_renderbuffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLsizei&   in_n,
                     GLuint*          out_renderbuffers_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGenRenderbuffers(GLsizei n,
                                                GLuint* renderbuffers)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenRenderbuffers(dispatch_table_ptr->bound_context_ptr,
                                            n,
                                            renderbuffers);
}

static void vkglGenRenderbuffers_execute(OpenGL::Context* in_context_ptr,
                                         const GLsizei&   in_n,
                                         GLuint*          out_renderbuffers_ptr)
{
    in_context_ptr->gen_renderbuffers(in_n,
                                      out_renderbuffers_ptr);
}

void OpenGL::vkglGenRenderbuffers_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLsizei&   in_n,
                                                  GLuint*          out_renderbuffers_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 out_renderbuffers_ptr) )
    {
        vkglGenRenderbuffers_execute(in_context_ptr,
                                     in_n,
                                     out_renderbuffers_ptr);
    }
}

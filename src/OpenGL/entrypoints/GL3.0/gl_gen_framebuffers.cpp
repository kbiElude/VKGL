/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_gen_framebuffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     GLuint*        out_framebuffers_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglGenFramebuffers(GLsizei n,
                                                GLuint* framebuffers)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenFramebuffers(dispatch_table_ptr->bound_context_ptr,
                                           n,
                                           framebuffers);
}

void vkglGenFramebuffers_execute(VKGL::Context* in_context_ptr,
                                 const GLsizei& in_n,
                                 GLuint*        out_framebuffers_ptr)
{
    in_context_ptr->gen_framebuffers(in_n,
                                     out_framebuffers_ptr);
}

void vkglGenFramebuffers_with_validation(VKGL::Context* in_context_ptr,
                                         const GLsizei& in_n,
                                         GLuint*        out_framebuffers_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 out_framebuffers_ptr) )
    {
        vkglGenFramebuffers_execute(in_context_ptr,
                                    in_n,
                                    out_framebuffers_ptr);
    }
}

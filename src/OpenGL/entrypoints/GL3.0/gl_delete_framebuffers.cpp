/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_delete_framebuffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     const GLuint*  in_framebuffers_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteFramebuffers(GLsizei       n,
                                                  const GLuint* framebuffers)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDeleteFramebuffers(dispatch_table_ptr->bound_context_ptr,
                                              n,
                                              framebuffers);
}

static void vkglDeleteFramebuffers_execute(VKGL::Context* in_context_ptr,
                                           const GLsizei& in_n,
                                           const GLuint*  in_framebuffers_ptr)
{
    in_context_ptr->delete_framebuffers(in_n,
                                        in_framebuffers_ptr);
}

void OpenGL::vkglDeleteFramebuffers_with_validation(VKGL::Context* in_context_ptr,
                                                    const GLsizei& in_n,
                                                    const GLuint*  in_framebuffers_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_framebuffers_ptr) )
    {
        vkglDeleteFramebuffers_execute(in_context_ptr,
                                       in_n,
                                       in_framebuffers_ptr);
    }
}

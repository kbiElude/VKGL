/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_is_framebuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_framebuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglIsFramebuffer(GLuint framebuffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glIsFramebuffer(framebuffer=[%u])",
               framebuffer);

    return dispatch_table_ptr->pGLIsFramebuffer(dispatch_table_ptr->bound_context_ptr,
                                                framebuffer) ? GL_TRUE
                                                             : GL_FALSE;
}

static bool vkglIsFramebuffer_execute(OpenGL::Context* in_context_ptr,
                                      const GLuint&    in_framebuffer)
{
    return in_context_ptr->is_framebuffer(in_framebuffer);
}

bool OpenGL::vkglIsFramebuffer_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLuint&    in_framebuffer)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_framebuffer) )
    {
        result = vkglIsFramebuffer_execute(in_context_ptr,
                                           in_framebuffer);
    }

    return result;
}


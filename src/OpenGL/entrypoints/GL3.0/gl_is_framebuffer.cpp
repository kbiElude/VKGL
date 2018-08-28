/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_is_framebuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_framebuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglIsFramebuffer(GLuint framebuffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsFramebuffer(dispatch_table_ptr->bound_context_ptr,
                                                framebuffer) == GL_TRUE;
}

static bool vkglIsFramebuffer_execute(VKGL::Context* in_context_ptr,
                                      const GLuint&  in_framebuffer)
{
    return in_context_ptr->is_framebuffer(in_framebuffer) == GL_TRUE;
}

bool OpenGL::vkglIsFramebuffer_with_validation(VKGL::Context* in_context_ptr,
                                               const GLuint&  in_framebuffer)
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


/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_is_renderbuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_renderbuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglIsRenderbuffer(GLuint renderbuffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glIsRenderbuffer(renderbuffer=[%u])",
               renderbuffer);

    return dispatch_table_ptr->pGLIsRenderbuffer(dispatch_table_ptr->bound_context_ptr,
                                                 renderbuffer) == GL_TRUE;
}

static bool vkglIsRenderbuffer_execute(OpenGL::Context* in_context_ptr,
                                       const GLuint&    in_renderbuffer)
{
    return in_context_ptr->is_renderbuffer(in_renderbuffer) == GL_TRUE;
}

bool OpenGL::vkglIsRenderbuffer_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_renderbuffer)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_renderbuffer) )
    {
        result = vkglIsRenderbuffer_execute(in_context_ptr,
                                            in_renderbuffer);
    }

    return result;
}


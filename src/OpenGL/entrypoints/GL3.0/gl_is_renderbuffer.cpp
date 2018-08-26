/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_is_renderbuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_renderbuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY vkglIsRenderbuffer(GLuint renderbuffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsRenderbuffer(dispatch_table_ptr->bound_context_ptr,
                                                 renderbuffer) == GL_TRUE;
}

bool vkglIsRenderbuffer_execute(VKGL::Context* in_context_ptr,
                                const GLuint&  in_renderbuffer)
{
    return in_context_ptr->is_renderbuffer(in_renderbuffer) == GL_TRUE;
}

bool vkglIsRenderbuffer_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_renderbuffer)
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


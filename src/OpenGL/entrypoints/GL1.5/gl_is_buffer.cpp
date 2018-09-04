/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_is_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_buffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglIsBuffer(GLuint buffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glIsBuffer(buffer=[%u])",
               buffer);

    return dispatch_table_ptr->pGLIsBuffer(dispatch_table_ptr->bound_context_ptr,
                                           buffer) ? GL_TRUE
                                                   : GL_FALSE;
}

static bool vkglIsBuffer_execute(OpenGL::Context* in_context_ptr,
                                 const GLuint&    in_buffer)
{
    return in_context_ptr->is_buffer(in_buffer);
}

bool OpenGL::vkglIsBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_buffer)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_buffer) )
    {
        result = vkglIsBuffer_execute(in_context_ptr,
                                      in_buffer);
    }

    return result;
}

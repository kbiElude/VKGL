/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_create_program.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLuint VKGL_APIENTRY OpenGL::vkglCreateProgram()
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCreateProgram()");

    return dispatch_table_ptr->pGLCreateProgram(dispatch_table_ptr->bound_context_ptr);
}

static GLuint vkglCreateProgram_execute(OpenGL::Context* in_context_ptr)
{
    return in_context_ptr->create_program();
}

GLuint OpenGL::vkglCreateProgram_with_validation(OpenGL::Context* in_context_ptr)
{
    GLuint result = 0;

    if (validate(in_context_ptr) )
    {
        result = vkglCreateProgram_execute(in_context_ptr);
    }

    return result;
}

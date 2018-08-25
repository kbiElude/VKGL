/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_create_program.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLuint VKGL_APIENTRY vkglCreateProgram()
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLCreateProgram(dispatch_table_ptr->bound_context_ptr);
}

GLuint vkglCreateProgram_execute(VKGL::Context* in_context_ptr)
{
    return in_context_ptr->create_program();
}

GLuint vkglCreateProgram_with_validation(VKGL::Context* in_context_ptr)
{
    GLuint result = 0;

    if (validate(in_context_ptr) )
    {
        result = vkglCreateProgram_execute(in_context_ptr);
    }

    return result;
}

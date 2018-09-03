/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_is_program.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglIsProgram(GLuint program)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsProgram(dispatch_table_ptr->bound_context_ptr,
                                            program) == GL_TRUE;
}

static bool vkglIsProgram_execute(OpenGL::Context* in_context_ptr,
                                  const GLuint&    in_program)
{
    return in_context_ptr->is_program(in_program);
}

bool OpenGL::vkglIsProgram_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLuint&    in_program)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_program) )
    {
        result = vkglIsProgram_execute(in_context_ptr,
                                       in_program);
    }

    return result;
}


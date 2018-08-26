/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_use_program.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglUseProgram(GLuint program)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUseProgram(dispatch_table_ptr->bound_context_ptr,
                                      program);
}

void vkglUseProgram_execute(VKGL::Context* in_context_ptr,
                            const GLuint&  in_program)
{
    in_context_ptr->use_program(in_program);
}

void vkglUseProgram_with_validation(VKGL::Context* in_context_ptr,
                                    const GLuint&  in_program)
{
    if (validate(in_context_ptr,
                 in_program) )
    {
        vkglUseProgram_execute(in_context_ptr,
                               in_program);
    }
}

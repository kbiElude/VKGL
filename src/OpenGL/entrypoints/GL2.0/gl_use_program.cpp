/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_use_program.h"
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

void VKGL_APIENTRY OpenGL::vkglUseProgram(GLuint program)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glUseProgram(program=[%u])",
               program);

    dispatch_table_ptr->pGLUseProgram(dispatch_table_ptr->bound_context_ptr,
                                      program);
}

static void vkglUseProgram_execute(OpenGL::Context* in_context_ptr,
                                   const GLuint&    in_program)
{
    in_context_ptr->use_program(in_program);
}

void OpenGL::vkglUseProgram_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_program)
{
    if (validate(in_context_ptr,
                 in_program) )
    {
        vkglUseProgram_execute(in_context_ptr,
                               in_program);
    }
}

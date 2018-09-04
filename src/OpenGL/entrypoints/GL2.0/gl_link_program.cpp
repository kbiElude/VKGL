/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_link_program.h"
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

void VKGL_APIENTRY OpenGL::vkglLinkProgram(GLuint program)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glLinkProgram(program=[%u])",
               program);

    return dispatch_table_ptr->pGLLinkProgram(dispatch_table_ptr->bound_context_ptr,
                                              program);
}

static bool vkglLinkProgram_execute(OpenGL::Context* in_context_ptr,
                                    const GLuint&    in_program)
{
    return in_context_ptr->link_program(in_program);
}

bool OpenGL::vkglLinkProgram_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLuint&    in_program)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_program) )
    {
        result = vkglLinkProgram_execute(in_context_ptr,
                                         in_program);
    }

    return result;
}


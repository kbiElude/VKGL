/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_uniform_location.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program,
                     const GLchar*    in_name)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLint VKGL_APIENTRY OpenGL::vkglGetUniformLocation(GLuint        program,
                                                   const GLchar* name)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetUniformLocation(program=[%u] name=[%s])",
               program,
               name);

    return dispatch_table_ptr->pGLGetUniformLocation(dispatch_table_ptr->bound_context_ptr,
                                                     program,
                                                     name);
}

static GLint vkglGetUniformLocation_execute(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_program,
                                            const GLchar*    in_name)
{
    return in_context_ptr->get_uniform_location(in_program,
                                                in_name);
}

GLint OpenGL::vkglGetUniformLocation_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLuint&    in_program,
                                                     const GLchar*    in_name)
{
    GLint result = -1;

    if (validate(in_context_ptr,
                 in_program,
                 in_name) )
    {
        result = vkglGetUniformLocation_execute(in_context_ptr,
                                                in_program,
                                                in_name);
    }

    return result;
}

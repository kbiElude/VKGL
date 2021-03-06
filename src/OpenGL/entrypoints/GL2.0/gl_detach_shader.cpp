/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_detach_shader.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program,
                     const GLuint&    in_shader)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDetachShader(GLuint program,
                                            GLuint shader)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDetachShader(program=[%d] shader=[%d])",
               program,
               shader);

    dispatch_table_ptr->pGLDetachShader(dispatch_table_ptr->bound_context_ptr,
                                        program,
                                        shader);
}

static void vkglDetachShader_execute(OpenGL::Context* in_context_ptr,
                                     const GLuint&    in_program,
                                     const GLuint&    in_shader)
{
    in_context_ptr->detach_shader(in_program,
                                  in_shader);
}

void OpenGL::vkglDetachShader_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_program,
                                              const GLuint&    in_shader)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_shader) )
    {
        vkglDetachShader_execute(in_context_ptr,
                                 in_program,
                                 in_shader);
    }
}


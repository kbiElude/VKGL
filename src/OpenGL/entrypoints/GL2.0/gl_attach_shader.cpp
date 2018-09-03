/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_attach_shader.h"
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

void VKGL_APIENTRY OpenGL::vkglAttachShader(GLuint program,
                                            GLuint shader)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLAttachShader(dispatch_table_ptr->bound_context_ptr,
                                        program,
                                        shader);
}

static void vkglAttachShader_execute(OpenGL::Context* in_context_ptr,
                                     const GLuint&    in_program,
                                     const GLuint&    in_shader)
{
    in_context_ptr->attach_shader(in_program,
                                  in_shader);
}

void OpenGL::vkglAttachShader_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_program,
                                              const GLuint&    in_shader)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_shader) )
    {
        vkglAttachShader_execute(in_context_ptr,
                                 in_program,
                                 in_shader);
    }
}


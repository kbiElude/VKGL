/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_attach_shader.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_shader)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglAttachShader(GLuint program,
                                             GLuint shader)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLAttachShader(dispatch_table_ptr->bound_context_ptr,
                                        program,
                                        shader);
}

void vkglAttachShader_execute(VKGL::Context* in_context_ptr,
                              const GLuint&  in_program,
                              const GLuint&  in_shader)
{
    in_context_ptr->attach_shader(in_program,
                                  in_shader);
}

void vkglAttachShader_with_validation(VKGL::Context* in_context_ptr,
                                      const GLuint&  in_program,
                                      const GLuint&  in_shader)
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


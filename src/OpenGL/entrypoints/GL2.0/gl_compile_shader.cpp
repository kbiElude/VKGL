/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_compile_shader.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_shader)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglCompileShader(GLuint shader)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCompileShader(shader=[%d])",
               shader);

    dispatch_table_ptr->pGLCompileShader(dispatch_table_ptr->bound_context_ptr,
                                        shader);
}

static void vkglCompileShader_execute(OpenGL::Context* in_context_ptr,
                                      const GLuint&    in_shader)
{
    in_context_ptr->compile_shader(in_shader);
}

void OpenGL::vkglCompileShader_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLuint&    in_shader)
{
    if (validate(in_context_ptr,
                 in_shader) )
    {
        vkglCompileShader_execute(in_context_ptr,
                                  in_shader);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_compile_shader.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_shader)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glCompileShader(GLuint shader)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->compile_shader(dispatch_table_ptr->bound_context_ptr,
                                       shader);
}

void vkglCompileShader_execute(VKGL::Context* in_context_ptr,
                               const GLuint&  in_shader)
{
    in_context_ptr->compile_shader(in_shader);
}

void vkglCompileShader_with_validation(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_shader)
{
    if (validate(in_context_ptr,
                 in_shader) )
    {
        vkglCompileShader_execute(in_context_ptr,
                                  in_shader);
    }
}

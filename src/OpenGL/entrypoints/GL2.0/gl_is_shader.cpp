/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_is_shader.h"
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

GLboolean VKGL_APIENTRY vkglIsShader(GLuint shader)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsShader(dispatch_table_ptr->bound_context_ptr,
                                           shader) == GL_TRUE;
}

bool vkglIsShader_execute(VKGL::Context* in_context_ptr,
                          const GLuint&  in_shader)
{
    return in_context_ptr->is_shader(in_shader);
}

bool vkglIsShader_with_validation(VKGL::Context* in_context_ptr,
                                  const GLuint&  in_shader)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_shader) )
    {
        result = vkglIsShader_execute(in_context_ptr,
                                      in_shader);
    }

    return result;
}


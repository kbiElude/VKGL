/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_is_shader.h"
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

GLboolean VKGL_APIENTRY OpenGL::vkglIsShader(GLuint shader)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsShader(dispatch_table_ptr->bound_context_ptr,
                                           shader) == GL_TRUE;
}

static bool vkglIsShader_execute(OpenGL::Context* in_context_ptr,
                                 const GLuint&    in_shader)
{
    return in_context_ptr->is_shader(in_shader);
}

bool OpenGL::vkglIsShader_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_shader)
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


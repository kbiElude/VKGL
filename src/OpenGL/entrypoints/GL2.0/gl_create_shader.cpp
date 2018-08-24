/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_create_shader.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_type)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API GLuint VKGL_APIENTRY vkglCreateShader(GLenum type)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLCreateShaderr(dispatch_table_ptr->bound_context_ptr,
                                                type);
}

GLuint vkglCreateShader_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_type)
{
    const auto type_vkgl = VKGL::Utils::get_shader_type_for_gl_enum(in_type);

    return in_context_ptr->create_shader(type_vkgl);
}

GLuint vkglCreateShader_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_type)
{
    GLuint result = 0;

    if (validate(in_context_ptr,
                 in_type) )
    {
        result = vkglCreateShader_execute(in_context_ptr,
                                          in_type);
    }

    return result;
}

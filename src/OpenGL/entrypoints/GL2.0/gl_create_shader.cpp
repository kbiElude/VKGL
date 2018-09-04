/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_create_shader.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_type)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLuint VKGL_APIENTRY OpenGL::vkglCreateShader(GLenum type)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glCreateShader(type=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(type) );

    return dispatch_table_ptr->pGLCreateShader(dispatch_table_ptr->bound_context_ptr,
                                               type);
}

static GLuint vkglCreateShader_execute(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_type)
{
    const auto type_vkgl = OpenGL::Utils::get_shader_type_for_gl_enum(in_type);

    return in_context_ptr->create_shader(type_vkgl);
}

GLuint OpenGL::vkglCreateShader_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_type)
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

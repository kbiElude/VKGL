/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_shader_source.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_shader,
                     const GLsizei& in_buf_size,
                     GLsizei*       inout_length_ptr,
                     GLchar*        out_source_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGetShaderSource(GLuint   shader,
                                       GLsizei  bufSize,
                                       GLsizei* length,
                                       GLchar*  source)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetShaderSource(dispatch_table_ptr->bound_context_ptr,
                                           shader,
                                           bufSize,
                                           length,
                                           source);
}

void vkglGetShaderSource_execute(VKGL::Context* in_context_ptr,
                                 const GLuint&  in_shader,
                                 const GLsizei& in_buf_size,
                                 GLsizei*       inout_length_ptr,
                                 GLchar*        out_source_ptr)
{
    in_context_ptr->get_shader_source(in_shader,
                                      in_buf_size,
                                      inout_length_ptr,
                                      out_source_ptr);
}

void vkglGetShaderSource_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_shader,
                                         const GLsizei& in_buf_size,
                                         GLsizei*       inout_length_ptr,
                                         GLchar*        out_source_ptr)
{
    if (validate(in_context_ptr,
                 in_shader,
                 in_buf_size,
                 inout_length_ptr,
                 out_source_ptr) )
    {
        vkglGetShaderSource_execute(in_context_ptr,
                                    in_shader,
                                    in_buf_size,
                                    inout_length_ptr,
                                    out_source_ptr);
    }
}

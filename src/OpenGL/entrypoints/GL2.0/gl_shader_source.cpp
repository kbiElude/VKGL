/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_shader_source.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context*     in_context_ptr,
                     const GLuint&        in_shader,
                     const GLsizei&       in_count,
                     const GLchar* const* in_string_ptr_ptr,
                     const GLint*         in_length_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglShaderSource(GLuint               shader,
                                            GLsizei              count,
                                            const GLchar* const* string,
                                            const GLint*         length)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glShaderSource(shader=[%u] count=[%d] string=[%p] length=[%p])",
               shader,
               static_cast<int32_t>(count),
               string,
               length);

    dispatch_table_ptr->pGLShaderSource(dispatch_table_ptr->bound_context_ptr,
                                        shader,
                                        count,
                                        string,
                                        length);
}

static void vkglShaderSource_execute(OpenGL::Context*     in_context_ptr,
                                     const GLuint&        in_shader,
                                     const GLsizei&       in_count,
                                     const GLchar* const* in_string_ptr_ptr,
                                     const GLint*         in_length_ptr)
{
    in_context_ptr->shader_source(in_shader,
                                  in_count,
                                  in_string_ptr_ptr,
                                  in_length_ptr);
}

void OpenGL::vkglShaderSource_with_validation(OpenGL::Context*     in_context_ptr,
                                              const GLuint&        in_shader,
                                              const GLsizei&       in_count,
                                              const GLchar* const* in_string_ptr_ptr,
                                              const GLint*         in_length_ptr)
{
    if (validate(in_context_ptr,
                 in_shader,
                 in_count,
                 in_string_ptr_ptr,
                 in_length_ptr) )
    {
        vkglShaderSource_execute(in_context_ptr,
                                 in_shader,
                                 in_count,
                                 in_string_ptr_ptr,
                                 in_length_ptr);
    }
}

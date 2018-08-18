/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_name.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_uniform_index,
                     const GLsizei& in_buf_size,
                     GLsizei*       inout_length_ptr,
                     GLchar*        out_uniform_name_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glGetActiveUniformName(GLuint   program,
                                                   GLuint   uniformIndex,
                                                   GLsizei  bufSize,
                                                   GLsizei* length,
                                                   GLchar*  uniformName)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetActiveUniformName(dispatch_table_ptr->bound_context_ptr,
                                                program,
                                                uniformIndex,
                                                bufSize,
                                                length,
                                                uniformName);
}

void vkglGetActiveUniformName_execute(VKGL::Context* in_context_ptr,
                                      const GLuint&  in_program,
                                      const GLuint&  in_uniform_index,
                                      const GLsizei& in_buf_size,
                                      GLsizei*       inout_length_ptr,
                                      GLchar*        out_uniform_name_ptr)
{
    in_context_ptr->get_active_uniform_name(in_program,
                                            in_uniform_index,
                                            in_buf_size,
                                            inout_length_ptr,
                                            out_uniform_name_ptr);
}

void vkglGetActiveUniformName_with_validation(VKGL::Context* in_context_ptr,
                                              const GLuint&  in_program,
                                              const GLuint&  in_uniform_index,
                                              const GLsizei& in_buf_size,
                                              GLsizei*       inout_length_ptr,
                                              GLchar*        out_uniform_name_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_index,
                 in_buf_size,
                 inout_length_ptr,
                 out_uniform_name_ptr) )
    {
        vkglGetActiveUniformName_execute(in_context_ptr,
                                         in_program,
                                         in_uniform_index,
                                         in_buf_size,
                                         inout_length_ptr,
                                         out_uniform_name_ptr);
    }
}

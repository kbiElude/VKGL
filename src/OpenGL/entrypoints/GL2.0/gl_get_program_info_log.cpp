/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_program_info_log.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLsizei& in_buf_size,
                     GLsizei*       inout_length_ptr,
                     GLchar*        out_info_log_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glGetProgramInfoLog(GLuint   program,
                                                GLsizei  bufSize,
                                                GLsizei* length,
                                                GLchar*  infoLog)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetProgramInfoLog(dispatch_table_ptr->bound_context_ptr,
                                             program,
                                             bufSize,
                                             length,
                                             infoLog);
}

void vkglGetProgramInfoLog_execute(VKGL::Context* in_context_ptr,
                                   const GLuint&  in_program,
                                   const GLsizei& in_buf_size,
                                   GLsizei*       inout_length_ptr,
                                   GLchar*        out_info_log_ptr)
{
    in_context_ptr->get_program_info_log(in_program,
                                         in_buf_size,
                                         inout_length_ptr,
                                         out_info_log_ptr);
}

void vkglGetProgramInfoLog_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_program,
                                           const GLsizei& in_buf_size,
                                           GLsizei*       inout_length_ptr,
                                           GLchar*        out_info_log_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_buf_size,
                 inout_length_ptr,
                 out_info_log_ptr) )
    {
        vkglGetProgramInfoLog_execute(in_context_ptr,
                                      in_program,
                                      in_buf_size,
                                      inout_length_ptr,
                                      out_info_log_ptr);
    }
}

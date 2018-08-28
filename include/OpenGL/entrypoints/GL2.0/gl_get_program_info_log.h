/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_PROGRAM_INFO_LOG_H
#define VKGL_GL_GET_PROGRAM_INFO_LOG_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetProgramInfoLog(GLuint   program,
                                             GLsizei  bufSize,
                                             GLsizei* length,
                                             GLchar*  infoLog);

    void vkglGetProgramInfoLog_with_validation(VKGL::Context* in_context_ptr,
                                               const GLuint&  in_program,
                                               const GLsizei& in_buf_size,
                                               GLsizei*       inout_length_ptr,
                                               GLchar*        out_info_log_ptr);
}

#endif /* VKGL_GL_GET_PROGRAM_INFO_LOG_H */
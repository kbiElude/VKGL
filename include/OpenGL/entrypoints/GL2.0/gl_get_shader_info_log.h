/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_SHADER_INFO_LOG_H
#define VKGL_GL_GET_SHADER_INFO_LOG_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetShaderInfoLog(GLuint   shader,
                                        GLsizei  bufSize,
                                        GLsizei* length,
                                        GLchar*  infoLog);

void vkglGetShaderInfoLog_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_shader,
                                          const GLsizei& in_buf_size,
                                          GLsizei*       inout_length_ptr,
                                          GLchar*        out_info_log_ptr);

#endif /* VKGL_GL_GET_SHADER_INFO_LOG_H */
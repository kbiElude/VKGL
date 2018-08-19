/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_SHADER_SOURCE_H
#define VKGL_GL_GET_SHADER_SOURCE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetShaderSource(GLuint   shader,
                                              GLsizei  bufSize,
                                              GLsizei* length,
                                              GLchar*  source);

void vkglGetShaderSource_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_shader,
                                         const GLsizei& in_buf_size,
                                         GLsizei*       inout_length_ptr,
                                         GLchar*        out_source_ptr);

#endif /* VKGL_GL_GET_SHADER_SOURCE_H */
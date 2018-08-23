/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_SHADER_INFO_LOG_H
#define VKGL_GL_GET_SHADER_INFO_LOG_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetShaderInfoLog(GLuint   shader,
                                                 GLsizei  bufSize,
                                                 GLsizei* length,
                                                 GLchar*  infoLog);


#endif /* VKGL_GL_GET_SHADER_INFO_LOG_H */
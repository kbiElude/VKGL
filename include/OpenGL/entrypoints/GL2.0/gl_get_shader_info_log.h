#ifndef VKGL_GL_GET_SHADER_INFO_LOG_H
#define VKGL_GL_GET_SHADER_INFO_LOG_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetShaderInfoLog(GLuint   shader,
                                               GLsizei  bufSize,
                                               GLsizei* length,
                                               GLchar*  infoLog);

#endif /* VKGL_GL_GET_SHADER_INFO_LOG_H */
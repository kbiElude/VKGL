#ifndef VKGL_GL_GET_SHADER_SOURCE_H
#define VKGL_GL_GET_SHADER_SOURCE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetShaderSource(GLuint   shader,
                                              GLsizei  bufSize,
                                              GLsizei* length,
                                              GLchar*  source);

#endif /* VKGL_GL_GET_SHADER_SOURCE_H */
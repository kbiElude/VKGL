#ifndef VKGL_GL_GET_PROGRAM_INFO_LOG_H
#define VKGL_GL_GET_PROGRAM_INFO_LOG_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetProgramInfoLog(GLuint   program,
                                                GLsizei  bufSize,
                                                GLsizei* length,
                                                GLchar*  infoLog);

#endif /* VKGL_GL_GET_PROGRAM_INFO_LOG_H */
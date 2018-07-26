#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveUniformName(GLuint   program,
                                                   GLuint   uniformIndex,
                                                   GLsizei  bufSize,
                                                   GLsizei* length,
                                                   GLchar*  uniformName);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H */
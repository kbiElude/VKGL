#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveUniform(GLuint   program,
                                               GLuint   index,
                                               GLsizei  bufSize,
                                               GLsizei* length,
                                               GLint*   size,
                                               GLenum*  type,
                                               GLchar*  name);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_H */
#ifndef VKGL_GL_UNIFORM_2UIV_H
#define VKGL_GL_UNIFORM_2UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform2uiv(GLint         location,
                                          GLsizei       count,
                                          const GLuint* value);

#endif /* VKGL_GL_UNIFORM_2UIV_H */
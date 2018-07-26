#ifndef VKGL_GL_GET_UNIFORM_LOCATION_H
#define VKGL_GL_GET_UNIFORM_LOCATION_H

#include "OpenGL/types.h"

VKGL_API GLint VKGL_APIENTRY glGetUniformLocation(GLuint        program,
                                                  const GLchar* name);

#endif /* VKGL_GL_GET_UNIFORM_LOCATION_H */
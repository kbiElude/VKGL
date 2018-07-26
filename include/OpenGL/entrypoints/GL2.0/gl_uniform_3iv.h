#ifndef VKGL_GL_UNIFORM_3IV_H
#define VKGL_GL_UNIFORM_3IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform3iv(GLint        location,
                                         GLsizei      count,
                                         const GLint* value);

#endif /* VKGL_GL_UNIFORM_3IV_H */
#ifndef VKGL_GL_UNIFORM_1IV_H
#define VKGL_GL_UNIFORM_1IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform1iv(GLint        location,
                                         GLsizei      count,
                                         const GLint* value);

#endif /* VKGL_GL_UNIFORM_1IV_H */
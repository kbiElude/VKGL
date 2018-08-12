/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_4IV_H
#define VKGL_GL_UNIFORM_4IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform4iv(GLint        location,
                                         GLsizei      count,
                                         const GLint* value);

#endif /* VKGL_GL_UNIFORM_4IV_H */
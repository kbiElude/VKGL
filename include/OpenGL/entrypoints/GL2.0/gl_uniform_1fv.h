/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_1FV_H
#define VKGL_GL_UNIFORM_1FV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform1fv(GLint          location,
                                         GLsizei        count,
                                         const GLfloat* value);

#endif /* VKGL_GL_UNIFORM_1FV_H */
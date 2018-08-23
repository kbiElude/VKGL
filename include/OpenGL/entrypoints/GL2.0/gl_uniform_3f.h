/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3F_H
#define VKGL_GL_UNIFORM_3F_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglUniform3f(GLint   location,
                                          GLfloat v0,
                                          GLfloat v1,
                                          GLfloat v2);

#endif /* VKGL_GL_UNIFORM_3F_H */
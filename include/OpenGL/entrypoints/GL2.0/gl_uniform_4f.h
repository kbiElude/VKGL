/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_4F_H
#define VKGL_GL_UNIFORM_4F_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform4f(GLint   location,
                                 GLfloat v0,
                                 GLfloat v1,
                                 GLfloat v2,
                                 GLfloat v3);

#endif /* VKGL_GL_UNIFORM_4F_H */
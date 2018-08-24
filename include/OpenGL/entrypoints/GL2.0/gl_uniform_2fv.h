/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_2FV_H
#define VKGL_GL_UNIFORM_2FV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform2fv(GLint          location,
                                  GLsizei        count,
                                  const GLfloat* value);

#endif /* VKGL_GL_UNIFORM_2FV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_MATRIX_2X3_FV_H
#define VKGL_GL_UNIFORM_MATRIX_2X3_FV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniformMatrix2x3fv(GLint          location,
                                          GLsizei        count,
                                          GLboolean      transpose,
                                          const GLfloat* value);

#endif /* VKGL_GL_UNIFORM_MATRIX_2X3_FV_H */
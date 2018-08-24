/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_MATRIX_3X2_FV_H
#define VKGL_GL_UNIFORM_MATRIX_3X2_FV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniformMatrix3x2fv(GLint          location,
                                          GLsizei        count,
                                          GLboolean      transpose,
                                          const GLfloat* value);

#endif /* VKGL_GL_UNIFORM_MATRIX_3X2_FV_H */
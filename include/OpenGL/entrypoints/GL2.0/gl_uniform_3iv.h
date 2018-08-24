/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3IV_H
#define VKGL_GL_UNIFORM_3IV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform3iv(GLint        location,
                                  GLsizei      count,
                                  const GLint* value);

#endif /* VKGL_GL_UNIFORM_3IV_H */
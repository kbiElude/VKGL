/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_2IV_H
#define VKGL_GL_UNIFORM_2IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglUniform2iv(GLint        location,
                                           GLsizei      count,
                                           const GLint* value);

#endif /* VKGL_GL_UNIFORM_2IV_H */
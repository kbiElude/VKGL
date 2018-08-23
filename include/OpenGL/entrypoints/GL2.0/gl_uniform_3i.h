/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3I_H
#define VKGL_GL_UNIFORM_3I_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglUniform3i(GLint location,
                                          GLint v0,
                                          GLint v1,
                                          GLint v2);

#endif /* VKGL_GL_UNIFORM_3I_H */
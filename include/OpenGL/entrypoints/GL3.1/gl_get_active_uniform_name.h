/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetActiveUniformName(GLuint   program,
                                            GLsizei* length,
                                            GLuint   uniformIndex,
                                            GLsizei  bufSize,
                                            GLchar*  uniformName);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H */
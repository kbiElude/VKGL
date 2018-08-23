/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetActiveUniformBlockName(GLuint   program,
                                                          GLuint   uniformBlockIndex,
                                                          GLsizei  bufSize,
                                                          GLsizei* length,
                                                          GLchar*  uniformBlockName);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H */
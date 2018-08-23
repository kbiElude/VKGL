/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H
#define VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H

#include "OpenGL/types.h"

VKGL_API GLuint VKGL_APIENTRY vkglGetUniformBlockIndex(GLuint        program,
                                                       const GLchar* uniformBlockName);

#endif /* VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H */
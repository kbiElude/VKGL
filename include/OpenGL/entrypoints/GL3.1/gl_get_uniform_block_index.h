/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H
#define VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H

#include "OpenGL/types.h"

VKGL_API GLuint VKGL_APIENTRY glGetUniformBlockIndex(GLuint        program,
                                                     const GLchar* uniformBlockName);

GLuint vkglGetUniformBlockIndex_with_validation(VKGL::Context* in_context_ptr,
                                                GLuint         in_program,
                                                const GLchar*  in_uniform_block_name);

#endif /* VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H */
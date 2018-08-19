/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_BLOCK_BINDING_H
#define VKGL_GL_UNIFORM_BLOCK_BINDING_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniformBlockBinding(GLuint program,
                                                  GLuint uniformBlockIndex,
                                                  GLuint uniformBlockBinding);

void vkglUniformBlockBinding_with_validation(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_program,
                                             const GLuint&  in_uniform_block_index,
                                             const GLuint&  in_uniform_block_binding);

#endif /* VKGL_GL_UNIFORM_BLOCK_BINDING_H */
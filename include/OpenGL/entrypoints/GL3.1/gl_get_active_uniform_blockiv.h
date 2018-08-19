/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_BLOCKIV_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_BLOCKIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveUniformBlockiv(GLuint program,
                                                      GLuint uniformBlockIndex,
                                                      GLenum pname,
                                                      GLint* params);

void vkglGetActiveUniformBlockiv_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLuint&  in_program,
                                                 const GLuint&  in_uniform_block_index,
                                                 const GLenum&  in_pname,
                                                 GLint*         out_params_ptr);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_BLOCKIV_H */
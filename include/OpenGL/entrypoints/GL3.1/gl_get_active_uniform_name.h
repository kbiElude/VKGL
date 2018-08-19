/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveUniformName(GLuint   program,
                                                   GLuint   uniformIndex,
                                                   GLsizei  bufSize,
                                                   GLsizei* length,
                                                   GLchar*  uniformName);

void vkglGetActiveUniformName_with_validation(VKGL::Context* in_context_ptr,
                                              const GLuint&  in_program,
                                              const GLuint&  in_uniform_index,
                                              const GLsizei& in_buf_size,
                                              GLsizei*       inout_length_ptr,
                                              GLchar*        out_uniform_name_ptr);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_NAME_H */
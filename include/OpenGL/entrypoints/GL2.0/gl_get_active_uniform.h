/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetActiveUniform(GLuint   program,
                                        GLuint   index,
                                        GLsizei  bufSize,
                                        GLsizei* length,
                                        GLint*   size,
                                        GLenum*  type,
                                        GLchar*  name);

void vkglGetActiveUniform_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_program,
                                          const GLuint&  in_index,
                                          const GLsizei& in_buf_size,
                                          GLsizei*       out_length_ptr,
                                          GLint*         out_size_ptr,
                                          GLenum*        out_type_ptr,
                                          GLchar*        out_name_ptr);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_H */
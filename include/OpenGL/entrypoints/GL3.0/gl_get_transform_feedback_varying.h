/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H
#define VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTransformFeedbackVarying(GLuint   program,
                                                          GLuint   index,
                                                          GLsizei  bufSize,
                                                          GLsizei* length,
                                                          GLsizei* size,
                                                          GLenum*  type,
                                                          GLchar*  name);

void vkglGetTransformFeedbackVarying_with_validation(VKGL::Context* in_context_ptr,
                                                     GLuint         in_program,
                                                     GLuint         in_index,
                                                     GLsizei        in_buf_size,
                                                     GLsizei*       out_length_ptr,
                                                     GLsizei*       out_size_ptr,
                                                     GLenum*        out_type_ptr,
                                                     GLchar*        out_name_ptr);

#endif /* VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H */
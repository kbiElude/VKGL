/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H
#define VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetTransformFeedbackVarying(GLuint   program,
                                                   GLuint   index,
                                                   GLsizei  bufSize,
                                                   GLsizei* length,
                                                   GLsizei* size,
                                                   GLenum*  type,
                                                   GLchar*  name);

#endif /* VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H */
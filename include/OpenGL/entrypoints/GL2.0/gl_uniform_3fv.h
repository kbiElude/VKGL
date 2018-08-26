/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3FV_H
#define VKGL_GL_UNIFORM_3FV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform3fv(GLint          location,
                                  GLsizei        count,
                                  const GLfloat* value);

void vkglUniform3fv_with_validation(VKGL::Context* in_context_ptr,
                                    const GLint&   in_location,
                                    const GLsizei& in_count,
                                    const GLfloat* in_value_ptr);

#endif /* VKGL_GL_UNIFORM_3FV_H */
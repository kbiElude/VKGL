/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_1IV_H
#define VKGL_GL_UNIFORM_1IV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform1iv(GLint        location,
                                  GLsizei      count,
                                  const GLint* value);

void vkglUniform1iv_with_validation(VKGL::Context* in_context_ptr,
                                    const GLint&   in_location,
                                    const GLsizei& in_count,
                                    const GLint*   in_value_ptr);

#endif /* VKGL_GL_UNIFORM_1IV_H */
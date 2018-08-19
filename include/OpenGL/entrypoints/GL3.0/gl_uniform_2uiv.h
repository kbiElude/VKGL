/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_2UIV_H
#define VKGL_GL_UNIFORM_2UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform2uiv(GLint         location,
                                          GLsizei       count,
                                          const GLuint* value);

void vkglUniform2uiv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLint&   in_location,
                                     const GLsizei& in_count,
                                     const GLuint*  in_value_ptr);

#endif /* VKGL_GL_UNIFORM_2UIV_H */
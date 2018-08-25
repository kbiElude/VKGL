/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3F_H
#define VKGL_GL_UNIFORM_3F_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform3f(GLint   location,
                                 GLfloat v0,
                                 GLfloat v1,
                                 GLfloat v2);

void vkglUniform3f_with_validation(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLfloat& in_v0,
                                   const GLfloat& in_v1,
                                   const GLfloat& in_v2);

#endif /* VKGL_GL_UNIFORM_3F_H */
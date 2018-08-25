/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_1I_H
#define VKGL_GL_UNIFORM_1I_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform1i(GLint location,
                                 GLint v0);

void vkglUniform1i_with_validation(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLint&   in_v0);

#endif /* VKGL_GL_UNIFORM_1I_H */
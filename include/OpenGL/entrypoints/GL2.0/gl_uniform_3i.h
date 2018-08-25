/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_3I_H
#define VKGL_GL_UNIFORM_3I_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform3i(GLint location,
                                 GLint v0,
                                 GLint v1,
                                 GLint v2);

void vkglUniform3i_with_validation(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLint&   in_v0,
                                   const GLint&   in_v1,
                                   const GLint&   in_v2);

#endif /* VKGL_GL_UNIFORM_3I_H */
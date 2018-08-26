/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_STENCIL_H
#define VKGL_GL_CLEAR_STENCIL_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglClearStencil(GLint s);

void vkglClearStencil_with_validation(VKGL::Context* in_context_ptr,
                                      const GLint&   in_s);

#endif /* VKGL_GL_CLEAR_STENCIL_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SCISSOR_H
#define VKGL_GL_SCISSOR_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglScissor(GLint   x,
                               GLint   y,
                               GLsizei width,
                               GLsizei height);

void vkglScissor_with_validation(VKGL::Context* in_context_ptr,
                                 const GLint&   in_x,
                                 const GLint&   in_y,
                                 const GLsizei& in_width,
                                 const GLsizei& in_height);

#endif /* VKGL_GL_SCISSOR_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_LINE_WIDTH_H
#define VKGL_GL_LINE_WIDTH_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglLineWidth(GLfloat width);

void vkglLineWidth_with_validation(VKGL::Context* in_context_ptr,
                                   const GLfloat& in_width);

#endif /* VKGL_GL_LINE_WIDTH_H */
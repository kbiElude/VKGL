/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_BUFFERS_H
#define VKGL_GL_DRAW_BUFFERS_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglDrawBuffers(GLsizei       n,
                                   const GLenum* bufs);

#endif /* VKGL_GL_DRAW_BUFFERS_H */
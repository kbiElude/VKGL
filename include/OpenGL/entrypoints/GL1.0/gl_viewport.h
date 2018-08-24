/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VIEWPORT_H
#define VKGL_GL_VIEWPORT_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglViewport(GLint   x,
                                GLint   y,
                                GLsizei width,
                                GLsizei height);

#endif /* VKGL_GL_VIEWPORT_H */
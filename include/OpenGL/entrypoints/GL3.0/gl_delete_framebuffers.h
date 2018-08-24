/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_FRAMEBUFFERS_H
#define VKGL_GL_DELETE_FRAMEBUFFERS_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglDeleteFramebuffers(GLsizei       n,
                                          const GLuint* framebuffers);

#endif /* VKGL_GL_DELETE_FRAMEBUFFERS_H */
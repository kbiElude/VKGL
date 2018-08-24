/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_RENDERBUFFERS_H
#define VKGL_GL_DELETE_RENDERBUFFERS_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglDeleteRenderbuffers(GLsizei       n,
                                           const GLuint* renderbuffers);

#endif /* VKGL_GL_DELETE_RENDERBUFFERS_H */
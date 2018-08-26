/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GEN_RENDERBUFFERS_H
#define VKGL_GL_GEN_RENDERBUFFERS_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGenRenderbuffers(GLsizei n,
                                        GLuint* renderbuffers);

void vkglGenRenderbuffers_with_validation(VKGL::Context* in_context_ptr,
                                          const GLsizei& in_n,
                                          GLuint*        out_renderbuffers_ptr);

#endif /* VKGL_GL_GEN_RENDERBUFFERS_H */
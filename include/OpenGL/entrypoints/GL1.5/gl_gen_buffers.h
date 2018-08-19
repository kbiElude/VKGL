/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GEN_BUFFERS_H
#define VKGL_GL_GEN_BUFFERS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGenBuffers(GLsizei n,
                                         GLuint* buffers);

void vkglGenBuffers_with_validation(VKGL::Context* in_context_ptr,
                                    const GLsizei& in_n,
                                    GLuint*        out_buffers_ptr);

#endif /* VKGL_GL_GEN_BUFFERS_H */
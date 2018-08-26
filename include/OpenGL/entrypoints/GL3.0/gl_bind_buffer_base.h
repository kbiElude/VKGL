/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_BUFFER_BASE_H
#define VKGL_GL_BIND_BUFFER_BASE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBindBufferBase(GLenum target,
                                      GLuint index,
                                      GLuint buffer);

void vkglBindBufferBase_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLuint&  in_index,
                                        const GLuint&  in_buffer);

#endif /* VKGL_GL_BIND_BUFFER_BASE_H */
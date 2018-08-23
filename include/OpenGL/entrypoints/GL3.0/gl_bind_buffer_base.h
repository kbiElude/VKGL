/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_BUFFER_BASE_H
#define VKGL_GL_BIND_BUFFER_BASE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglBindBufferBase(GLenum target,
                                               GLuint index,
                                               GLuint buffer);

#endif /* VKGL_GL_BIND_BUFFER_BASE_H */
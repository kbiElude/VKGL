/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_BUFFER_RANGE_H
#define VKGL_GL_BIND_BUFFER_RANGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBindBufferRange(GLenum     target,
                                              GLuint     index,
                                              GLuint     buffer,
                                              GLintptr   offset,
                                              GLsizeiptr size);

#endif /* VKGL_GL_BIND_BUFFER_RANGE_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BUFFER_SUB_DATA_H
#define VKGL_GL_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBufferSubData(GLenum      target,
                                     GLintptr    offset,
                                     GLsizeiptr  size,
                                     const void* data);

#endif /* VKGL_GL_BUFFER_SUB_DATA_H */
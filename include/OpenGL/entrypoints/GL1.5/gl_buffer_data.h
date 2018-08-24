/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BUFFER_DATA_H
#define VKGL_GL_BUFFER_DATA_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBufferData(GLenum      target,
                                  GLsizeiptr  size,
                                  const void* data,
                                  GLenum      usage);

#endif /* VKGL_GL_BUFFER_DATA_H */
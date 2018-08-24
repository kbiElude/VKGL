/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MAP_BUFFER_RANGE_H
#define VKGL_GL_MAP_BUFFER_RANGE_H

#include "OpenGL/types.h"

void *VKGL_APIENTRY vkglMapBufferRange(GLenum     target,
                                       GLintptr   offset,
                                       GLsizeiptr length,
                                       GLbitfield access);

#endif /* VKGL_GL_MAP_BUFFER_RANGE_H */
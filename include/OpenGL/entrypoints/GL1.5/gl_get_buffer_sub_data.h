/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BUFFER_SUB_DATA_H
#define VKGL_GL_GET_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetBufferSubData(GLenum     target,
                                               GLintptr   offset,
                                               GLsizeiptr size,
                                               void*      data);

#endif /* VKGL_GL_GET_BUFFER_SUB_DATA_H */
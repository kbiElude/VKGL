/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BUFFER_POINTERV_H
#define VKGL_GL_GET_BUFFER_POINTERV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetBufferPointerv(GLenum target,
                                         GLenum pname,
                                         void** params);

#endif /* VKGL_GL_GET_BUFFER_POINTERV_H */
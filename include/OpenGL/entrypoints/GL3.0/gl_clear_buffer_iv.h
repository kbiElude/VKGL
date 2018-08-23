/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_IV_H
#define VKGL_GL_CLEAR_BUFFER_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglClearBufferiv(GLenum       buffer,
                                              GLint        drawbuffer,
                                              const GLint* value);

#endif /* VKGL_GL_CLEAR_BUFFER_IV_H */
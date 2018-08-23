/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_UIV_H
#define VKGL_GL_CLEAR_BUFFER_UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglClearBufferuiv(GLenum        buffer,
                                               GLint         drawbuffer,
                                               const GLuint* value);

#endif /* VKGL_GL_CLEAR_BUFFER_UIV_H */
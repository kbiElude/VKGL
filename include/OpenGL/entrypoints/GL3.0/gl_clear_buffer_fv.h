/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_FV_H
#define VKGL_GL_CLEAR_BUFFER_FV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglClearBufferfv(GLenum         buffer,
                                              GLint          drawbuffer,
                                              const GLfloat* value);

#endif /* VKGL_GL_CLEAR_BUFFER_FV_H */
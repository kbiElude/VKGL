/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_BUFFER_H
#define VKGL_GL_TEX_BUFFER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglTexBuffer(GLenum target,
                                          GLenum internalformat,
                                          GLuint buffer);

#endif /* VKGL_GL_TEX_BUFFER_H */
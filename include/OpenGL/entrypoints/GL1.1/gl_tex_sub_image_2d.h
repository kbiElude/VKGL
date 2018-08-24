/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_SUB_IMAGE_2D_H
#define VKGL_GL_TEX_SUB_IMAGE_2D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexSubImage2D(GLenum      target,
                                     GLint       level,
                                     GLint       xoffset,
                                     GLint       yoffset,
                                     GLsizei     width,
                                     GLsizei     height,
                                     GLenum      format,
                                     GLenum      type,
                                     const void* pixels);

#endif /* VKGL_GL_TEX_SUB_IMAGE_2D_H */
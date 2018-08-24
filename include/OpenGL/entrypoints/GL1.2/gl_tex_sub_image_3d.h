/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_SUB_IMAGE_3D_H
#define VKGL_GL_TEX_SUB_IMAGE_3D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexSubImage3D(GLenum      target,
                                     GLint       level,
                                     GLint       xoffset,
                                     GLint       yoffset,
                                     GLint       zoffset,
                                     GLsizei     width,
                                     GLsizei     height,
                                     GLsizei     depth,
                                     GLenum      format,
                                     GLenum      type,
                                     const void* pixels);

#endif /* VKGL_GL_TEX_SUB_IMAGE_3D_H */
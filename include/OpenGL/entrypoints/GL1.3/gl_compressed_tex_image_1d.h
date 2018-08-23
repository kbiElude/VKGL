/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H
#define VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglCompressedTexImage1D(GLenum      target,
                                                     GLint       level,
                                                     GLenum      internalformat,
                                                     GLsizei     width,
                                                     GLint       border,
                                                     GLsizei     imageSize,
                                                     const void* data);

#endif /* VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H */
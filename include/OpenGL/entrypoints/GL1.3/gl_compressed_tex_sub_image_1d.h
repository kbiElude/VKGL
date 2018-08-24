/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCompressedTexSubImage1D(GLenum      target,
                                               GLint       level,
                                               GLint       xoffset,
                                               GLsizei     width,
                                               GLenum      format,
                                               GLsizei     imageSize,
                                               const void* data);

#endif /* VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H */
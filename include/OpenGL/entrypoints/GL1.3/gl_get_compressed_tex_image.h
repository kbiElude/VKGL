/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_COMPRESSED_TEX_IMAGE_H
#define VKGL_GL_GET_COMPRESSED_TEX_IMAGE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetCompressedTexImage(GLenum target,
                                             GLint  level,
                                             void*  img);

#endif /* VKGL_GL_GET_COMPRESSED_TEX_IMAGE_H */
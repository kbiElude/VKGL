/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_IMAGE_3D_H
#define VKGL_GL_TEX_IMAGE_3D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexImage3D(GLenum      target,
                                  GLint       level,
                                  GLint       internalformat,
                                  GLsizei     width,
                                  GLsizei     height,
                                  GLsizei     depth,
                                  GLint       border,
                                  GLenum      format,
                                  GLenum      type,
                                  const void* pixels);

#endif /* VKGL_GL_TEX_IMAGE_3D_H */
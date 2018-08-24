/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_TEX_IMAGE_1D_H
#define VKGL_GL_COPY_TEX_IMAGE_1D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCopyTexImage1D(GLenum  target,
                                      GLint   level,
                                      GLenum  internalformat,
                                      GLint   x,
                                      GLint   y,
                                      GLsizei width,
                                      GLint   border);

#endif /* VKGL_GL_COPY_TEX_IMAGE_1D_H */
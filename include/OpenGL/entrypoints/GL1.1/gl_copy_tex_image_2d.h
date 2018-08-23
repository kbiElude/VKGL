/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_TEX_IMAGE_2D_H
#define VKGL_GL_COPY_TEX_IMAGE_2D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglCopyTexImage2D(GLenum  target,
                                               GLint   level,
                                               GLenum  internalformat,
                                               GLint   x,
                                               GLint   y,
                                               GLsizei width,
                                               GLsizei height,
                                               GLint   border);

#endif /* VKGL_GL_COPY_TEX_IMAGE_2D_H */
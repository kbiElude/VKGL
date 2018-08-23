/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglCopyTexSubImage1D(GLenum  target,
                                                  GLint   level,
                                                  GLint   xoffset,
                                                  GLint   x,
                                                  GLint   y,
                                                  GLsizei width);

#endif /* VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H */
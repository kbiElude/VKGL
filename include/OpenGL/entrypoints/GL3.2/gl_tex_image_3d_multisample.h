/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_IMAGE_3D_MULTISAMPLE_H
#define VKGL_GL_TEX_IMAGE_3D_MULTISAMPLE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexImage3DMultisample(GLenum    target,
                                             GLsizei   samples,
                                             GLenum    internalformat,
                                             GLsizei   width,
                                             GLsizei   height,
                                             GLsizei   depth,
                                             GLboolean fixedsamplelocations);

#endif /* VKGL_GL_TEX_IMAGE_3D_MULTISAMPLE_H */
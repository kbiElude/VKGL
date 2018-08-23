/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_IMAGE_H
#define VKGL_GL_GET_TEX_IMAGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetTexImage(GLenum target,
                                            GLint  level,
                                            GLenum format,
                                            GLenum type,
                                            void*  pixels);

#endif /* VKGL_GL_GET_TEX_IMAGE_H */
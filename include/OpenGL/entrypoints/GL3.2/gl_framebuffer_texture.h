/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglFramebufferTexture(GLenum target,
                                                   GLenum attachment,
                                                   GLuint texture,
                                                   GLint  level);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_H */
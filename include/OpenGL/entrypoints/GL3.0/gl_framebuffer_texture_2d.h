/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_2D_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_2D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTexture2D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint  level);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_2D_H */
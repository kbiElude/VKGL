/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BLIT_FRAMEBUFFER_H
#define VKGL_GL_BLIT_FRAMEBUFFER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBlitFramebuffer(GLint      srcX0,
                                              GLint      srcY0,
                                              GLint      srcX1,
                                              GLint      srcY1,
                                              GLint      dstX0,
                                              GLint      dstY0,
                                              GLint      dstX1,
                                              GLint      dstY1,
                                              GLbitfield mask,
                                              GLenum     filter);

#endif /* VKGL_GL_BLIT_FRAMEBUFFER_H */
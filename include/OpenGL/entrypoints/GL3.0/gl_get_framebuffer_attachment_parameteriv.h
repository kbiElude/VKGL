/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H
#define VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetFramebufferAttachmentParameteriv(GLenum target,
                                                           GLenum attachment,
                                                           GLenum pname,
                                                           GLint* params);

#endif /* VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H */
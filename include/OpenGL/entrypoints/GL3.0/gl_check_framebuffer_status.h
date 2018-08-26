/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CHECK_FRAMEBUFFER_STATUS_H
#define VKGL_GL_CHECK_FRAMEBUFFER_STATUS_H

#include "OpenGL/types.h"

GLenum VKGL_APIENTRY vkglCheckFramebufferStatus(GLenum target);

GLenum vkglCheckFramebufferStatus_with_validation(VKGL::Context* in_context_ptr,
                                                  const GLenum&  in_target);

#endif /* VKGL_GL_CHECK_FRAMEBUFFER_STATUS_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_FRAMEBUFFER_H
#define VKGL_GL_IS_FRAMEBUFFER_H

#include "OpenGL/types.h"

VKGL_API GLboolean VKGL_APIENTRY glIsFramebuffer(GLuint framebuffer);

bool vkglIsFramebuffer_with_validation(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_framebuffer);

#endif /* VKGL_GL_IS_FRAMEBUFFER_H */
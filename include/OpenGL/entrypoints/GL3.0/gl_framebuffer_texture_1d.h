/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_1D_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTexture1D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint  level);

void vkglFramebufferTexture1D_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_target,
                                              const GLenum&  in_attachment,
                                              const GLenum&  in_textarget,
                                              const GLuint&  in_texture,
                                              const GLint&   in_level);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_1D_H */
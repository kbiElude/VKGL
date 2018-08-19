/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_3D_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTexture3D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint  level,
                                                   GLint  zoffset);

void vkglFramebufferTexture3D_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_target,
                                              const GLenum&  in_attachment,
                                              const GLenum&  in_textarget,
                                              const GLuint&  in_texture,
                                              const GLint&   in_level,
                                              const GLint&   in_zoffset);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_3D_H */
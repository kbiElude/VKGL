/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglFramebufferTexture(GLenum target,
                                              GLenum attachment,
                                              GLuint texture,
                                              GLint  level);

    void vkglFramebufferTexture_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLenum&    in_attachment,
                                                const GLuint&    in_texture,
                                                const GLint&     in_level);
}

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_H */
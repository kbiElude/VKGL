/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_RENDERBUFFER_H
#define VKGL_GL_FRAMEBUFFER_RENDERBUFFER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglFramebufferRenderbuffer(GLenum target,
                                                   GLenum attachment,
                                                   GLenum renderbuffertarget,
                                                   GLuint renderbuffer);

    void vkglFramebufferRenderbuffer_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_target,
                                                     const GLenum&    in_attachment,
                                                     const GLenum&    in_renderbuffertarget,
                                                     const GLuint&    in_renderbuffer);
}

#endif /* VKGL_GL_FRAMEBUFFER_RENDERBUFFER_H */
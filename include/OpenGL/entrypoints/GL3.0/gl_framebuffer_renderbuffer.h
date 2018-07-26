#ifndef VKGL_GL_FRAMEBUFFER_RENDERBUFFER_H
#define VKGL_GL_FRAMEBUFFER_RENDERBUFFER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferRenderbuffer(GLenum target,
                                                      GLenum attachment,
                                                      GLenum renderbuffertarget,
                                                      GLuint renderbuffer);

#endif /* VKGL_GL_FRAMEBUFFER_RENDERBUFFER_H */
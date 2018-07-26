#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTexture(GLenum target,
                                                 GLenum attachment,
                                                 GLuint texture,
                                                 GLint  level);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_H */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_1D_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTexture1D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint  level);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_1D_H */
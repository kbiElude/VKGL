#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_3D_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTexture3D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint  level,
                                                   GLint  zoffset);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_3D_H */
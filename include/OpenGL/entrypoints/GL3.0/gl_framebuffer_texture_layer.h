#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_LAYER_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_LAYER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFramebufferTextureLayer(GLenum target,
                                                      GLenum attachment,
                                                      GLuint texture,
                                                      GLint  level,
                                                      GLint  layer);

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_LAYER_H */
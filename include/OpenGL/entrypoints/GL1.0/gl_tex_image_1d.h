#ifndef VKGL_GL_TEX_IMAGE_1D_H
#define VKGL_GL_TEX_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexImage1D(GLenum      target,
                                         GLint       level,
                                         GLint       internalformat,
                                         GLsizei     width,
                                         GLint       border,
                                         GLenum      format,
                                         GLenum      type,
                                         const void* pixels);

#endif /* VKGL_GL_TEX_IMAGE_1D_H */
#ifndef VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H
#define VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCompressedTexImage1D(GLenum      target,
                                                   GLint       level,
                                                   GLenum      internalformat,
                                                   GLsizei     width,
                                                   GLint       border,
                                                   GLsizei     imageSize,
                                                   const void* data);

#endif /* VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H */
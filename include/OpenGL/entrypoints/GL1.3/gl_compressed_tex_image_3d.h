#ifndef VKGL_GL_COMPRESSED_TEX_IMAGE_3D_H
#define VKGL_GL_COMPRESSED_TEX_IMAGE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCompressedTexImage3D(GLenum      target,
                                                   GLint       level,
                                                   GLenum      internalformat,
                                                   GLsizei     width,
                                                   GLsizei     height,
                                                   GLsizei     depth,
                                                   GLint       border,
                                                   GLsizei     imageSize,
                                                   const void* data);

#endif /* VKGL_GL_COMPRESSED_TEX_IMAGE_3D_H */
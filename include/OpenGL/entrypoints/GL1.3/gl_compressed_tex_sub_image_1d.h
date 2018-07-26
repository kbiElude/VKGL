#ifndef VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCompressedTexSubImage1D(GLenum      target,
                                                      GLint       level,
                                                      GLint       xoffset,
                                                      GLsizei     width,
                                                      GLenum      format,
                                                      GLsizei     imageSize,
                                                      const void* data);

#endif /* VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H */
#ifndef VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_3D_H
#define VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCompressedTexSubImage3D(GLenum      target,
                                                      GLint       level,
                                                      GLint       xoffset,
                                                      GLint       yoffset,
                                                      GLint       zoffset,
                                                      GLsizei     width,
                                                      GLsizei     height,
                                                      GLsizei     depth,
                                                      GLenum      format,
                                                      GLsizei     imageSize,
                                                      const void* data);

#endif /* VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_3D_H */
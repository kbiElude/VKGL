#ifndef VKGL_GL_TEX_SUB_IMAGE_3D_H
#define VKGL_GL_TEX_SUB_IMAGE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexSubImage3D(GLenum      target,
                                            GLint       level,
                                            GLint       xoffset,
                                            GLint       yoffset,
                                            GLint       zoffset,
                                            GLsizei     width,
                                            GLsizei     height,
                                            GLsizei     depth,
                                            GLenum      format,
                                            GLenum      type,
                                            const void* pixels);

#endif /* VKGL_GL_TEX_SUB_IMAGE_3D_H */
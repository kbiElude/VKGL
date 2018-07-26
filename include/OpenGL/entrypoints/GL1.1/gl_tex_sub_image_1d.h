#ifndef VKGL_GL_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexSubImage1D(GLenum      target,
                                            GLint       level,
                                            GLint       xoffset,
                                            GLsizei     width,
                                            GLenum      format,
                                            GLenum      type,
                                            const void* pixels);

#endif /* VKGL_GL_TEX_SUB_IMAGE_1D_H */
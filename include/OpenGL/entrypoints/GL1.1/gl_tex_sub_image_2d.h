#ifndef VKGL_GL_TEX_SUB_IMAGE_2D_H
#define VKGL_GL_TEX_SUB_IMAGE_2D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexSubImage2D(GLenum      target,
                                            GLint       level,
                                            GLint       xoffset,
                                            GLint       yoffset,
                                            GLsizei     width,
                                            GLsizei     height,
                                            GLenum      format,
                                            GLenum      type,
                                            const void* pixels);

#endif /* VKGL_GL_TEX_SUB_IMAGE_2D_H */
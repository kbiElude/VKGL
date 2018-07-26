#ifndef VKGL_GL_COPY_TEX_IMAGE_2D_H
#define VKGL_GL_COPY_TEX_IMAGE_2D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCopyTexImage2D(GLenum  target,
                                             GLint   level,
                                             GLenum  internalformat,
                                             GLint   x,
                                             GLint   y,
                                             GLsizei width,
                                             GLsizei height,
                                             GLint   border);

#endif /* VKGL_GL_COPY_TEX_IMAGE_2D_H */
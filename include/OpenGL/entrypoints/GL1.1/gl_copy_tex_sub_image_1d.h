#ifndef VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCopyTexSubImage1D(GLenum  target,
                                                GLint   level,
                                                GLint   xoffset,
                                                GLint   x,
                                                GLint   y,
                                                GLsizei width);

#endif /* VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H */
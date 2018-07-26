#ifndef VKGL_GL_COPY_TEX_SUB_IMAGE_3D_H
#define VKGL_GL_COPY_TEX_SUB_IMAGE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCopyTexSubImage3D(GLenum  target,
                                                GLint   level,
                                                GLint   xoffset,
                                                GLint   yoffset,
                                                GLint   zoffset,
                                                GLint   x,
                                                GLint   y,
                                                GLsizei width,
                                                GLsizei height);

#endif /* VKGL_GL_COPY_TEX_SUB_IMAGE_3D_H */
#ifndef VKGL_GL_GET_COMPRESSED_TEX_IMAGE_H
#define VKGL_GL_GET_COMPRESSED_TEX_IMAGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetCompressedTexImage(GLenum target,
                                                    GLint  level,
                                                    void*  img);

#endif /* VKGL_GL_GET_COMPRESSED_TEX_IMAGE_H */
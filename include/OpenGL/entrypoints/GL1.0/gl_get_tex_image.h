#ifndef VKGL_GL_GET_TEX_IMAGE_H
#define VKGL_GL_GET_TEX_IMAGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexImage(GLenum target,
                                          GLint  level,
                                          GLenum format,
                                          GLenum type,
                                          void*  pixels);

#endif /* VKGL_GL_GET_TEX_IMAGE_H */
#ifndef VKGL_GL_RENDERBUFFER_STORAGE_H
#define VKGL_GL_RENDERBUFFER_STORAGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glRenderbufferStorage(GLenum  target,
                                                  GLenum  internalformat,
                                                  GLsizei width,
                                                  GLsizei height);

#endif /* VKGL_GL_RENDERBUFFER_STORAGE_H */
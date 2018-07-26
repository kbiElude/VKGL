#ifndef VKGL_GL_RENDERBUFFER_STORAGE_MULTISAMPLE_H
#define VKGL_GL_RENDERBUFFER_STORAGE_MULTISAMPLE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glRenderbufferStorageMultisample(GLenum  target,
                                                             GLsizei samples,
                                                             GLenum  internalformat,
                                                             GLsizei width,
                                                             GLsizei height);

#endif /* VKGL_GL_RENDERBUFFER_STORAGE_MULTISAMPLE_H */
#ifndef VKGL_GL_TEX_BUFFER_H
#define VKGL_GL_TEX_BUFFER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexBuffer(GLenum target,
                                        GLenum internalformat,
                                        GLuint buffer);

#endif /* VKGL_GL_TEX_BUFFER_H */
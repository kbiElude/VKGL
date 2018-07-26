#ifndef VKGL_GL_BIND_BUFFER_BASE_H
#define VKGL_GL_BIND_BUFFER_BASE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBindBufferBase(GLenum target,
                                             GLuint index,
                                             GLuint buffer);

#endif /* VKGL_GL_BIND_BUFFER_BASE_H */
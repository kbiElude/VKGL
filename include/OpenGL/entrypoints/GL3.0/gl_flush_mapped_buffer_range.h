#ifndef VKGL_GL_FLUSH_MAPPED_BUFFER_RANGE_H
#define VKGL_GL_FLUSH_MAPPED_BUFFER_RANGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFlushMappedBufferRange(GLenum     target,
                                                     GLintptr   offset,
                                                     GLsizeiptr length);

#endif /* VKGL_GL_FLUSH_MAPPED_BUFFER_RANGE_H */
#ifndef VKGL_GL_COPY_BUFFER_SUB_DATA_H
#define VKGL_GL_COPY_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCopyBufferSubData(GLenum     readTarget,
                                                GLenum     writeTarget,
                                                GLintptr   readOffset,
                                                GLintptr   writeOffset,
                                                GLsizeiptr size);

#endif /* VKGL_GL_COPY_BUFFER_SUB_DATA_H */
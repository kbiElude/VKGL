#ifndef VKGL_GL_BUFFER_SUB_DATA_H
#define VKGL_GL_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBufferSubData(GLenum      target,
                                            GLintptr    offset,
                                            GLsizeiptr  size,
                                            const void* data);

#endif /* VKGL_GL_BUFFER_SUB_DATA_H */
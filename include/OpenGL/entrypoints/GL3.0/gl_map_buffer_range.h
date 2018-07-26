#ifndef VKGL_GL_MAP_BUFFER_RANGE_H
#define VKGL_GL_MAP_BUFFER_RANGE_H

#include "OpenGL/types.h"

VKGL_API void *APIENTRY glMapBufferRange(GLenum     target,
                                         GLintptr   offset,
                                         GLsizeiptr length,
                                         GLbitfield access);

#endif /* VKGL_GL_MAP_BUFFER_RANGE_H */
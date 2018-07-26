#ifndef VKGL_GL_BUFFER_DATA_H
#define VKGL_GL_BUFFER_DATA_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBufferData(GLenum      target,
                                         GLsizeiptr  size,
                                         const void* data,
                                         GLenum      usage);

#endif /* VKGL_GL_BUFFER_DATA_H */
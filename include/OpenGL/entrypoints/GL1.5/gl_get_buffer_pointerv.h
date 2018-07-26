#ifndef VKGL_GL_GET_BUFFER_POINTERV_H
#define VKGL_GL_GET_BUFFER_POINTERV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetBufferPointerv(GLenum target,
                                                GLenum pname,
                                                void** params);

#endif /* VKGL_GL_GET_BUFFER_POINTERV_H */
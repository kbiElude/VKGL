#ifndef VKGL_GL_GET_BUFFER_PARAMETERI64V_H
#define VKGL_GL_GET_BUFFER_PARAMETERI64V_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetBufferParameteri64v(GLenum   target,
                                                     GLenum   pname,
                                                     GLint64* params);

#endif /* VKGL_GL_GET_BUFFER_PARAMETERI64V_H */
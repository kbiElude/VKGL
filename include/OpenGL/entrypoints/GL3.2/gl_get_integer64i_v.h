#ifndef VKGL_GL_GET_INTEGER64I_V_H
#define VKGL_GL_GET_INTEGER64I_V_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetInteger64i_v(GLenum   target,
                                              GLuint   index,
                                              GLint64* data);

#endif /* VKGL_GL_GET_INTEGER64I_V_H */
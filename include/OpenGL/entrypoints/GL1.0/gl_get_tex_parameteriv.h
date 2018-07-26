#ifndef VKGL_GL_GET_TEX_PARAMETER_IV_H
#define VKGL_GL_GET_TEX_PARAMETER_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexParameteriv(GLenum target,
                                                GLenum pname,
                                                GLint* params);

#endif /* VKGL_GL_GET_TEX_PARAMETER_IV_H */
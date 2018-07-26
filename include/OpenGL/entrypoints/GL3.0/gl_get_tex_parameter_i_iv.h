#ifndef VKGL_GL_GET_TEX_PARAMETER_I_IV_H
#define VKGL_GL_GET_TEX_PARAMETER_I_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexParameterIiv(GLenum target,
                                                 GLenum pname,
                                                 GLint* params);

#endif /* VKGL_GL_GET_TEX_PARAMETER_I_IV_H */
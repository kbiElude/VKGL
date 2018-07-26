#ifndef VKGL_GL_TEX_PARAMETER_I_IV_H
#define VKGL_GL_TEX_PARAMETER_I_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameterIiv(GLenum       target,
                                              GLenum       pname,
                                              const GLint* params);

#endif /* VKGL_GL_TEX_PARAMETER_I_IV_H */
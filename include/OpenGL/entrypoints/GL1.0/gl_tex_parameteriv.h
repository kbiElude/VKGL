#ifndef VKGL_GL_TEX_PARAMETERIV_H
#define VKGL_GL_TEX_PARAMETERIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameteriv(GLenum       target,
                                             GLenum       pname,
                                             const GLint* params);

#endif /* VKGL_GL_TEX_PARAMETERIV_H */
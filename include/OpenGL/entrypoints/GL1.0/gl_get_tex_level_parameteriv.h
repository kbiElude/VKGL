#ifndef VKGL_GL_GET_TEX_LEVEL_PARAMETERIV_H
#define VKGL_GL_GET_TEX_LEVEL_PARAMETERIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexLevelParameteriv(GLenum target,
                                                     GLint  level,
                                                     GLenum pname,
                                                     GLint* params);

#endif /* VKGL_GL_GET_TEX_LEVEL_PARAMETERIV_H */
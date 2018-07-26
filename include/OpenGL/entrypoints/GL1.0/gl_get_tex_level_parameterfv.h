#ifndef VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H
#define VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexLevelParameterfv(GLenum   target,
                                                     GLint    level,
                                                     GLenum   pname,
                                                     GLfloat* params);

#endif /* VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H */
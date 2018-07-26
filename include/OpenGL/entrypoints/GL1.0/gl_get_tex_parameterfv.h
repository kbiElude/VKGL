#ifndef VKGL_GL_GET_TEX_PARAMETER_FV_H
#define VKGL_GL_GET_TEX_PARAMETER_FV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexParameterfv(GLenum   target,
                                                GLenum   pname,
                                                GLfloat* params);

#endif /* VKGL_GL_GET_TEX_PARAMETER_FV_H */
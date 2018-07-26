#ifndef VKGL_GL_TEX_PARAMETERFV_H
#define VKGL_GL_TEX_PARAMETERFV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameterfv(GLenum         target,
                                             GLenum         pname,
                                             const GLfloat* params);

#endif /* VKGL_GL_TEX_PARAMETERFV_H */
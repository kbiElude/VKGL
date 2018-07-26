#ifndef VKGL_GL_GET_UNIFORMFV_H
#define VKGL_GL_GET_UNIFORMFV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetUniformfv(GLuint   program,
                                           GLint    location,
                                           GLfloat* params);

#endif /* VKGL_GL_GET_UNIFORMFV_H */
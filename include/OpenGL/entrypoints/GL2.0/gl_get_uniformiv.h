#ifndef VKGL_GL_GET_UNIFORMIV_H
#define VKGL_GL_GET_UNIFORMIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetUniformiv(GLuint program,
                                           GLint  location,
                                           GLint* params);

#endif /* VKGL_GL_GET_UNIFORMIV_H */
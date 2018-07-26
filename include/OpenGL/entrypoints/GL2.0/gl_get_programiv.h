#ifndef VKGL_GL_GET_PROGRAMIV_H
#define VKGL_GL_GET_PROGRAMIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetProgramiv(GLuint program,
                                           GLenum pname,
                                           GLint* params);

#endif /* VKGL_GL_GET_PROGRAMIV_H */
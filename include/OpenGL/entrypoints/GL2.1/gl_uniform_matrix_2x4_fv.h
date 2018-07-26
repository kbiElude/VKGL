#ifndef VKGL_GL_UNIFORM_MATRIX_2X4_FV_H
#define VKGL_GL_UNIFORM_MATRIX_2X4_FV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniformMatrix2x4fv(GLint          location,
                                                 GLsizei        count,
                                                 GLboolean      transpose,
                                                 const GLfloat* value);

#endif /* VKGL_GL_UNIFORM_MATRIX_2X4_FV_H */
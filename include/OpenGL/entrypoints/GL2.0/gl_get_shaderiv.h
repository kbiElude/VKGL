#ifndef VKGL_GL_GET_SHADERIV_H
#define VKGL_GL_GET_SHADERIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetShaderiv(GLuint shader,
                                          GLenum pname,
                                          GLint* params);

#endif /* VKGL_GL_GET_SHADERIV_H */
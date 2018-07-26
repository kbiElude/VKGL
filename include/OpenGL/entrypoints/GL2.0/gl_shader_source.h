#ifndef VKGL_GL_SHADER_SOURCE_H
#define VKGL_GL_SHADER_SOURCE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glShaderSource(GLuint               shader,
                                           GLsizei              count,
                                           const GLchar* const* string,
                                           const GLint*         length);

#endif /* VKGL_GL_SHADER_SOURCE_H */
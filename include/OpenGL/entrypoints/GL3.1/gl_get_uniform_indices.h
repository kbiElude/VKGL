#ifndef VKGL_GL_GET_UNIFORM_INDICES_H
#define VKGL_GL_GET_UNIFORM_INDICES_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetUniformIndices(GLuint               program,
                                                GLsizei              uniformCount,
                                                const GLchar* const* uniformNames,
                                                GLuint*              uniformIndices);

#endif /* VKGL_GL_GET_UNIFORM_INDICES_H */
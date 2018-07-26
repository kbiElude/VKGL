#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_BLOCKIV_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_BLOCKIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveUniformBlockiv(GLuint program,
                                                      GLuint uniformBlockIndex,
                                                      GLenum pname,
                                                      GLint* params);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_BLOCKIV_H */
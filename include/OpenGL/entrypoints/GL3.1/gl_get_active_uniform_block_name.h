#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveUniformBlockName(GLuint   program,
                                                        GLuint   uniformBlockIndex,
                                                        GLsizei  bufSize,
                                                        GLsizei* length,
                                                        GLchar*  uniformBlockName);

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H */
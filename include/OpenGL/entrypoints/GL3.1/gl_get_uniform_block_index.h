#ifndef VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H
#define VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H

#include "OpenGL/types.h"

VKGL_API GLuint VKGL_APIENTRY glGetUniformBlockIndex(GLuint        program,
                                                     const GLchar* uniformBlockName);

#endif /* VKGL_GL_GET_UNIFORM_BLOCK_INDEX_H */
#ifndef VKGL_GL_GET_SYNCIV_H
#define VKGL_GL_GET_SYNCIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetSynciv(GLsync   sync,
                                        GLenum   pname,
                                        GLsizei  bufSize,
                                        GLsizei* length,
                                        GLint*   values);

#endif /* VKGL_GL_GET_SYNCIV_H */
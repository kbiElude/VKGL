#ifndef VKGL_GL_GET_QUERY_OBJECTUIV_H
#define VKGL_GL_GET_QUERY_OBJECTUIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetQueryObjectuiv(GLuint  id,
                                                GLenum  pname,
                                                GLuint* params);

#endif /* VKGL_GL_GET_QUERY_OBJECTUIV_H */
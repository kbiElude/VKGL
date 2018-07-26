#ifndef VKGL_GL_GET_VERTEX_ATTRIBFV_H
#define VKGL_GL_GET_VERTEX_ATTRIBFV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetVertexAttribfv(GLuint   index,
                                                GLenum   pname,
                                                GLfloat* params);

#endif /* VKGL_GL_GET_VERTEX_ATTRIBFV_H */
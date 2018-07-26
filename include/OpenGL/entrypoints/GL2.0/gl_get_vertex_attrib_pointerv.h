#ifndef VKGL_GL_GET_VERTEX_ATTRIB_POINTERV_H
#define VKGL_GL_GET_VERTEX_ATTRIB_POINTERV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetVertexAttribPointerv(GLuint index,
                                                      GLenum pname,
                                                      void** pointer);

#endif /* VKGL_GL_GET_VERTEX_ATTRIB_POINTERV_H */
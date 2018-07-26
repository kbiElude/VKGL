#ifndef VKGL_GL_VERTEX_ATTRIB_I_POINTER_H
#define VKGL_GL_VERTEX_ATTRIB_I_POINTER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttribIPointer(GLuint      index,
                                                   GLint       size,
                                                   GLenum      type,
                                                   GLsizei     stride,
                                                   const void* pointer);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_POINTER_H */
#ifndef VKGL_GL_BIND_VERTEX_ARRAY_H
#define VKGL_GL_BIND_VERTEX_ARRAY_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBindVertexArray(GLuint array);

void vkglBindVertexArray_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_array);

#endif /* VKGL_GL_BIND_VERTEX_ARRAY_H */
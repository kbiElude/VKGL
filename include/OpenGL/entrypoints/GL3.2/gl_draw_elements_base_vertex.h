#ifndef VKGL_GL_DRAW_ELEMENTS_BASE_VERTEX_H
#define VKGL_GL_DRAW_ELEMENTS_BASE_VERTEX_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDrawElementsBaseVertex(GLenum      mode,
                                                     GLsizei     count,
                                                     GLenum      type,
                                                     const void* indices,
                                                     GLint       basevertex);

#endif /* VKGL_GL_DRAW_ELEMENTS_BASE_VERTEX_H */
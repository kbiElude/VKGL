#ifndef VKGL_GL_DRAW_RANGE_ELEMENTS_H
#define VKGL_GL_DRAW_RANGE_ELEMENTS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDrawRangeElements(GLenum      mode,
                                                GLuint      start,
                                                GLuint      end,
                                                GLsizei     count,
                                                GLenum      type,
                                                const void* indices);

#endif /* VKGL_GL_DRAW_RANGE_ELEMENTS_H */
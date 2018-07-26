#ifndef VKGL_GL_SCISSOR_H
#define VKGL_GL_SCISSOR_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glScissor(GLint   x,
                                      GLint   y,
                                      GLsizei width,
                                      GLsizei height);

#endif /* VKGL_GL_SCISSOR_H */
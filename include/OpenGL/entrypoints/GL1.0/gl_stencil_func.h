#ifndef VKGL_GL_STENCIL_FUNC_H
#define VKGL_GL_STENCIL_FUNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilFunc(GLenum func,
                                          GLint  ref,
                                          GLuint mask);

#endif /* VKGL_GL_STENCIL_FUNC_H */
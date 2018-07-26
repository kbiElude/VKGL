#ifndef VKGL_GL_STENCIL_FUNC_SEPARATE_H
#define VKGL_GL_STENCIL_FUNC_SEPARATE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilFuncSeparate(GLenum face,
                                                  GLenum func,
                                                  GLint  ref,
                                                  GLuint mask);

#endif /* VKGL_GL_STENCIL_FUNC_SEPARATE_H */
#ifndef VKGL_GL_STENCIL_OP_H
#define VKGL_GL_STENCIL_OP_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilOp(GLenum fail,
                                        GLenum zfail,
                                        GLenum zpass);

#endif /* VKGL_GL_STENCIL_OP_H */
#ifndef VKGL_GL_STENCIL_OP_SEPARATE_H
#define VKGL_GL_STENCIL_OP_SEPARATE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilOpSeparate(GLenum face,
                                                GLenum sfail,
                                                GLenum dpfail,
                                                GLenum dppass);

#endif /* VKGL_GL_STENCIL_OP_SEPARATE_H */
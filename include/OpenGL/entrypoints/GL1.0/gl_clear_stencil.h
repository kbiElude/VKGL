#ifndef VKGL_GL_CLEAR_STENCIL_H
#define VKGL_GL_CLEAR_STENCIL_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glClearStencil(GLint s);

void vkglClearStencil_with_validation(VKGL::Context* in_context_ptr,
                                      const GLint&   in_s);

#endif /* VKGL_GL_CLEAR_STENCIL_H */
#ifndef VKGL_GL_ENABLE_H
#define VKGL_GL_ENABLE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glEnable(GLenum cap);

void vkglEnable_with_validation(VKGL::Context* in_context_ptr,
                                const GLenum&  in_cap);

#endif /* VKGL_GL_ENABLE_H */
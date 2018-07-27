#ifndef VKGL_GL_DEPTH_FUNC_H
#define VKGL_GL_DEPTH_FUNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDepthFunc(GLenum func);

void vkglDepthFunc_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_func);

#endif /* VKGL_GL_DEPTH_FUNC_H */
#ifndef VKGL_GL_BLEND_FUNC_H
#define VKGL_GL_BLEND_FUNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBlendFunc(GLenum sfactor,
                                        GLenum dfactor);

void vkglBlendFunc_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_sfactor,
                                   const GLenum&  in_dfactor);

#endif /* VKGL_GL_BLEND_FUNC_H */
#ifndef VKGL_GL_DISABLE_H
#define VKGL_GL_DISABLE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDisable(GLenum cap);

void vkglDisable_with_validation(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_cap);

#endif /* VKGL_GL_DISABLE_H */
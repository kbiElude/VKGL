#ifndef VKGL_GL_FINISH_H
#define VKGL_GL_FINISH_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFinish(void);

void vkglFinish_with_validation(VKGL::Context* in_context_ptr);

#endif /* VKGL_GL_FINISH_H */
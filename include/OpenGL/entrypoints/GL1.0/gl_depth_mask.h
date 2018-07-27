#ifndef VKGL_GL_DEPTH_MASK_H
#define VKGL_GL_DEPTH_MASK_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDepthMask(GLboolean flag);

void vkglDepthMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_flag);

#endif /* VKGL_GL_DEPTH_MASK_H */
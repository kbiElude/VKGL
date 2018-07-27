#ifndef VKGL_GL_CLEAR_DEPTH_H
#define VKGL_GL_CLEAR_DEPTH_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glClearDepth(GLdouble depth);

void vkglClearDepth_with_validation(VKGL::Context*  in_context_ptr,
                                    const GLdouble& in_depth);

#endif /* VKGL_GL_CLEAR_DEPTH_H */
#ifndef VKGL_GL_CULL_FACE_H
#define VKGL_GL_CULL_FACE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCullFace(GLenum mode);

void vkglCullFace_with_validation(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_mode);

#endif /* VKGL_GL_CULL_FACE_H */
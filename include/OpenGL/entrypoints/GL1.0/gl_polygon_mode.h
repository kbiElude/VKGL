#ifndef VKGL_GL_POLYGON_MODE_H
#define VKGL_GL_POLYGON_MODE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glPolygonMode(GLenum face,
                                          GLenum mode);

void vkglPolygonMode_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_face,
                                     const GLenum&  in_mode);

#endif /* VKGL_GL_POLYGON_MODE_H */
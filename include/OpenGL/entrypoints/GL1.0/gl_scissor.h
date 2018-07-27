#ifndef VKGL_GL_SCISSOR_H
#define VKGL_GL_SCISSOR_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glScissor(GLint   x,
                                      GLint   y,
                                      GLsizei width,
                                      GLsizei height);

void vkglScissor_with_validation(VKGL::Context* in_context_ptr,
                                 const GLint&   x,
                                 const GLint&   in_y,
                                 const GLsizei& in_width,
                                 const GLsizei& in_height);

#endif /* VKGL_GL_SCISSOR_H */
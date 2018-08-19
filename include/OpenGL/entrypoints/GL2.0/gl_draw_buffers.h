#ifndef VKGL_GL_DRAW_BUFFERS_H
#define VKGL_GL_DRAW_BUFFERS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDrawBuffers(GLsizei       n,
                                          const GLenum* bufs);

void vkglDrawBuffers_with_validation(VKGL::Context* in_context_ptr,
                                     const GLsizei& in_n,
                                     const GLenum*  in_bufs);

#endif /* VKGL_GL_DRAW_BUFFERS_H */
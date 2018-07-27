#ifndef VKGL_GL_READ_BUFFER_H
#define VKGL_GL_READ_BUFFER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glReadBuffer(GLenum src);

void vkglReadBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_src);

#endif /* VKGL_GL_READ_BUFFER_H */
#ifndef VKGL_GL_CLEAR_BUFFER_IV_H
#define VKGL_GL_CLEAR_BUFFER_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glClearBufferiv(GLenum       buffer,
                                            GLint        drawbuffer,
                                            const GLint* value);

#endif /* VKGL_GL_CLEAR_BUFFER_IV_H */
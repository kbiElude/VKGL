#ifndef VKGL_GL_CLEAR_BUFFER_FI_H
#define VKGL_GL_CLEAR_BUFFER_FI_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glClearBufferfi(GLenum  buffer,
                                            GLint   drawbuffer,
                                            GLfloat depth,
                                            GLint   stencil);

#endif /* VKGL_GL_CLEAR_BUFFER_FI_H */
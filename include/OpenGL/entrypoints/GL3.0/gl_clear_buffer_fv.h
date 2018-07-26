#ifndef VKGL_GL_CLEAR_BUFFER_FV_H
#define VKGL_GL_CLEAR_BUFFER_FV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glClearBufferfv(GLenum         buffer,
                                            GLint          drawbuffer,
                                            const GLfloat* value);

#endif /* VKGL_GL_CLEAR_BUFFER_FV_H */
#ifndef VKGL_GL_GET_UNIFORMUIV_H
#define VKGL_GL_GET_UNIFORMUIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetUniformuiv(GLuint  program,
                                            GLint   location,
                                            GLuint* params);

#endif /* VKGL_GL_GET_UNIFORMUIV_H */
#ifndef VKGL_GL_GET_ACTIVE_ATTRIB_H
#define VKGL_GL_GET_ACTIVE_ATTRIB_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetActiveAttrib(GLuint   program,
                                              GLuint   index,
                                              GLsizei  bufSize,
                                              GLsizei* length,
                                              GLint*   size,
                                              GLenum*  type,
                                              GLchar*  name);

#endif /* VKGL_GL_GET_ACTIVE_ATTRIB_H */
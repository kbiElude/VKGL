#ifndef VKGL_GL_BIND_ATTRIB_LOCATION_H
#define VKGL_GL_BIND_ATTRIB_LOCATION_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBindAttribLocation(GLuint        program,
                                                 GLuint        index,
                                                 const GLchar* name);

#endif /* VKGL_GL_BIND_ATTRIB_LOCATION_H */
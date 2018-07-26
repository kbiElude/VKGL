#ifndef VKGL_GL_GET_QUERYIV_H
#define VKGL_GL_GET_QUERYIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetQueryiv(GLenum target,
                                         GLenum pname,
                                         GLint* params);

#endif /* VKGL_GL_GET_QUERYIV_H */
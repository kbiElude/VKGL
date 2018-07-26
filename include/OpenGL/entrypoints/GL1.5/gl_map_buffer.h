#ifndef VKGL_GL_MAP_BUFFER_H
#define VKGL_GL_MAP_BUFFER_H

#include "OpenGL/types.h"

VKGL_API void *APIENTRY glMapBuffer(GLenum target,
                                    GLenum access);

#endif /* VKGL_GL_MAP_BUFFER_H */
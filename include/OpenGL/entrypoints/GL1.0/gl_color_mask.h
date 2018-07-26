#ifndef VKGL_GL_COLOR_MASK_H
#define VKGL_GL_COLOR_MASK_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glColorMask(GLboolean red,
                                        GLboolean green,
                                        GLboolean blue,
                                        GLboolean alpha);

#endif /* VKGL_GL_COLOR_MASK_H */
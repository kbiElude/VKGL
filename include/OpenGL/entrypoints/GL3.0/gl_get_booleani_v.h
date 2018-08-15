/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BOOLEANI_V_H
#define VKGL_GL_GET_BOOLEANI_V_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetBooleani_v(GLenum     target,
                                            GLuint     index,
                                            GLboolean* data);

#endif /* VKGL_GL_GET_BOOLEANI_V_H */
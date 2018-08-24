/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COLOR_MASKI_H
#define VKGL_GL_COLOR_MASKI_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglColorMaski(GLuint    index,
                                  GLboolean r,
                                  GLboolean g,
                                  GLboolean b,
                                  GLboolean a);

#endif /* VKGL_GL_COLOR_MASKI_H */
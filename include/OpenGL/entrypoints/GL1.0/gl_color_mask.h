/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COLOR_MASK_H
#define VKGL_GL_COLOR_MASK_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglColorMask(GLboolean red,
                                 GLboolean green,
                                 GLboolean blue,
                                 GLboolean alpha);

#endif /* VKGL_GL_COLOR_MASK_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_ARRAYS_H
#define VKGL_GL_DRAW_ARRAYS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglDrawArrays(GLenum  mode,
                                           GLint   first,
                                           GLsizei count);

#endif /* VKGL_GL_DRAW_ARRAYS_H */
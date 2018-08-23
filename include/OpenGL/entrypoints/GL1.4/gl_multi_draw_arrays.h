/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MULTI_DRAW_ARRAYS_H
#define VKGL_GL_MULTI_DRAW_ARRAYS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglMultiDrawArrays(GLenum         mode,
                                                const GLint*   first,
                                                const GLsizei* count,
                                                GLsizei        drawcount);

#endif /* VKGL_GL_MULTI_DRAW_ARRAYS_H */
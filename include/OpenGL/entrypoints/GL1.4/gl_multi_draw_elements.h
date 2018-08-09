/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MULTI_DRAW_ELEMENTS_H
#define VKGL_GL_MULTI_DRAW_ELEMENTS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glMultiDrawElements(GLenum             mode,
                                                const GLsizei*     count,
                                                GLenum             type,
                                                const void* const* indices,
                                                GLsizei            drawcount);

#endif /* VKGL_GL_MULTI_DRAW_ELEMENTS_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_ELEMENTS_BASE_VERTEX_H
#define VKGL_GL_DRAW_ELEMENTS_BASE_VERTEX_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglDrawElementsBaseVertex(GLenum      mode,
                                                       GLsizei     count,
                                                       GLenum      type,
                                                       const void* indices,
                                                       GLint       basevertex);

#endif /* VKGL_GL_DRAW_ELEMENTS_BASE_VERTEX_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MULTI_DRAW_ELEMENTS_BASE_VERTEX_H
#define VKGL_GL_MULTI_DRAW_ELEMENTS_BASE_VERTEX_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glMultiDrawElementsBaseVertex(GLenum             mode,
                                                          const GLsizei*     count,
                                                          GLenum             type,
                                                          const void* const* indices,
                                                          GLsizei            drawcount,
                                                          const GLint*       basevertex);

void vkglMultiDrawElementsBaseVertex_with_validation(VKGL::Context*     in_context_ptr,
                                                     const GLenum&      in_mode,
                                                     const GLsizei*     in_count_ptr,
                                                     const GLenum&      in_type,
                                                     const void* const* in_indices_ptr,
                                                     const GLsizei&     in_drawcount,
                                                     const GLint*       in_basevertex_ptr);

#endif /* VKGL_GL_MULTI_DRAW_ELEMENTS_BASE_VERTEX_H */
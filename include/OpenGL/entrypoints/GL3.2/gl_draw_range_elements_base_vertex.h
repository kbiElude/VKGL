/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_RANGE_ELEMENTS_BASE_VERTEX_H
#define VKGL_GL_DRAW_RANGE_ELEMENTS_BASE_VERTEX_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDrawRangeElementsBaseVertex(GLenum      mode,
                                                          GLuint      start,
                                                          GLuint      end,
                                                          GLsizei     count,
                                                          GLenum      type,
                                                          const void* indices,
                                                          GLint       basevertex);

void vkglDrawRangeElementsBaseVertex_with_validation(VKGL::Context* in_context_ptr,
                                                     const GLenum&  in_mode,
                                                     const GLuint&  in_start,
                                                     const GLuint&  in_end,
                                                     const GLsizei& in_count,
                                                     const GLenum&  in_type,
                                                     const void*    in_indices,
                                                     const GLint&   in_basevertex);

#endif /* VKGL_GL_DRAW_RANGE_ELEMENTS_BASE_VERTEX_H */
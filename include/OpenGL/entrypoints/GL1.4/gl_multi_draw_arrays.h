/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MULTI_DRAW_ARRAYS_H
#define VKGL_GL_MULTI_DRAW_ARRAYS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glMultiDrawArrays(GLenum         mode,
                                              const GLint*   first,
                                              const GLsizei* count,
                                              GLsizei        drawcount);

void vkglMultiDrawArrays_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_mode,
                                         const GLint*   in_first_ptr,
                                         const GLsizei* in_count_ptr,
                                         const GLsizei& in_drawcount);

#endif /* VKGL_GL_MULTI_DRAW_ARRAYS_H */
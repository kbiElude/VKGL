/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_ARRAYS_H
#define VKGL_GL_DRAW_ARRAYS_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglDrawArrays(GLenum  mode,
                                  GLint   first,
                                  GLsizei count);

void vkglDrawArrays_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_mode,
                                    const GLint&   in_first,
                                    const GLsizei& in_count);

#endif /* VKGL_GL_DRAW_ARRAYS_H */
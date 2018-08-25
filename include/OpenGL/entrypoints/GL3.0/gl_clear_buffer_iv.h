/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_IV_H
#define VKGL_GL_CLEAR_BUFFER_IV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglClearBufferiv(GLenum       buffer,
                                     GLint        drawbuffer,
                                     const GLint* value);

void vkglClearBufferiv_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_buffer,
                                       const GLint&   in_drawbuffer,
                                       const GLint*   in_value_ptr);

#endif /* VKGL_GL_CLEAR_BUFFER_IV_H */
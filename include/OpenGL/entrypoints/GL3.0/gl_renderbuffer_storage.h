/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_RENDERBUFFER_STORAGE_H
#define VKGL_GL_RENDERBUFFER_STORAGE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglRenderbufferStorage(GLenum  target,
                                           GLenum  internalformat,
                                           GLsizei width,
                                           GLsizei height);

void vkglRenderbufferStorage_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_target,
                                             const GLenum&  in_internalformat,
                                             const GLsizei& in_width,
                                             const GLsizei& in_height);

#endif /* VKGL_GL_RENDERBUFFER_STORAGE_H */
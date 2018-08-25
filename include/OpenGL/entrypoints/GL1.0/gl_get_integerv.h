/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_INTEGERV_H
#define VKGL_GL_GET_INTEGERV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetIntegerv(GLenum pname,
                                   GLint* data);

void vkglGetIntegerv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLint*         out_data_ptr);
#endif /* VKGL_GL_GET_INTEGERV_H */
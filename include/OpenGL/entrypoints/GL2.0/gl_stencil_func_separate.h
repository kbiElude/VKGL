/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_FUNC_SEPARATE_H
#define VKGL_GL_STENCIL_FUNC_SEPARATE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglStencilFuncSeparate(GLenum face,
                                           GLenum func,
                                           GLint  ref,
                                           GLuint mask);

#endif /* VKGL_GL_STENCIL_FUNC_SEPARATE_H */
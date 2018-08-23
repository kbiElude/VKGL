/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_FUNC_H
#define VKGL_GL_STENCIL_FUNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglStencilFunc(GLenum func,
                                            GLint  ref,
                                            GLuint mask);

#endif /* VKGL_GL_STENCIL_FUNC_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_OP_H
#define VKGL_GL_STENCIL_OP_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglStencilOp(GLenum fail,
                                          GLenum zfail,
                                          GLenum zpass);

#endif /* VKGL_GL_STENCIL_OP_H */
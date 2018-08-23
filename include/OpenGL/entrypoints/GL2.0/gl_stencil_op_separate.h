/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_OP_SEPARATE_H
#define VKGL_GL_STENCIL_OP_SEPARATE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglStencilOpSeparate(GLenum face,
                                                  GLenum sfail,
                                                  GLenum dpfail,
                                                  GLenum dppass);

#endif /* VKGL_GL_STENCIL_OP_SEPARATE_H */
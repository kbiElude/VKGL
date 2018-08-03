/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_OP_H
#define VKGL_GL_STENCIL_OP_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilOp(GLenum fail,
                                        GLenum zfail,
                                        GLenum zpass);

void vkglStencilOp_with_validation(VKGL::Context* in_context_ptr,
                                   GLenum         in_fail,
                                   GLenum         in_zfail,
                                   GLenum         in_zpass);

#endif /* VKGL_GL_STENCIL_OP_H */
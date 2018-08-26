/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_OP_SEPARATE_H
#define VKGL_GL_STENCIL_OP_SEPARATE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglStencilOpSeparate(GLenum face,
                                         GLenum sfail,
                                         GLenum dpfail,
                                         GLenum dppass);

void vkglStencilOpSeparate_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_face,
                                           const GLenum&  in_sfail,
                                           const GLenum&  in_dpfail,
                                           const GLenum&  in_dppass);

#endif /* VKGL_GL_STENCIL_OP_SEPARATE_H */
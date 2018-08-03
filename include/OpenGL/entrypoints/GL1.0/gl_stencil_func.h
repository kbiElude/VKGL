/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_FUNC_H
#define VKGL_GL_STENCIL_FUNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilFunc(GLenum func,
                                          GLint  ref,
                                          GLuint mask);

void vkglStencilFunc_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_func,
                                     const GLint&   in_ref,
                                     const GLuint&  in_mask);

#endif /* VKGL_GL_STENCIL_FUNC_H */
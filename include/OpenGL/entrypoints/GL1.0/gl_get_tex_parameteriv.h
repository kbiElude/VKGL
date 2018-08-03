/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_PARAMETER_IV_H
#define VKGL_GL_GET_TEX_PARAMETER_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexParameteriv(GLenum target,
                                                GLenum pname,
                                                GLint* params);

void vkglGetTexParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_target,
                                           const GLenum&  in_pname,
                                           GLint*         out_params_ptr);

#endif /* VKGL_GL_GET_TEX_PARAMETER_IV_H */
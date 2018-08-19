/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETER_I_IV_H
#define VKGL_GL_TEX_PARAMETER_I_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameterIiv(GLenum       target,
                                              GLenum       pname,
                                              const GLint* params);

void vkglTexParameterIiv_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_target,
                                         const GLenum&  in_pname,
                                         const GLint*   in_params_ptr);

#endif /* VKGL_GL_TEX_PARAMETER_I_IV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERIV_H
#define VKGL_GL_TEX_PARAMETERIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameteriv(GLenum       target,
                                             GLenum       pname,
                                             const GLint* params);

void vkglTexParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLenum&  in_pname,
                                        const GLint*   in_params_ptr);

#endif /* VKGL_GL_TEX_PARAMETERIV_H */
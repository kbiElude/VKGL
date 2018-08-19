/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETER_I_UIV_H
#define VKGL_GL_TEX_PARAMETER_I_UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameterIuiv(GLenum        target,
                                               GLenum        pname,
                                               const GLuint* params);

void vkglTexParameterIuiv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLenum&  in_target,
                                          const GLenum&  in_pname,
                                          const GLuint*  in_params_ptr);

#endif /* VKGL_GL_TEX_PARAMETER_I_UIV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_LEVEL_PARAMETERIV_H
#define VKGL_GL_GET_TEX_LEVEL_PARAMETERIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetTexLevelParameteriv(GLenum target,
                                              GLint  level,
                                              GLenum pname,
                                              GLint* params);

void vkglGetTexLevelParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLint&   in_level,
                                                const GLenum&  in_pname,
                                                GLint*         out_params_ptr);

#endif /* VKGL_GL_GET_TEX_LEVEL_PARAMETERIV_H */
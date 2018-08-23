/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETER_I_IV_H
#define VKGL_GL_TEX_PARAMETER_I_IV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglTexParameterIiv(GLenum       target,
                                                GLenum       pname,
                                                const GLint* params);

#endif /* VKGL_GL_TEX_PARAMETER_I_IV_H */
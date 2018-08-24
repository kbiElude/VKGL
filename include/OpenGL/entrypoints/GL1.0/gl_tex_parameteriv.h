/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERIV_H
#define VKGL_GL_TEX_PARAMETERIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexParameteriv(GLenum       target,
                                      GLenum       pname,
                                      const GLint* params);

#endif /* VKGL_GL_TEX_PARAMETERIV_H */
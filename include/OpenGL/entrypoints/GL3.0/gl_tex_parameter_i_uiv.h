/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETER_I_UIV_H
#define VKGL_GL_TEX_PARAMETER_I_UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglTexParameterIuiv(GLenum        target,
                                                 GLenum        pname,
                                                 const GLuint* params);

#endif /* VKGL_GL_TEX_PARAMETER_I_UIV_H */
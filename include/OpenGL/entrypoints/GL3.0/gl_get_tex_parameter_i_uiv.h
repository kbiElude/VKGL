/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_PARAMETER_I_UIV_H
#define VKGL_GL_GET_TEX_PARAMETER_I_UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetTexParameterIuiv(GLenum  target,
                                                    GLenum  pname,
                                                    GLuint* params);

#endif /* VKGL_GL_GET_TEX_PARAMETER_I_UIV_H */
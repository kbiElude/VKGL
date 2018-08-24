/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERF_H
#define VKGL_GL_TEX_PARAMETERF_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexParameterf(GLenum  target,
                                     GLenum  pname,
                                     GLfloat param);

#endif /* VKGL_GL_TEX_PARAMETERF_H */
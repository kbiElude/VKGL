/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H
#define VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetTexLevelParameterfv(GLenum   target,
                                              GLint    level,
                                              GLenum   pname,
                                              GLfloat* params);

#endif /* VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H */
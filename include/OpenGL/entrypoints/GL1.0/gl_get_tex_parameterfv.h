/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_PARAMETER_FV_H
#define VKGL_GL_GET_TEX_PARAMETER_FV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetTexParameterfv(GLenum   target,
                                         GLenum   pname,
                                         GLfloat* params);

#endif /* VKGL_GL_GET_TEX_PARAMETER_FV_H */
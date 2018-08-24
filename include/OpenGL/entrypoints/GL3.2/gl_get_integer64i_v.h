/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_INTEGER64I_V_H
#define VKGL_GL_GET_INTEGER64I_V_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetInteger64i_v(GLenum   target,
                                       GLuint   index,
                                       GLint64* data);

#endif /* VKGL_GL_GET_INTEGER64I_V_H */
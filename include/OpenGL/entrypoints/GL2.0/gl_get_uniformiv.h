/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORMIV_H
#define VKGL_GL_GET_UNIFORMIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetUniformiv(GLuint program,
                                             GLint  location,
                                             GLint* params);

#endif /* VKGL_GL_GET_UNIFORMIV_H */
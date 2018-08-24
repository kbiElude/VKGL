/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_1UIV_H
#define VKGL_GL_UNIFORM_1UIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform1uiv(GLint         location,
                                   GLsizei       count,
                                   const GLuint* value);

#endif /* VKGL_GL_UNIFORM_1UIV_H */
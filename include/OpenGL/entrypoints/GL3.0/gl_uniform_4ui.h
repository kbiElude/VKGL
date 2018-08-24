/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_4UI_H
#define VKGL_GL_UNIFORM_4UI_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglUniform4ui(GLint  location,
                                  GLuint v0,
                                  GLuint v1,
                                  GLuint v2,
                                  GLuint v3);

#endif /* VKGL_GL_UNIFORM_4UI_H */
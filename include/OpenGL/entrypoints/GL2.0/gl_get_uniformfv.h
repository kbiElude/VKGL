/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORMFV_H
#define VKGL_GL_GET_UNIFORMFV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetUniformfv(GLuint   program,
                                    GLint    location,
                                    GLfloat* params);

#endif /* VKGL_GL_GET_UNIFORMFV_H */
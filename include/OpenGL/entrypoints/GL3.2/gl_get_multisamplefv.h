/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_MULTISAMPLEFV_H
#define VKGL_GL_GET_MULTISAMPLEFV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetMultisamplefv(GLenum   pname,
                                        GLuint   index,
                                        GLfloat* val);

#endif /* VKGL_GL_GET_MULTISAMPLEFV_H */
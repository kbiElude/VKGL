/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_VERTEX_ATTRIBFV_H
#define VKGL_GL_GET_VERTEX_ATTRIBFV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetVertexAttribfv(GLuint   index,
                                         GLenum   pname,
                                         GLfloat* params);

#endif /* VKGL_GL_GET_VERTEX_ATTRIBFV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4F_H
#define VKGL_GL_VERTEX_ATTRIB_4F_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglVertexAttrib4f(GLuint  index,
                                               GLfloat x,
                                               GLfloat y,
                                               GLfloat z,
                                               GLfloat w);

#endif /* VKGL_GL_VERTEX_ATTRIB_4F_H */
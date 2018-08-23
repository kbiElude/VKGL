/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4S_H
#define VKGL_GL_VERTEX_ATTRIB_4S_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglVertexAttrib4s(GLuint  index,
                                               GLshort x,
                                               GLshort y,
                                               GLshort z,
                                               GLshort w);

#endif /* VKGL_GL_VERTEX_ATTRIB_4S_H */
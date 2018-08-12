/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_VERTEX_ATTRIBDV_H
#define VKGL_GL_GET_VERTEX_ATTRIBDV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetVertexAttribdv(GLuint    index,
                                                GLenum    pname,
                                                GLdouble* params);

#endif /* VKGL_GL_GET_VERTEX_ATTRIBDV_H */
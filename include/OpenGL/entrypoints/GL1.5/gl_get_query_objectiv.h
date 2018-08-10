/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_QUERY_OBJECTIV_H
#define VKGL_GL_GET_QUERY_OBJECTIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetQueryObjectiv(GLuint id,
                                               GLenum pname,
                                               GLint* params);

#endif /* VKGL_GL_GET_QUERY_OBJECTIV_H */
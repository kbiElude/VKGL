/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_QUERY_OBJECTUIV_H
#define VKGL_GL_GET_QUERY_OBJECTUIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetQueryObjectuiv(GLuint  id,
                                                  GLenum  pname,
                                                  GLuint* params);

#endif /* VKGL_GL_GET_QUERY_OBJECTUIV_H */
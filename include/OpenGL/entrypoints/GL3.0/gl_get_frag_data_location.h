/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_FRAG_DATA_LOCATION_H
#define VKGL_GL_GET_FRAG_DATA_LOCATION_H

#include "OpenGL/types.h"

VKGL_API GLint VKGL_APIENTRY glGetFragDataLocation(GLuint        program,
                                                   const GLchar* name);

#endif /* VKGL_GL_GET_FRAG_DATA_LOCATION_H */
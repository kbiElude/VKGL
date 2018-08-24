/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_ATTRIB_LOCATION_H
#define VKGL_GL_BIND_ATTRIB_LOCATION_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBindAttribLocation(GLuint        program,
                                          GLuint        index,
                                          const GLchar* name);

#endif /* VKGL_GL_BIND_ATTRIB_LOCATION_H */
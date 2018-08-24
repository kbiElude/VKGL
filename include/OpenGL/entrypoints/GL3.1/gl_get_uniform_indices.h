/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORM_INDICES_H
#define VKGL_GL_GET_UNIFORM_INDICES_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetUniformIndices(GLuint               program,
                                         GLsizei              uniformCount,
                                         const GLchar* const* uniformNames,
                                         GLuint*              uniformIndices);

#endif /* VKGL_GL_GET_UNIFORM_INDICES_H */
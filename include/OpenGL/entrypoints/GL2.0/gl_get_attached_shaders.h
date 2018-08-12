/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ATTACHED_SHADERS_H
#define VKGL_GL_GET_ATTACHED_SHADERS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetAttachedShaders(GLuint   program,
                                                 GLsizei  maxCount,
                                                 GLsizei* count,
                                                 GLuint*  shaders);

#endif /* VKGL_GL_GET_ATTACHED_SHADERS_H */
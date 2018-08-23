/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SHADER_SOURCE_H
#define VKGL_GL_SHADER_SOURCE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglShaderSource(GLuint               shader,
                                             GLsizei              count,
                                             const GLchar* const* string,
                                             const GLint*         length);

#endif /* VKGL_GL_SHADER_SOURCE_H */
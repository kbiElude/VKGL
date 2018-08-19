/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CREATE_PROGRAM_H
#define VKGL_GL_CREATE_PROGRAM_H

#include "OpenGL/types.h"

VKGL_API GLuint VKGL_APIENTRY glCreateProgram(void);

GLuint vkglCreateProgram_with_validation(VKGL::Context* in_context_ptr);

#endif /* VKGL_GL_CREATE_PROGRAM_H */
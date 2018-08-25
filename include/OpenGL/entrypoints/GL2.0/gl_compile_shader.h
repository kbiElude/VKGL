/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPILE_SHADER_H
#define VKGL_GL_COMPILE_SHADER_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCompileShader(GLuint shader);

void vkglCompileShader_with_validation(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_shader);

#endif /* VKGL_GL_COMPILE_SHADER_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CREATE_SHADER_H
#define VKGL_GL_CREATE_SHADER_H

#include "OpenGL/types.h"

GLuint VKGL_APIENTRY vkglCreateShader(GLenum type);

GLuint vkglCreateShader_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_type);

#endif /* VKGL_GL_CREATE_SHADER_H */
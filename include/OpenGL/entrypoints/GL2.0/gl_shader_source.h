/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SHADER_SOURCE_H
#define VKGL_GL_SHADER_SOURCE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglShaderSource(GLuint               shader,
                                        GLsizei              count,
                                        const GLchar* const* string,
                                        const GLint*         length);

    void vkglShaderSource_with_validation(OpenGL::Context*     in_context_ptr,
                                          const GLuint&        in_shader,
                                          const GLsizei&       in_count,
                                          const GLchar* const* in_string_ptr_ptr,
                                          const GLint*         in_length_ptr);
}

#endif /* VKGL_GL_SHADER_SOURCE_H */
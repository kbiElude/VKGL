/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_TEXTURES_H
#define VKGL_GL_DELETE_TEXTURES_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDeleteTextures(GLsizei       n,
                                             const GLuint* textures);

void vkglDeleteTextures_with_validation(VKGL::Context* in_context_ptr,
                                        const GLsizei& in_n,
                                        const GLuint*  in_textures);

#endif /* VKGL_GL_DELETE_TEXTURES_H */
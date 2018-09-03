/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_TEXTURES_H
#define VKGL_GL_DELETE_TEXTURES_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDeleteTextures(GLsizei       n,
                                          const GLuint* textures);

    void vkglDeleteTextures_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLsizei&   in_n,
                                            const GLuint*    in_textures);
}

#endif /* VKGL_GL_DELETE_TEXTURES_H */
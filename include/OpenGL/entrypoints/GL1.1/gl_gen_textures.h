/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GEN_TEXTURES_H
#define VKGL_GL_GEN_TEXTURES_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGenTextures(GLsizei n,
                                       GLuint* textures);

    void vkglGenTextures_with_validation(VKGL::Context* in_context_ptr,
                                         const GLsizei& in_n,
                                         GLuint*        in_textures);
}

#endif /* VKGL_GL_GEN_TEXTURES_H */
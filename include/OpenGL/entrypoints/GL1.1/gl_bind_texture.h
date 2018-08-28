/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_TEXTURE_H
#define VKGL_GL_BIND_TEXTURE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBindTexture(GLenum target,
                                       GLuint texture);

    void vkglBindTexture_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_target,
                                         const GLuint&  in_texture);
}

#endif /* VKGL_GL_BIND_TEXTURE_H */
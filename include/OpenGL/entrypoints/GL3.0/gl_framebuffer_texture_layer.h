/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_TEXTURE_LAYER_H
#define VKGL_GL_FRAMEBUFFER_TEXTURE_LAYER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglFramebufferTextureLayer(GLenum target,
                                                   GLenum attachment,
                                                   GLuint texture,
                                                   GLint  level,
                                                   GLint  layer);

    void vkglFramebufferTextureLayer_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_target,
                                                     const GLenum&    in_attachment,
                                                     const GLuint&    in_texture,
                                                     const GLint&     in_level,
                                                     const GLint&     in_layer);
}

#endif /* VKGL_GL_FRAMEBUFFER_TEXTURE_LAYER_H */
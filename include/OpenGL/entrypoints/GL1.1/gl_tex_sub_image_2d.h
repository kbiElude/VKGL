/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_SUB_IMAGE_2D_H
#define VKGL_GL_TEX_SUB_IMAGE_2D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglTexSubImage2D(GLenum      target,
                                         GLint       level,
                                         GLint       xoffset,
                                         GLint       yoffset,
                                         GLsizei     width,
                                         GLsizei     height,
                                         GLenum      format,
                                         GLenum      type,
                                         const void* pixels);

    void vkglTexSubImage2D_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_target,
                                           const GLint&     in_level,
                                           const GLint&     in_xoffset,
                                           const GLint&     in_yoffset,
                                           const GLsizei&   in_width,
                                           const GLsizei&   in_height,
                                           const GLenum&    in_format,
                                           const GLenum&    in_type,
                                           const void*      in_pixels);
}

#endif /* VKGL_GL_TEX_SUB_IMAGE_2D_H */
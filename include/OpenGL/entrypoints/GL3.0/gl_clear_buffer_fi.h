/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_FI_H
#define VKGL_GL_CLEAR_BUFFER_FI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglClearBufferfi(GLenum  buffer,
                                         GLint   drawbuffer,
                                         GLfloat depth,
                                         GLint   stencil);

    void vkglClearBufferfi_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_buffer,
                                           const GLint&   in_drawbuffer,
                                           const GLfloat& in_depth,
                                           const GLint&   in_stencil);
}

#endif /* VKGL_GL_CLEAR_BUFFER_FI_H */
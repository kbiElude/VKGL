/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_FV_H
#define VKGL_GL_CLEAR_BUFFER_FV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglClearBufferfv(GLenum         buffer,
                                         GLint          drawbuffer,
                                         const GLfloat* value);

    void vkglClearBufferfv_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_buffer,
                                           const GLint&     in_drawbuffer,
                                           const GLfloat*   in_value_ptr);
}

#endif /* VKGL_GL_CLEAR_BUFFER_FV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BUFFER_SUB_DATA_H
#define VKGL_GL_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBufferSubData(GLenum      target,
                                         GLintptr    offset,
                                         GLsizeiptr  size,
                                         const void* data);

    void vkglBufferSubData_with_validation(OpenGL::Context*  in_context_ptr,
                                           const GLenum&     in_target,
                                           const GLintptr&   in_offset,
                                           const GLsizeiptr& in_size,
                                           const void*       in_data);
}

#endif /* VKGL_GL_BUFFER_SUB_DATA_H */
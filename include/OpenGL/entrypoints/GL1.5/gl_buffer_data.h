/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BUFFER_DATA_H
#define VKGL_GL_BUFFER_DATA_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBufferData(GLenum      target,
                                      GLsizeiptr  size,
                                      const void* data,
                                      GLenum      usage);

    void vkglBufferData_with_validation(VKGL::Context*    in_context_ptr,
                                        const GLenum&     in_target,
                                        const GLsizeiptr& in_size,
                                        const void*       in_data,
                                        const GLenum&     in_usage);
}

#endif /* VKGL_GL_BUFFER_DATA_H */
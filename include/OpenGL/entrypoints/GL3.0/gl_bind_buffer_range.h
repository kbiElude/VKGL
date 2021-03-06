/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_BUFFER_RANGE_H
#define VKGL_GL_BIND_BUFFER_RANGE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBindBufferRange(GLenum     target,
                                           GLuint     index,
                                           GLuint     buffer,
                                           GLintptr   offset,
                                           GLsizeiptr size);

    void vkglBindBufferRange_with_validation(OpenGL::Context*  in_context_ptr,
                                             const GLenum&     in_target,
                                             const GLuint&     in_index,
                                             const GLuint&     in_buffer,
                                             const GLintptr&   in_offset,
                                             const GLsizeiptr& in_size);
}

#endif /* VKGL_GL_BIND_BUFFER_RANGE_H */
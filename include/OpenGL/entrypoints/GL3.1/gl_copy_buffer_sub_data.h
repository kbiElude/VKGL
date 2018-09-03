/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_BUFFER_SUB_DATA_H
#define VKGL_GL_COPY_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglCopyBufferSubData(GLenum     readTarget,
                                             GLenum     writeTarget,
                                             GLintptr   readOffset,
                                             GLintptr   writeOffset,
                                             GLsizeiptr size);

    void vkglCopyBufferSubData_with_validation(OpenGL::Context*  in_context_ptr,
                                               const GLenum&     in_read_target,
                                               const GLenum&     in_write_target,
                                               const GLintptr&   in_read_offset,
                                               const GLintptr&   in_write_offset,
                                               const GLsizeiptr& in_size);
}

#endif /* VKGL_GL_COPY_BUFFER_SUB_DATA_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FLUSH_MAPPED_BUFFER_RANGE_H
#define VKGL_GL_FLUSH_MAPPED_BUFFER_RANGE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglFlushMappedBufferRange(GLenum     target,
                                                  GLintptr   offset,
                                                  GLsizeiptr length);

    void vkglFlushMappedBufferRange_with_validation(VKGL::Context*    in_context_ptr,
                                                    const GLenum&     in_target,
                                                    const GLintptr&   in_offset,
                                                    const GLsizeiptr& in_length);
}

#endif /* VKGL_GL_FLUSH_MAPPED_BUFFER_RANGE_H */
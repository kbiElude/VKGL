/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BUFFER_SUB_DATA_H
#define VKGL_GL_GET_BUFFER_SUB_DATA_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetBufferSubData(GLenum     target,
                                        GLintptr   offset,
                                        GLsizeiptr size,
                                        void*      data);

void vkglGetBufferSubData_with_validation(VKGL::Context*    in_context_ptr,
                                          const GLenum&     in_target,
                                          const GLintptr&   in_offset,
                                          const GLsizeiptr& in_size,
                                          void*             in_data);

#endif /* VKGL_GL_GET_BUFFER_SUB_DATA_H */
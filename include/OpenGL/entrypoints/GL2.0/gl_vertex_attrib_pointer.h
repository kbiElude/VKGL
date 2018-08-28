/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_POINTER_H
#define VKGL_GL_VERTEX_ATTRIB_POINTER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttribPointer(GLuint      index,
                                               GLint       size,
                                               GLenum      type,
                                               GLboolean   normalized,
                                               GLsizei     stride,
                                               const void* pointer);

    void vkglVertexAttribPointer_with_validation(VKGL::Context*   in_context_ptr,
                                                 const GLuint&    in_index,
                                                 const GLint&     in_size,
                                                 const GLenum&    in_type,
                                                 const GLboolean& in_normalized,
                                                 const GLsizei&   in_stride,
                                                 const void*      in_pointer_ptr);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_POINTER_H */
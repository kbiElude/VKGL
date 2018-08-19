/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_POINTER_H
#define VKGL_GL_VERTEX_ATTRIB_I_POINTER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttribIPointer(GLuint      index,
                                                   GLint       size,
                                                   GLenum      type,
                                                   GLsizei     stride,
                                                   const void* pointer);

void vkglVertexAttribIPointer_with_validation(VKGL::Context*   in_context_ptr,
                                              const GLuint&    in_index,
                                              const GLint&     in_size,
                                              const GLenum&    in_type,
                                              const GLsizei&   in_stride,
                                              const void*      in_pointer_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_POINTER_H */
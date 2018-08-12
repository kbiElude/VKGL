/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_POINTER_H
#define VKGL_GL_VERTEX_ATTRIB_POINTER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttribPointer(GLuint      index,
                                                  GLint       size,
                                                  GLenum      type,
                                                  GLboolean   normalized,
                                                  GLsizei     stride,
                                                  const void* pointer);

#endif /* VKGL_GL_VERTEX_ATTRIB_POINTER_H */
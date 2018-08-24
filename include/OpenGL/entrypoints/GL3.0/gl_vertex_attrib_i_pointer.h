/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_POINTER_H
#define VKGL_GL_VERTEX_ATTRIB_I_POINTER_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglVertexAttribIPointer(GLuint      index,
                                            GLint       size,
                                            GLenum      type,
                                            GLsizei     stride,
                                            const void* pointer);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_POINTER_H */
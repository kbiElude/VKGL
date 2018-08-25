/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_VERTEX_ATTRIB_POINTERV_H
#define VKGL_GL_GET_VERTEX_ATTRIB_POINTERV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetVertexAttribPointerv(GLuint index,
                                               GLenum pname,
                                               void** pointer);

void vkglGetVertexAttribPointerv_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLuint&  in_index,
                                                 const GLenum&  in_pname,
                                                 void**         out_pointer_ptr);

#endif /* VKGL_GL_GET_VERTEX_ATTRIB_POINTERV_H */
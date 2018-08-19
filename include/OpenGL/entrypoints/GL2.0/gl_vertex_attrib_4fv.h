/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4FV_H
#define VKGL_GL_VERTEX_ATTRIB_4FV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttrib4fv(GLuint         index,
                                              const GLfloat* v);

void vkglVertexAttrib4fv_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLfloat* in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_4FV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_1F_H
#define VKGL_GL_VERTEX_ATTRIB_1F_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttrib1f(GLuint  index,
                                             GLfloat x);

void vkglVertexAttrib1f_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLfloat& in_x);

#endif /* VKGL_GL_VERTEX_ATTRIB_1F_H */
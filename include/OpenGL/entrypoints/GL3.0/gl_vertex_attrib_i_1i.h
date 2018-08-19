/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_1I_H
#define VKGL_GL_VERTEX_ATTRIB_I_1I_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttribI1i(GLuint index,
                                              GLint  x);

void vkglVertexAttribI1i_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLint&   in_x);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_1I_H */
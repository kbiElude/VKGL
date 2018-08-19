/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4S_H
#define VKGL_GL_VERTEX_ATTRIB_4S_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttrib4s(GLuint  index,
                                             GLshort x,
                                             GLshort y,
                                             GLshort z,
                                             GLshort w);

void vkglVertexAttrib4s_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLshort& in_x,
                                        const GLshort& in_y,
                                        const GLshort& in_z,
                                        const GLshort& in_w);

#endif /* VKGL_GL_VERTEX_ATTRIB_4S_H */
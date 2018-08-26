/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_3SV_H
#define VKGL_GL_VERTEX_ATTRIB_3SV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglVertexAttrib3sv(GLuint         index,
                                       const GLshort* v);

void vkglVertexAttrib3sv_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLshort* in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_3SV_H */
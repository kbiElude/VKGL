/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_1SV_H
#define VKGL_GL_VERTEX_ATTRIB_1SV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttrib1sv(GLuint         index,
                                              const GLshort* v);

void vkglVertexAttrib1sv_with_validation(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLshort* in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_1SV_H */
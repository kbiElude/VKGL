/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_4BV_H
#define VKGL_GL_VERTEX_ATTRIB_I_4BV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttribI4bv(GLuint        index,
                                               const GLbyte* v);

void vkglVertexAttribI4bv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_index,
                                          const GLbyte*  in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_4BV_H */
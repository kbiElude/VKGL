/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_1UIV_H
#define VKGL_GL_VERTEX_ATTRIB_I_1UIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglVertexAttribI1uiv(GLuint        index,
                                         const GLuint* v);

void vkglVertexAttribI1uiv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_index,
                                           const GLuint*  in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_1UIV_H */
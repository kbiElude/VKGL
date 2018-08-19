/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4UIV_H
#define VKGL_GL_VERTEX_ATTRIB_4UIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glVertexAttrib4uiv(GLuint        index,
                                               const GLuint* v);

void vkglVertexAttrib4uiv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_index,
                                          const GLuint*  in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_4UIV_H */
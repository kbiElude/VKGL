/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_4UBV_H
#define VKGL_GL_VERTEX_ATTRIB_I_4UBV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglVertexAttribI4ubv(GLuint         index,
                                         const GLubyte* v);

void vkglVertexAttribI4ubv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_index,
                                           const GLubyte* in_v_ptr);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_4UBV_H */
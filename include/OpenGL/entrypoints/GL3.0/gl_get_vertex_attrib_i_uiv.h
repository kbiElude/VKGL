/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_VERTEX_ATTRIB_I_UIV_H
#define VKGL_GL_GET_VERTEX_ATTRIB_I_UIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetVertexAttribIuiv(GLuint  index,
                                           GLenum  pname,
                                           GLuint* params);

void vkglGetVertexAttribIuiv_with_validation(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_index,
                                             const GLenum&  in_pname,
                                             GLuint*        out_params_ptr);

#endif /* VKGL_GL_GET_VERTEX_ATTRIB_I_UIV_H */
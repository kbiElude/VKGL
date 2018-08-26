/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_QUERY_OBJECTIV_H
#define VKGL_GL_GET_QUERY_OBJECTIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetQueryObjectiv(GLuint id,
                                        GLenum pname,
                                        GLint* params);

void vkglGetQueryObjectiv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_id,
                                          const GLenum&  in_pname,
                                          GLint*         out_params_ptr);

#endif /* VKGL_GL_GET_QUERY_OBJECTIV_H */
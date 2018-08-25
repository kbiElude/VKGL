/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_QUERY_OBJECTUIV_H
#define VKGL_GL_GET_QUERY_OBJECTUIV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetQueryObjectuiv(GLuint  id,
                                         GLenum  pname,
                                         GLuint* params);

void vkglGetQueryObjectuiv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_id,
                                           const GLenum&  in_pname,
                                           GLuint*        out_params_ptr);

#endif /* VKGL_GL_GET_QUERY_OBJECTUIV_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BUFFER_PARAMETERI64V_H
#define VKGL_GL_GET_BUFFER_PARAMETERI64V_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetBufferParameteri64v(GLenum   target,
                                              GLenum   pname,
                                              GLint64* params);

void vkglGetBufferParameteri64v_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLenum&  in_pname,
                                                GLint64*       out_params_ptr);

#endif /* VKGL_GL_GET_BUFFER_PARAMETERI64V_H */
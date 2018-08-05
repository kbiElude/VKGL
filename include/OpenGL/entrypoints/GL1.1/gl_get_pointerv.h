/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_POINTERV_H
#define VKGL_GL_GET_POINTERV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetPointerv(GLenum pname,
                                          void** params);

void vkglGetPointerv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     void**         in_params);

#endif /* VKGL_GL_GET_POINTERV_H */
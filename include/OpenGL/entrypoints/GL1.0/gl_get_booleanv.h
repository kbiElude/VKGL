/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BOOLEANV_H
#define VKGL_GL_GET_BOOLEANV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetBooleanv(GLenum     pname,
                                   GLboolean* data);

void vkglGetBooleanv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLboolean*     out_data_ptr);

#endif /* VKGL_GL_GET_BOOLEANV_H */
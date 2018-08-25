/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERF_H
#define VKGL_GL_TEX_PARAMETERF_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglTexParameterf(GLenum  target,
                                     GLenum  pname,
                                     GLfloat param);

void vkglTexParameterf_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_target,
                                       const GLenum&  in_pname,
                                       const GLfloat& in_param);

#endif /* VKGL_GL_TEX_PARAMETERF_H */
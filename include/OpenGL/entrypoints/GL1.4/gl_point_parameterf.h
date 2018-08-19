/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_PARAMETERF_H
#define VKGL_GL_POINT_PARAMETERF_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glPointParameterf(GLenum  pname,
                                              GLfloat param);

void vkglPointParameterf_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_pname,
                                         const GLfloat& in_param);

#endif /* VKGL_GL_POINT_PARAMETERF_H */
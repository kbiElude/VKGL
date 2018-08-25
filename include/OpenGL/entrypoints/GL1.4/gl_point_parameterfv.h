/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_PARAMETERFV_H
#define VKGL_GL_POINT_PARAMETERFV_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglPointParameterfv(GLenum         pname,
                                        const GLfloat* params);

void vkglPointParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLenum&  in_pname,
                                          const GLfloat* in_params);

#endif /* VKGL_GL_POINT_PARAMETERFV_H */
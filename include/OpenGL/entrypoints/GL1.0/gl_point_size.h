/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_SIZE_H
#define VKGL_GL_POINT_SIZE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glPointSize(GLfloat size);

void vkglPointSize_with_validation(VKGL::Context* in_context_ptr,
                                   const GLfloat& in_size);

#endif /* VKGL_GL_POINT_SIZE_H */
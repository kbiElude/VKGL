/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DEPTH_RANGE_H
#define VKGL_GL_DEPTH_RANGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDepthRange(GLdouble n,
                                         GLdouble f);

void vkglDepthRange_with_validation(VKGL::Context*  in_context_ptr,
                                    const GLdouble& in_n,
                                    const GLdouble& in_f);

#endif /* VKGL_GL_DEPTH_RANGE_H */
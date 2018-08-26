/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_END_TRANSFORM_FEEDBACK_H
#define VKGL_GL_END_TRANSFORM_FEEDBACK_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglEndTransformFeedback(void);

void vkglEndTransformFeedback_with_validation(VKGL::Context* in_context_ptr);

#endif /* VKGL_GL_END_TRANSFORM_FEEDBACK_H */
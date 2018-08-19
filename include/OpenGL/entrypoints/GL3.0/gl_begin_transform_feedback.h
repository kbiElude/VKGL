/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BEGIN_TRANSFORM_FEEDBACK_H
#define VKGL_GL_BEGIN_TRANSFORM_FEEDBACK_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBeginTransformFeedback(GLenum primitiveMode);

void vkglBeginTransformFeedback_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_primitive_mode);

#endif /* VKGL_GL_BEGIN_TRANSFORM_FEEDBACK_H */
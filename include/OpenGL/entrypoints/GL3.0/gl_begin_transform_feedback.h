/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BEGIN_TRANSFORM_FEEDBACK_H
#define VKGL_GL_BEGIN_TRANSFORM_FEEDBACK_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBeginTransformFeedback(GLenum primitiveMode);

    void vkglBeginTransformFeedback_with_validation(OpenGL::Context* in_context_ptr,
                                                    const GLenum&    in_primitive_mode);
}

#endif /* VKGL_GL_BEGIN_TRANSFORM_FEEDBACK_H */
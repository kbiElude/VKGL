/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TRANSFORM_FEEDBACK_VARYINGS_H
#define VKGL_GL_TRANSFORM_FEEDBACK_VARYINGS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglTransformFeedbackVaryings(GLuint               program,
                                                     GLsizei              count,
                                                     const GLchar* const* varyings,
                                                     GLenum               bufferMode);

    void vkglTransformFeedbackVaryings_with_validation(VKGL::Context*       in_context_ptr,
                                                       const GLuint&        in_program,
                                                       const GLsizei&       in_count,
                                                       const GLchar* const* in_varyings_ptr_ptr,
                                                       const GLenum&        in_buffer_mode);
}

#endif /* VKGL_GL_TRANSFORM_FEEDBACK_VARYINGS_H */
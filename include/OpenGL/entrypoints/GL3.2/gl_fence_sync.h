/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FENCE_SYNC_H
#define VKGL_GL_FENCE_SYNC_H

#include "OpenGL/types.h"

VKGL_API GLsync VKGL_APIENTRY glFenceSync(GLenum     condition,
                                          GLbitfield flags);

GLsync vkglFenceSync_with_validation(VKGL::Context*    in_context_ptr,
                                     const GLenum&     in_condition,
                                     const GLbitfield& in_flags);

#endif /* VKGL_GL_FENCE_SYNC_H */
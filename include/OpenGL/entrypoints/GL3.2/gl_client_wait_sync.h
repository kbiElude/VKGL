/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLIENT_WAIT_SYNC_H
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#define VKGL_GL_CLIENT_WAIT_SYNC_H

#include "OpenGL/types.h"

VKGL_API GLenum VKGL_APIENTRY glClientWaitSync(GLsync     sync,
                                               GLbitfield flags,
                                               GLuint64   timeout);

GLenum vkglClientWaitSync_with_validation(VKGL::Context*    in_context_ptr,
                                          const GLsync&     in_sync,
                                          const GLbitfield& in_flags,
                                          const GLuint64&   in_timeout);

#endif /* VKGL_GL_CLIENT_WAIT_SYNC_H */
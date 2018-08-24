/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLIENT_WAIT_SYNC_H
#define VKGL_GL_CLIENT_WAIT_SYNC_H

#include "OpenGL/types.h"

GLenum VKGL_APIENTRY vkglClientWaitSync(GLsync     sync,
                                        GLbitfield flags,
                                        GLuint64   timeout);

#endif /* VKGL_GL_CLIENT_WAIT_SYNC_H */
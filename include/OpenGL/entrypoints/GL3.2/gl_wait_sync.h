/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_WAIT_SYNC_H
#define VKGL_GL_WAIT_SYNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglWaitSync(GLsync     sync,
                                         GLbitfield flags,
                                         GLuint64   timeout);

#endif /* VKGL_GL_WAIT_SYNC_H */
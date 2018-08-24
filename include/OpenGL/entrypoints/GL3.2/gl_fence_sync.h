/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FENCE_SYNC_H
#define VKGL_GL_FENCE_SYNC_H

#include "OpenGL/types.h"

GLsync VKGL_APIENTRY vkglFenceSync(GLenum     condition,
                                   GLbitfield flags);

#endif /* VKGL_GL_FENCE_SYNC_H */
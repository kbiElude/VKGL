#ifndef VKGL_GL_FENCE_SYNC_H
#define VKGL_GL_FENCE_SYNC_H

#include "OpenGL/types.h"

VKGL_API GLsync VKGL_APIENTRY glFenceSync(GLenum     condition,
                                          GLbitfield flags);

#endif /* VKGL_GL_FENCE_SYNC_H */
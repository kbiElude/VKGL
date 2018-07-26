#ifndef VKGL_GL_WAIT_SYNC_H
#define VKGL_GL_WAIT_SYNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glWaitSync(GLsync     sync,
                                       GLbitfield flags,
                                       GLuint64   timeout);

#endif /* VKGL_GL_WAIT_SYNC_H */
#ifndef VKGL_GL_CLIENT_WAIT_SYNC_H
#define VKGL_GL_CLIENT_WAIT_SYNC_H

#include "OpenGL/types.h"

VKGL_API GLenum VKGL_APIENTRY glClientWaitSync(GLsync     sync,
                                               GLbitfield flags,
                                               GLuint64   timeout);

#endif /* VKGL_GL_CLIENT_WAIT_SYNC_H */
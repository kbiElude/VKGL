/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_SYNC_H
#define VKGL_GL_DELETE_SYNC_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDeleteSync(GLsync sync);

    void vkglDeleteSync_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLsync&    in_sync);
}

#endif /* VKGL_GL_DELETE_SYNC_H */
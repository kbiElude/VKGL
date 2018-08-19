/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_SYNC_H
#define VKGL_GL_DELETE_SYNC_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDeleteSync(GLsync sync);

void vkglDeleteSync_with_validation(VKGL::Context* in_context_ptr,
                                    const GLsync&  in_sync);

#endif /* VKGL_GL_DELETE_SYNC_H */
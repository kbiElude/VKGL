/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_SYNC_H
#define VKGL_GL_IS_SYNC_H

#include "OpenGL/types.h"

GLboolean VKGL_APIENTRY vkglIsSync(GLsync sync);

GLboolean vkglIsSync_with_validation(VKGL::Context* in_context_ptr,
                                     const GLsync&  in_sync);

#endif /* VKGL_GL_IS_SYNC_H */
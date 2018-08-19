/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNMAP_BUFFER_H
#define VKGL_GL_UNMAP_BUFFER_H

#include "OpenGL/types.h"

VKGL_API GLboolean VKGL_APIENTRY glUnmapBuffer(GLenum target);

bool vkglUnmapBuffer_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_target);

#endif /* VKGL_GL_UNMAP_BUFFER_H */
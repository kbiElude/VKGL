/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MAP_BUFFER_H
#define VKGL_GL_MAP_BUFFER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void *VKGL_APIENTRY vkglMapBuffer(GLenum target,
                                      GLenum access);

    void* vkglMapBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLenum&    in_target,
                                        const GLenum&    in_access);
}

#endif /* VKGL_GL_MAP_BUFFER_H */
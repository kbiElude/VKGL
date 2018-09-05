/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_BUFFER_H
#define VKGL_GL_DRAW_BUFFER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDrawBuffer(GLenum buf);

    void vkglDrawBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLenum&    in_buf);
}

#endif /* VKGL_GL_DRAW_BUFFER_H */
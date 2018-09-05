/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_BUFFERS_H
#define VKGL_GL_DRAW_BUFFERS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDrawBuffers(GLsizei       n,
                                       const GLenum* bufs);

    void vkglDrawBuffers_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLsizei&   in_n,
                                         const GLenum*    in_bufs);
}

#endif /* VKGL_GL_DRAW_BUFFERS_H */
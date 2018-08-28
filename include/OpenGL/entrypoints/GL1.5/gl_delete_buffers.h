/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DELETE_BUFFERS_H
#define VKGL_GL_DELETE_BUFFERS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDeleteBuffers(GLsizei       n,
                                         const GLuint* buffers);

    void vkglDeleteBuffers_with_validation(VKGL::Context* in_context_ptr,
                                           const GLsizei& in_n,
                                           const GLuint*  in_buffers);
}

#endif /* VKGL_GL_DELETE_BUFFERS_H */
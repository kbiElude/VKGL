/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_BUFFER_H
#define VKGL_GL_TEX_BUFFER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglTexBuffer(GLenum target,
                                     GLenum internalformat,
                                     GLuint buffer);

    void vkglTexBuffer_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_target,
                                       const GLenum&  in_internalformat,
                                       const GLuint&  in_buffer);
}

#endif /* VKGL_GL_TEX_BUFFER_H */
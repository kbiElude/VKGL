/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_RENDERBUFFER_STORAGE_MULTISAMPLE_H
#define VKGL_GL_RENDERBUFFER_STORAGE_MULTISAMPLE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglRenderbufferStorageMultisample(GLenum  target,
                                                          GLsizei samples,
                                                          GLenum  internalformat,
                                                          GLsizei width,
                                                          GLsizei height);

    void vkglRenderbufferStorageMultisample_with_validation(OpenGL::Context* in_context_ptr,
                                                            const GLenum&    in_target,
                                                            const GLsizei&   in_samples,
                                                            const GLenum&    in_internalformat,
                                                            const GLsizei&   in_width,
                                                            const GLsizei&   in_height);
}

#endif /* VKGL_GL_RENDERBUFFER_STORAGE_MULTISAMPLE_H */
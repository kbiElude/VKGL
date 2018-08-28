/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_IMAGE_2D_MULTISAMPLE_H
#define VKGL_GL_TEX_IMAGE_2D_MULTISAMPLE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglTexImage2DMultisample(GLenum    target,
                                                 GLsizei   samples,
                                                 GLenum    internalformat,
                                                 GLsizei   width,
                                                 GLsizei   height,
                                                 GLboolean fixedsamplelocations);

    void vkglTexImage2DMultisample_with_validation(VKGL::Context*   in_context_ptr,
                                                   const GLenum&    in_target,
                                                   const GLsizei&   in_samples,
                                                   const GLenum&    in_internalformat,
                                                   const GLsizei&   in_width,
                                                   const GLsizei&   in_height,
                                                   const GLboolean& in_fixedsamplelocations);
}

#endif /* VKGL_GL_TEX_IMAGE_2D_MULTISAMPLE_H */
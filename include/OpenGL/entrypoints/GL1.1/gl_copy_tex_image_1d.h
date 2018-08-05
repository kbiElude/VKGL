/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_TEX_IMAGE_1D_H
#define VKGL_GL_COPY_TEX_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCopyTexImage1D(GLenum  target,
                                             GLint   level,
                                             GLenum  internalformat,
                                             GLint   x,
                                             GLint   y,
                                             GLsizei width,
                                             GLint   border);

void vkglCopyTexImage1D_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLint&   in_level,
                                        const GLenum&  in_internalformat,
                                        const GLint&   in_x,
                                        const GLint&   in_y,
                                        const GLsizei& in_width,
                                        const GLint&   in_border);

#endif /* VKGL_GL_COPY_TEX_IMAGE_1D_H */
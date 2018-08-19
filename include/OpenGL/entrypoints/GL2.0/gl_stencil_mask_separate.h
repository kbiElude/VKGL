/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_MASK_SEPARATE_H
#define VKGL_GL_STENCIL_MASK_SEPARATE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glStencilMaskSeparate(GLenum face,
                                                  GLuint mask);

void vkglStencilMaskSeparate_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_face,
                                             const GLuint&  in_mask);

#endif /* VKGL_GL_STENCIL_MASK_SEPARATE_H */
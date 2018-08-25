/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DEPTH_MASK_H
#define VKGL_GL_DEPTH_MASK_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglDepthMask(GLboolean flag);

void vkglDepthMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_flag);

#endif /* VKGL_GL_DEPTH_MASK_H */
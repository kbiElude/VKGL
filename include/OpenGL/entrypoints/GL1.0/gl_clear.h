/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_H
#define VKGL_GL_CLEAR_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glClear(GLbitfield mask);

void vkglClear_with_validation(VKGL::Context*    in_context_ptr,
                               const GLbitfield& in_mask);

#endif /* VKGL_GL_CLEAR_H */
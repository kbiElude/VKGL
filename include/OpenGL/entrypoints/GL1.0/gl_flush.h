/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FLUSH_H
#define VKGL_GL_FLUSH_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glFlush(void);

void vkglFlush_with_validation(VKGL::Context* in_context_ptr);

#endif /* VKGL_GL_FLUSH_H */
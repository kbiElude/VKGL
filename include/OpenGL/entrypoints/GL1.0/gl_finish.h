/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FINISH_H
#define VKGL_GL_FINISH_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglFinish(void);

void vkglFinish_with_validation(VKGL::Context* in_context_ptr);

#endif /* VKGL_GL_FINISH_H */
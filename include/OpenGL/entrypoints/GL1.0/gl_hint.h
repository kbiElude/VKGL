/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_HINT_H
#define VKGL_GL_HINT_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glHint(GLenum target,
                                   GLenum mode);

void vkglHint_with_validation(VKGL::Context* in_context_ptr,
                              const GLenum&  in_target,
                              const GLenum&  in_mode);

#endif /* VKGL_GL_HINT_H */
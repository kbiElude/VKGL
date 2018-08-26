/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BEGIN_CONDITIONAL_RENDER_H
#define VKGL_GL_BEGIN_CONDITIONAL_RENDER_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBeginConditionalRender(GLuint id,
                                              GLenum mode);

void vkglBeginConditionalRender_with_validation(VKGL::Context* in_context_ptr,
                                                const GLuint&  in_id,
                                                const GLenum&  in_mode);

#endif /* VKGL_GL_BEGIN_CONDITIONAL_RENDER_H */
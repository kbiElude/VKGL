/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_END_CONDITIONAL_RENDER_H
#define VKGL_GL_END_CONDITIONAL_RENDER_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglEndConditionalRender(void);

    void vkglEndConditionalRender_with_validation(OpenGL::Context* in_context_ptr);
}

#endif /* VKGL_GL_END_CONDITIONAL_RENDER_H */
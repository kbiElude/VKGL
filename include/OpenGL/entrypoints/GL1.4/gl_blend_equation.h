/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BLEND_EQUATION_H
#define VKGL_GL_BLEND_EQUATION_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBlendEquation(GLenum mode);

    void vkglBlendEquation_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_mode);
}

#endif /* VKGL_GL_BLEND_EQUATION_H */
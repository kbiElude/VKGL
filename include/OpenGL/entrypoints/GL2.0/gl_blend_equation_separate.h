/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BLEND_EQUATION_SEPARATE_H
#define VKGL_GL_BLEND_EQUATION_SEPARATE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBlendEquationSeparate(GLenum modeRGB,
                                                 GLenum modeAlpha);

    void vkglBlendEquationSeparate_with_validation(VKGL::Context* in_context_ptr,
                                                   const GLenum&  in_modeRGB,
                                                   const GLenum&  in_modeAlpha);
}

#endif /* VKGL_GL_BLEND_EQUATION_SEPARATE_H */
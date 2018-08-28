/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLAMP_COLOR_H
#define VKGL_GL_CLAMP_COLOR_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglClampColor(GLenum target,
                                      GLenum clamp);

    void vkglClampColor_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLenum&  in_clamp);
}

#endif /* VKGL_GL_CLAMP_COLOR_H */
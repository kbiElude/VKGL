/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COLOR_MASK_H
#define VKGL_GL_COLOR_MASK_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglColorMask(GLboolean red,
                                     GLboolean green,
                                     GLboolean blue,
                                     GLboolean alpha);

    void vkglColorMask_with_validation(OpenGL::Context* in_context_ptr,
                                       const GLboolean& in_red,
                                       const GLboolean& in_green,
                                       const GLboolean& in_blue,
                                       const GLboolean& in_alpha);
}

#endif /* VKGL_GL_COLOR_MASK_H */
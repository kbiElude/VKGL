/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_HINT_H
#define VKGL_GL_HINT_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglHint(GLenum target,
                                GLenum mode);

    void vkglHint_with_validation(OpenGL::Context* in_context_ptr,
                                  const GLenum&    in_target,
                                  const GLenum&    in_mode);
}

#endif /* VKGL_GL_HINT_H */
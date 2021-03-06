/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_H
#define VKGL_GL_CLEAR_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglClear(GLbitfield mask);

    void vkglClear_with_validation(OpenGL::Context*  in_context_ptr,
                                   const GLbitfield& in_mask);
}

#endif /* VKGL_GL_CLEAR_H */
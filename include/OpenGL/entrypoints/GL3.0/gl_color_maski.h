/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COLOR_MASKI_H
#define VKGL_GL_COLOR_MASKI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglColorMaski(GLuint    index,
                                      GLboolean r,
                                      GLboolean g,
                                      GLboolean b,
                                      GLboolean a);

    void vkglColorMaski_with_validation(VKGL::Context*   in_context_ptr,
                                        const GLuint&    in_index,
                                        const GLboolean& in_r,
                                        const GLboolean& in_g,
                                        const GLboolean& in_b,
                                        const GLboolean& in_a);
}

#endif /* VKGL_GL_COLOR_MASKI_H */
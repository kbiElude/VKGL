/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VIEWPORT_H
#define VKGL_GL_VIEWPORT_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglViewport(GLint   x,
                                    GLint   y,
                                    GLsizei width,
                                    GLsizei height);

    void vkglViewport_with_validation(OpenGL::Context* in_context_ptr,
                                      const GLint&     in_x,
                                      const GLint&     in_y,
                                      const GLsizei&   in_width,
                                      const GLsizei&   in_height);
}

#endif /* VKGL_GL_VIEWPORT_H */
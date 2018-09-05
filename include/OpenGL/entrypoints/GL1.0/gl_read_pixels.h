/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_READ_PIXELS_H
#define VKGL_GL_READ_PIXELS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglReadPixels(GLint   x,
                                      GLint   y,
                                      GLsizei width,
                                      GLsizei height,
                                      GLenum  format,
                                      GLenum  type,
                                      void*   pixels);

    void vkglReadPixels_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLint&     in_x,
                                        const GLint&     in_y,
                                        const GLsizei&   in_width,
                                        const GLsizei&   in_height,
                                        const GLenum&    in_format,
                                        const GLenum&    in_type,
                                        void*            out_pixels_ptr);
}

#endif /* VKGL_GL_READ_PIXELS_H */
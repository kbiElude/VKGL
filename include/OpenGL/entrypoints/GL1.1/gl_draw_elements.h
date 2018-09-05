/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_ELEMENTS_H
#define VKGL_GL_DRAW_ELEMENTS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDrawElements(GLenum      mode,
                                        GLsizei     count,
                                        GLenum      type,
                                        const void* indices);

    void vkglDrawElements_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_mode,
                                          const GLsizei&   in_count,
                                          const GLenum&    in_type,
                                          const void*      in_indices);
}

#endif /* VKGL_GL_DRAW_ELEMENTS_H */
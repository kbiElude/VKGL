/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_MULTI_DRAW_ARRAYS_H
#define VKGL_GL_MULTI_DRAW_ARRAYS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglMultiDrawArrays(GLenum         mode,
                                           const GLint*   first,
                                           const GLsizei* count,
                                           GLsizei        drawcount);

    void vkglMultiDrawArrays_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_mode,
                                             const GLint*     in_first_ptr,
                                             const GLsizei*   in_count_ptr,
                                             const GLsizei&   in_drawcount);
}

#endif /* VKGL_GL_MULTI_DRAW_ARRAYS_H */
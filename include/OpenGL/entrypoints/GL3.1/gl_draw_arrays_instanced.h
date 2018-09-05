/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_ARRAYS_INSTANCED_H
#define VKGL_GL_DRAW_ARRAYS_INSTANCED_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDrawArraysInstanced(GLenum  mode,
                                               GLint   first,
                                               GLsizei count,
                                               GLsizei instancecount);

    void vkglDrawArraysInstanced_with_validation(OpenGL::Context* in_context_ptr,
                                                 const GLenum&    in_mode,
                                                 const GLint&     in_first,
                                                 const GLsizei&   in_count,
                                                 const GLsizei&   in_instancecount);
}

#endif /* VKGL_GL_DRAW_ARRAYS_INSTANCED_H */
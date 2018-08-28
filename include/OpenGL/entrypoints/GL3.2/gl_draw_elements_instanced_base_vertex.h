/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_ELEMENTS_INSTANCED_BASE_VERTEX_H
#define VKGL_GL_DRAW_ELEMENTS_INSTANCED_BASE_VERTEX_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDrawElementsInstancedBaseVertex(GLenum      mode,
                                                           GLsizei     count,
                                                           GLenum      type,
                                                           const void* indices,
                                                           GLsizei     instancecount,
                                                           GLint       basevertex);

    void vkglDrawElementsInstancedBaseVertex_with_validation(VKGL::Context* in_context_ptr,
                                                             const GLenum&  in_mode,
                                                             const GLsizei& in_count,
                                                             const GLenum&  in_type,
                                                             const void*    in_indices_ptr,
                                                             const GLsizei& in_instancecount,
                                                             const GLint&   in_basevertex);
}

#endif /* VKGL_GL_DRAW_ELEMENTS_INSTANCED_BASE_VERTEX_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_PROVOKING_VERTEX_H
#define VKGL_GL_PROVOKING_VERTEX_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglProvokingVertex(GLenum mode);

    void vkglProvokingVertex_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_mode);
}

#endif /* VKGL_GL_PROVOKING_VERTEX_H */
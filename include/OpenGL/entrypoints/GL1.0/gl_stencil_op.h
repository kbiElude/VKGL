/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STENCIL_OP_H
#define VKGL_GL_STENCIL_OP_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglStencilOp(GLenum fail,
                                     GLenum zfail,
                                     GLenum zpass);

    void vkglStencilOp_with_validation(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_fail,
                                       const GLenum&    in_zfail,
                                       const GLenum&    in_zpass);
}

#endif /* VKGL_GL_STENCIL_OP_H */
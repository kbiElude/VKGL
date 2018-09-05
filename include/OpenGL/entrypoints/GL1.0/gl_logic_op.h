/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_LOGIC_OP_H
#define VKGL_GL_LOGIC_OP_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglLogicOp(GLenum opcode);

    void vkglLogicOp_with_validation(OpenGL::Context* in_context_ptr,
                                     const GLenum&    in_opcode);
}

#endif /* VKGL_GL_LOGIC_OP_H */
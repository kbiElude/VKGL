#ifndef VKGL_GL_LOGIC_OP_H
#define VKGL_GL_LOGIC_OP_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glLogicOp(GLenum opcode);

void vkglLogicOp_with_validation(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_opcode);

#endif /* VKGL_GL_LOGIC_OP_H */
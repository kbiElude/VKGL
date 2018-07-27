#include "OpenGL/entrypoints/GL1.0/gl_logic_op.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_opcode)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glLogicOp(GLenum opcode)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLLogicOp(dispatch_table_ptr->bound_context_ptr,
                                   opcode);
}

void vkglLogicOp_with_validation(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_opcode)
{
    todo;
}
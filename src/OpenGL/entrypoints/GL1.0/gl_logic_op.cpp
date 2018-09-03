/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_logic_op.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_opcode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglLogicOp(GLenum opcode)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLLogicOp(dispatch_table_ptr->bound_context_ptr,
                                   opcode);
}

static void vkglLogicOp_execute(OpenGL::Context* in_context_ptr,
                                const GLenum&    in_opcode)
{
    const auto opcode_vkgl = OpenGL::Utils::get_logic_op_mode_for_gl_enum(in_opcode);

    in_context_ptr->set_logic_op(opcode_vkgl);
}

void OpenGL::vkglLogicOp_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_opcode)
{
    if (validate(in_context_ptr,
                 in_opcode) )
    {
        vkglLogicOp_execute(in_context_ptr,
                            in_opcode);
    }
}
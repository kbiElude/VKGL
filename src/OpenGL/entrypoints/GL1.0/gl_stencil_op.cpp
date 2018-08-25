/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_stencil_op.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_fail,
                     const GLenum&  in_zfail,
                     const GLenum&  in_zpass)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglStencilOp(GLenum fail,
                                 GLenum zfail,
                                 GLenum zpass)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilOp(dispatch_table_ptr->bound_context_ptr,
                                     fail,
                                     zfail,
                                     zpass);
}

void vkglStencilOp_execute(VKGL::Context* in_context_ptr,
                           const GLenum&  in_fail,
                           const GLenum&  in_zfail,
                           const GLenum&  in_zpass)
{
    const auto fail_vkgl  = VKGL::Utils::get_stencil_operation_for_gl_enum(in_fail);
    const auto zfail_vkgl = VKGL::Utils::get_stencil_operation_for_gl_enum(in_zfail);
    const auto zpass_vkgl = VKGL::Utils::get_stencil_operation_for_gl_enum(in_zpass);

    in_context_ptr->set_stencil_operations(fail_vkgl,
                                           zfail_vkgl,
                                           zpass_vkgl);
}

void vkglStencilOp_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_fail,
                                   const GLenum&  in_zfail,
                                   const GLenum&  in_zpass)
{
    if (validate(in_context_ptr,
                 in_fail,
                 in_zfail,
                 in_zpass) )
    {
        vkglStencilOp_execute(in_context_ptr,
                              in_fail,
                              in_zfail,
                              in_zpass);
    }
}
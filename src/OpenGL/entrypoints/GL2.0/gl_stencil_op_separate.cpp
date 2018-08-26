/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_stencil_op_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_face,
                     const GLenum&  in_sfail,
                     const GLenum&  in_dpfail,
                     const GLenum&  in_dppass)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglStencilOpSeparate(GLenum face,
                                         GLenum sfail,
                                         GLenum dpfail,
                                         GLenum dppass)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilOpSeparate(dispatch_table_ptr->bound_context_ptr,
                                             face,
                                             sfail,
                                             dpfail,
                                             dppass);
}

void vkglStencilOpSeparate_execute(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_face,
                                   const GLenum&  in_sfail,
                                   const GLenum&  in_dpfail,
                                   const GLenum&  in_dppass)
{
    const auto dpfail_vkgl = VKGL::Utils::get_stencil_operation_for_gl_enum (in_dpfail);
    const auto dppass_vkgl = VKGL::Utils::get_stencil_operation_for_gl_enum (in_dppass);
    const auto face_vkgl   = VKGL::Utils::get_stencil_state_face_for_gl_enum(in_face);
    const auto sfail_vkgl  = VKGL::Utils::get_stencil_operation_for_gl_enum (in_sfail);

    in_context_ptr->set_stencil_operations_separate(face_vkgl,
                                                    sfail_vkgl,
                                                    dpfail_vkgl,
                                                    dppass_vkgl);
}

void vkglStencilOpSeparate_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_face,
                                           const GLenum&  in_sfail,
                                           const GLenum&  in_dpfail,
                                           const GLenum&  in_dppass)
{
    if (validate(in_context_ptr,
                 in_face,
                 in_sfail,
                 in_dpfail,
                 in_dppass) )
    {
        vkglStencilOpSeparate_execute(in_context_ptr,
                                      in_face,
                                      in_sfail,
                                      in_dpfail,
                                      in_dppass);
    }
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_framebuffer_attachment_parameteriv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_attachment,
                     const GLenum&    in_pname,
                     GLint*           out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetFramebufferAttachmentParameteriv(GLenum target,
                                                                   GLenum attachment,
                                                                   GLenum pname,
                                                                   GLint* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetFramebufferAttachmentParameteriv(dispatch_table_ptr->bound_context_ptr,
                                                               target,
                                                               attachment,
                                                               pname,
                                                               params);
}

static void vkglGetFramebufferAttachmentParameteriv_execute(OpenGL::Context* in_context_ptr,
                                                            const GLenum&    in_target,
                                                            const GLenum&    in_attachment,
                                                            const GLenum&    in_pname,
                                                            GLint*           out_params_ptr)
{
    const auto attachment_vkgl = OpenGL::Utils::get_framebuffer_attachment_point_for_gl_enum   (in_attachment);
    const auto pname_vkgl      = OpenGL::Utils::get_framebuffer_attachment_property_for_gl_enum(in_pname);
    const auto target_vkgl     = OpenGL::Utils::get_framebuffer_target_for_gl_enum             (in_target);

    in_context_ptr->get_framebuffer_attachment_property(target_vkgl,
                                                        attachment_vkgl,
                                                        pname_vkgl,
                                                        OpenGL::GetSetArgumentType::Int,
                                                        out_params_ptr);

}

void OpenGL::vkglGetFramebufferAttachmentParameteriv_with_validation(OpenGL::Context* in_context_ptr,
                                                                     const GLenum&    in_target,
                                                                     const GLenum&    in_attachment,
                                                                     const GLenum&    in_pname,
                                                                     GLint*           out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_attachment,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetFramebufferAttachmentParameteriv_execute(in_context_ptr,
                                                        in_target,
                                                        in_attachment,
                                                        in_pname,
                                                        out_params_ptr);
    }
}

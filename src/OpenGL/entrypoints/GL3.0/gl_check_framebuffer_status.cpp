/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_check_framebuffer_status.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLenum VKGL_APIENTRY vkglCheckFramebufferStatus(GLenum target)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;
    const auto  result             = dispatch_table_ptr->pGLCheckFramebufferStatus(dispatch_table_ptr->bound_context_ptr,
                                                                                   target);

    return result;
}

VKGL::FramebufferStatus vkglCheckFramebufferStatus_execute(VKGL::Context* in_context_ptr,
                                                           const GLenum&  in_target)
{
    const auto target_vkgl = VKGL::Utils::get_framebuffer_target_for_gl_enum(in_target);

    return in_context_ptr->check_framebuffer_status(target_vkgl);
}

GLenum vkglCheckFramebufferStatus_with_validation(VKGL::Context* in_context_ptr,
                                                  const GLenum&  in_target)
{
    VKGL::FramebufferStatus result = VKGL::FramebufferStatus::Unknown;

    if (validate(in_context_ptr,
                 in_target) )
    {
        result = vkglCheckFramebufferStatus_execute(in_context_ptr,
                                                    in_target);
    }

    return VKGL::Utils::get_gl_enum_for_framebuffer_status(result);
}

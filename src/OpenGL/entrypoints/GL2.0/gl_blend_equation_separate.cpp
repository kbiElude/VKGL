/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_blend_equation_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_modeRGB,
                     const GLenum&  in_modeAlpha)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglBlendEquationSeparate(GLenum modeRGB,
                                                      GLenum modeAlpha)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBlendEquationSeparate(dispatch_table_ptr->bound_context_ptr,
                                                 modeRGB,
                                                 modeAlpha);
}

void vkglBlendEquationSeparate_execute(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_modeRGB,
                                       const GLenum&  in_modeAlpha)
{
    const auto mode_alpha_vkgl = VKGL::Utils::get_blend_equation_for_gl_enum(in_modeAlpha);
    const auto mode_rgb_vkgl   = VKGL::Utils::get_blend_equation_for_gl_enum(in_modeRGB);

    in_context_ptr->set_blend_equation_separate(mode_rgb_vkgl,
                                                mode_alpha_vkgl);
}

void vkglBlendEquationSeparate_with_validation(VKGL::Context* in_context_ptr,
                                               const GLenum&  in_modeRGB,
                                               const GLenum&  in_modeAlpha)
{
    if (validate(in_context_ptr,
                 in_modeRGB,
                 in_modeAlpha) )
    {
        vkglBlendEquationSeparate_execute(in_context_ptr,
                                          in_modeRGB,
                                          in_modeAlpha);
    }
}

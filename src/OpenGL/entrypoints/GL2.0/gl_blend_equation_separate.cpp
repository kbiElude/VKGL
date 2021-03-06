/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_blend_equation_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_modeRGB,
                     const GLenum&    in_modeAlpha)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBlendEquationSeparate(GLenum modeRGB,
                                                     GLenum modeAlpha)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBlendEquationSeparate(modeRGB=[%s] modeAlpha=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(modeRGB),
               OpenGL::Utils::get_raw_string_for_gl_enum(modeAlpha) );

    dispatch_table_ptr->pGLBlendEquationSeparate(dispatch_table_ptr->bound_context_ptr,
                                                 modeRGB,
                                                 modeAlpha);
}

static void vkglBlendEquationSeparate_execute(OpenGL::Context* in_context_ptr,
                                              const GLenum&    in_modeRGB,
                                              const GLenum&    in_modeAlpha)
{
    const auto mode_alpha_vkgl = OpenGL::Utils::get_blend_equation_for_gl_enum(in_modeAlpha);
    const auto mode_rgb_vkgl   = OpenGL::Utils::get_blend_equation_for_gl_enum(in_modeRGB);

    in_context_ptr->set_blend_equation_separate(mode_rgb_vkgl,
                                                mode_alpha_vkgl);
}

void OpenGL::vkglBlendEquationSeparate_with_validation(OpenGL::Context* in_context_ptr,
                                                       const GLenum&    in_modeRGB,
                                                       const GLenum&    in_modeAlpha)
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

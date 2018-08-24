/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
 /* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_blend_func_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_sfactorRGB,
                     const GLenum&  in_dfactorRGB,
                     const GLenum&  in_sfactorAlpha,
                     const GLenum&  in_dfactorAlpha)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglBlendFuncSeparate(GLenum sfactorRGB,
                                                  GLenum dfactorRGB,
                                                  GLenum sfactorAlpha,
                                                  GLenum dfactorAlpha)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBlendFuncSeparate(dispatch_table_ptr->bound_context_ptr,
                                             sfactorRGB,
                                             dfactorRGB,
                                             sfactorAlpha,
                                             dfactorAlpha);
}

void vkglBlendFuncSeparate_execute(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_sfactorRGB,
                                   const GLenum&  in_dfactorRGB,
                                   const GLenum&  in_sfactorAlpha,
                                   const GLenum&  in_dfactorAlpha)
{
    const auto dfactor_alpha_vkgl = VKGL::Utils::get_blend_function_for_gl_enum(in_dfactorAlpha);
    const auto dfactor_rgb_vkgl   = VKGL::Utils::get_blend_function_for_gl_enum(in_dfactorRGB);
    const auto sfactor_alpha_vkgl = VKGL::Utils::get_blend_function_for_gl_enum(in_sfactorAlpha);
    const auto sfactor_rgb_vkgl   = VKGL::Utils::get_blend_function_for_gl_enum(in_sfactorRGB);

    in_context_ptr->set_blend_functions_separate(sfactor_rgb_vkgl,
                                                 dfactor_rgb_vkgl,
                                                 sfactor_alpha_vkgl,
                                                 dfactor_alpha_vkgl);
}

void vkglBlendFuncSeparate_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_sfactorRGB,
                                           const GLenum&  in_dfactorRGB,
                                           const GLenum&  in_sfactorAlpha,
                                           const GLenum&  in_dfactorAlpha)
{
    if (validate(in_context_ptr,
                 in_sfactorRGB,
                 in_dfactorRGB,
                 in_sfactorAlpha,
                 in_dfactorAlpha) )
    {
        vkglBlendFuncSeparate_execute(in_context_ptr,
                                      in_sfactorRGB,
                                      in_dfactorRGB,
                                      in_sfactorAlpha,
                                      in_dfactorAlpha);
    }
}


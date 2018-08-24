/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_generate_mipmap.h"
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

VKGL_API void VKGL_APIENTRY vkglGenerateMipmap(GLenum target)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenerateMipmap(dispatch_table_ptr->bound_context_ptr,
                                          target);
}

void vkglGenerateMipmap_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_target)
{
    const auto target_vkgl = VKGL::Utils::get_mipmap_generation_texture_target_for_gl_enum(in_target);

    in_context_ptr->generate_mipmap(target_vkgl);
}

void vkglGenerateMipmap_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target)
{
    if (validate(in_context_ptr,
                 in_target) )
    {
        vkglGenerateMipmap_execute(in_context_ptr,
                                   in_target);
    }
}

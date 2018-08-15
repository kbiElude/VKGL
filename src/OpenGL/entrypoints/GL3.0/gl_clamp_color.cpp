/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_clamp_color.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_clamp)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glClampColor(GLenum target,
                                         GLenum clamp)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClampColor(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      clamp);
}

void vkglClampColor_execute(VKGL::Context* in_context_ptr,
                            const GLenum&  in_target,
                            const GLenum&  in_clamp)
{
    vkgl_assert(in_target == GL_CLAMP_READ_COLOR);

    in_context_ptr->set_clamp_color( (in_clamp == GL_TRUE) ? true : false);
}

void vkglClampColor_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLenum&  in_clamp)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_clamp) )
    {
        vkglClampColor_execute(in_context_ptr,
                               in_target,
                               in_clamp);
    }
}

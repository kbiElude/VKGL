/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_clamp_color.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_clamp)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglClampColor(GLenum target,
                                          GLenum clamp)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glClampColor(target=[%s] clamp=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(clamp) );

    dispatch_table_ptr->pGLClampColor(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      clamp);
}

static void vkglClampColor_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_target,
                                   const GLenum&    in_clamp)
{
    vkgl_assert(in_target == GL_CLAMP_READ_COLOR);

    in_context_ptr->set_clamp_color( (in_clamp == GL_TRUE) ? true : false);
}

void OpenGL::vkglClampColor_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_target,
                                            const GLenum&    in_clamp)
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

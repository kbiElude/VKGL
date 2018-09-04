/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_blend_equation.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBlendEquation(GLenum mode)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBlendEquation(mode=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(mode) );

    dispatch_table_ptr->pGLBlendEquation(dispatch_table_ptr->bound_context_ptr,
                                         mode);
}

static void vkglBlendEquation_execute(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_mode)
{
    const auto mode_vkgl = OpenGL::Utils::get_blend_equation_for_gl_enum(in_mode);

    in_context_ptr->set_blend_equation(mode_vkgl);
}

void OpenGL::vkglBlendEquation_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_mode)
{
    if (validate(in_context_ptr,
                 in_mode) )
    {
        vkglBlendEquation_execute(in_context_ptr,
                                  in_mode);
    }
}
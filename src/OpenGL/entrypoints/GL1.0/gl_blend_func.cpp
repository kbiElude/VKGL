/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_blend_func.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_sfactor,
                     const GLenum&    in_dfactor)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBlendFunc(GLenum sfactor,
                                         GLenum dfactor)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBlendFunc(sfactor=[%s] dfactor=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(sfactor),
               OpenGL::Utils::get_raw_string_for_gl_enum(dfactor) );

    dispatch_table_ptr->pGLBlendFunc(dispatch_table_ptr->bound_context_ptr,
                                     sfactor,
                                     dfactor);
}

static void vkglBlendFunc_execute(OpenGL::Context* in_context_ptr,
                                  const GLenum&    in_sfactor,
                                  const GLenum&    in_dfactor)
{
    const auto sfactor_vkgl = OpenGL::Utils::get_blend_function_for_gl_enum(in_sfactor);
    const auto dfactor_vkgl = OpenGL::Utils::get_blend_function_for_gl_enum(in_dfactor);

    in_context_ptr->set_blend_functions(sfactor_vkgl,
                                        dfactor_vkgl);
}

void OpenGL::vkglBlendFunc_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_sfactor,
                                           const GLenum&    in_dfactor)
{
    if (validate(in_context_ptr,
                 in_sfactor,
                 in_dfactor) )
    {
        vkglBlendFunc_execute(in_context_ptr,
                              in_sfactor,
                              in_dfactor);
    }
}
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_depth_func.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_func)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglDepthFunc(GLenum func)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDepthFunc(func=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(func) );

    dispatch_table_ptr->pGLDepthFunc(dispatch_table_ptr->bound_context_ptr,
                                     func);
}

static void vkglDepthFunc_execute(OpenGL::Context* in_context_ptr,
                                  const GLenum&    in_func)
{
    const auto depth_func_vkgl = OpenGL::Utils::get_depth_function_for_gl_enum(in_func);

    in_context_ptr->set_depth_function(depth_func_vkgl);
}

void OpenGL::vkglDepthFunc_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_func)
{
    if (validate(in_context_ptr,
                 in_func) )
    {
        vkglDepthFunc_execute(in_context_ptr,
                              in_func);
    }
}
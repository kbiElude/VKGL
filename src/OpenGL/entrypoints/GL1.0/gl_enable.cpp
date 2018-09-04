/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_enable.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_cap)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglEnable(GLenum cap)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glEnable(cap=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(cap) );

    dispatch_table_ptr->pGLEnable(dispatch_table_ptr->bound_context_ptr,
                                  cap);
}

static void vkglEnable_execute(OpenGL::Context* in_context_ptr,
                               const GLenum&    in_cap)
{
    const auto mode_vkgl = OpenGL::Utils::get_nonindexed_capability_for_gl_enum(in_cap);

    in_context_ptr->enable(mode_vkgl);
}

void OpenGL::vkglEnable_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLenum&    in_cap)
{
    if (validate(in_context_ptr,
                 in_cap) )
    {
        vkglEnable_execute(in_context_ptr,
                           in_cap);
    }
}
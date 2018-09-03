/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_end_conditional_render.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglEndConditionalRender(void)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEndConditionalRender(dispatch_table_ptr->bound_context_ptr);
}


static void vkglEndConditionalRender_execute(OpenGL::Context* in_context_ptr)
{
    in_context_ptr->end_conditional_render();
}

void OpenGL::vkglEndConditionalRender_with_validation(OpenGL::Context* in_context_ptr)
{
    if (validate(in_context_ptr) )
    {
        vkglEndConditionalRender_execute(in_context_ptr);
    }
}

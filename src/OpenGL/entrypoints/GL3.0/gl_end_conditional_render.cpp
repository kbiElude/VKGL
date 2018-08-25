/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_end_conditional_render.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglEndConditionalRender(void)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEndConditionalRender(dispatch_table_ptr->bound_context_ptr);
}


void vkglEndConditionalRender_execute(VKGL::Context* in_context_ptr)
{
    in_context_ptr->end_conditional_render();
}

void vkglEndConditionalRender_with_validation(VKGL::Context* in_context_ptr)
{
    if (validate(in_context_ptr) )
    {
        vkglEndConditionalRender_execute(in_context_ptr);
    }
}

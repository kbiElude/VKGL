/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_end_transform_feedback.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglEndTransformFeedback(void)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEndTransformFeedback(dispatch_table_ptr->bound_context_ptr);
}


void vkglEndTransformFeedback_execute(VKGL::Context* in_context_ptr)
{
    in_context_ptr->end_transform_feedback();
}

void vkglEndTransformFeedback_with_validation(VKGL::Context* in_context_ptr)
{
    if (validate(in_context_ptr) )
    {
        vkglEndTransformFeedback_execute(in_context_ptr);
    }
}

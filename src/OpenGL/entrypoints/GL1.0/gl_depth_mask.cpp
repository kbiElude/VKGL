/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_depth_mask.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*   in_context_ptr,
                     const GLboolean& in_flag)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglDepthMask(GLboolean flag)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDepthMask(dispatch_table_ptr->bound_context_ptr,
                                     flag);
}

void vkglDepthMask_execute(VKGL::Context*   in_context_ptr,
                           const GLboolean& in_flag)
{
    in_context_ptr->set_depth_mask( (in_flag == GL_TRUE) );
}

void vkglDepthMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_flag)
{
    if (validate(in_context_ptr,
                 in_flag) )
    {
        vkglDepthMask_execute(in_context_ptr,
                              in_flag);
    }
}

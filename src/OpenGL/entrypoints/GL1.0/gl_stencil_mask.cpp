/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_stencil_mask.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glStencilMask(GLuint mask)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilMask(dispatch_table_ptr->bound_context_ptr,
                                       mask);
}

void vkglStencilMask_execute(VKGL::Context* in_context_ptr,
                             const GLuint&  in_mask)
{
    in_context_ptr->set_stencil_mask(in_mask);
}

void vkglStencilMask_with_validation(VKGL::Context* in_context_ptr,
                                     const GLuint&  in_mask)
{
    if (validate(in_context_ptr,
                 in_mask) )
    {
        vkglStencilMask_execute(in_context_ptr,
                                in_mask);
    }
}
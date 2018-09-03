/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_stencil_mask.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglStencilMask(GLuint mask)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilMask(dispatch_table_ptr->bound_context_ptr,
                                       mask);
}

static void vkglStencilMask_execute(OpenGL::Context* in_context_ptr,
                                    const GLuint&    in_mask)
{
    in_context_ptr->set_stencil_mask(in_mask);
}

void OpenGL::vkglStencilMask_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLuint&    in_mask)
{
    if (validate(in_context_ptr,
                 in_mask) )
    {
        vkglStencilMask_execute(in_context_ptr,
                                in_mask);
    }
}
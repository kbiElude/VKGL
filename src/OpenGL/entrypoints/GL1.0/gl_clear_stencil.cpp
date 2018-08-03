/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_clear_stencil.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_s)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glClearStencil(GLint s)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClearStencil(dispatch_table_ptr->bound_context_ptr,
                                        s);
}

void vkglClearStencil_execute(VKGL::Context* in_context_ptr,
                              const GLint&   in_s)
{
    in_context_ptr->set_clear_stencil_value(in_s);
}

void vkglClearStencil_with_validation(VKGL::Context* in_context_ptr,
                                      const GLint&   in_s)
{
    if (validate(in_context_ptr,
                 in_s) )
    {
        vkglClearStencil_execute(in_context_ptr,
                                 in_s);
    }
}
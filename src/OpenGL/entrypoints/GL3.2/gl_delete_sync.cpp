/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_delete_sync.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsync&  in_sync)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglDeleteSync(GLsync sync)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDeleteSync(dispatch_table_ptr->bound_context_ptr,
                                      sync);
}

void vkglDeleteSync_execute(VKGL::Context* in_context_ptr,
                            const GLsync&  in_sync)
{
    in_context_ptr->delete_sync(in_sync);
}

void vkglDeleteSync_with_validation(VKGL::Context* in_context_ptr,
                                    const GLsync&  in_sync)
{
    if (validate(in_context_ptr,
                 in_sync) )
    {
        vkglDeleteSync_execute(in_context_ptr,
                               in_sync);
    }
}

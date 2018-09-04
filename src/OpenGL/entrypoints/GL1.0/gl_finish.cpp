/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_finish.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

void VKGL_APIENTRY OpenGL::vkglFinish(void)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glFinish()");

    dispatch_table_ptr->pGLFinish(dispatch_table_ptr->bound_context_ptr);
}

void OpenGL::vkglFinish_with_validation(OpenGL::Context* in_context_ptr)
{
    in_context_ptr->finish();
}
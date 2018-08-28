/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_flush.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

void VKGL_APIENTRY OpenGL::vkglFlush(void)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFlush(dispatch_table_ptr->bound_context_ptr);
}

void OpenGL::vkglFlush_with_validation(VKGL::Context* in_context_ptr)
{
    in_context_ptr->flush();
}
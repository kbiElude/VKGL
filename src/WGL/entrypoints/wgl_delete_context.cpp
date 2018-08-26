/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_delete_context.h"

BOOL WINAPI WGL::delete_context(HGLRC in_hglrc)
{
    VKGL_TRACE("wglDeleteContext(in_hglrc=[%p])",
               in_hglrc);

    return reinterpret_cast<WGL::PFNWGLDELETECONTEXTPROC>(WGL::g_cached_delete_context_func_ptr)(in_hglrc);
}

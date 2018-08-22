/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_delete_context.h"

BOOL WINAPI vkgl_wgl_delete_context(HGLRC in_hglrc)
{
    MessageBox(HWND_DESKTOP,
               "wglDeleteContext() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLDELETECONTEXTPROC>(g_cached_wgl_delete_context_func_ptr)(in_hglrc);
}

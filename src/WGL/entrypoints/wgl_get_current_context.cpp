/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_get_current_context.h"

HGLRC WINAPI vkgl_wgl_get_current_context()
{
    MessageBox(HWND_DESKTOP,
               "wglGetCurrentContext() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLGETCURRENTCONTEXTPROC>(g_cached_wgl_get_current_context_func_ptr)();
}

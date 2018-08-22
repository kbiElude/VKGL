/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_get_current_dc.h"

HDC WINAPI vkgl_wgl_get_current_dc()
{
    MessageBox(HWND_DESKTOP,
               "wglGetCurrentDc() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLGETCURRENTDCPROC>(g_cached_wgl_get_current_dc_func_ptr)();
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_get_proc_address.h"

PROC WINAPI vkgl_wgl_get_proc_address(LPCSTR in_name)
{
    MessageBox(HWND_DESKTOP,
               "wglGetProcAddress() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLGETPROCADDRESSPROC>(g_cached_wgl_get_proc_address_func_ptr)(in_name);
}

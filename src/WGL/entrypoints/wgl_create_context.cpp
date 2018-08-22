/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_create_context.h"

HGLRC WINAPI vkgl_wgl_create_context(HDC in_hdc)
{
    MessageBox(HWND_DESKTOP,
               "wglCreateContext() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLCREATECONTEXTPROC>(g_cached_wgl_create_context_func_ptr)(in_hdc);
}

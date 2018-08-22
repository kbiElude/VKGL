/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_make_current.h"

BOOL WINAPI vkgl_wgl_make_current(HDC   in_hdc,
                                  HGLRC in_hglrc)
{
    MessageBox(HWND_DESKTOP,
               "wglMakeCurrent() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLMAKECURRENTPROC>(g_cached_wgl_make_current_func_ptr)(in_hdc,
                                                                                       in_hglrc);
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "GDI32/entrypoints/get_pixel_format.h"
#include "GDI32/dll.h"

typedef int (WINAPI *PFNGETPIXELFORMATPROC)(HDC);

int WINAPI vkgl_get_pixel_format(HDC in_hdc)
{
    auto func_ptr = reinterpret_cast<PFNGETPIXELFORMATPROC>(g_cached_get_pixel_format_func_ptr);

    MessageBox(HWND_DESKTOP,
               "GetPixelFormat() intercepted.",
               "",
               MB_OK);

    return func_ptr(in_hdc);
}
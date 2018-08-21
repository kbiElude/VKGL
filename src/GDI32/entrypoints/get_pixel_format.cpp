/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "GDI32/entrypoints/get_pixel_format.h"
#include "GDI32/globals.h"


int WINAPI vkgl_get_pixel_format(HDC in_hdc)
{
    MessageBox(HWND_DESKTOP,
               "GetPixelFormat() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNGETPIXELFORMATPROC>(g_cached_get_pixel_format_func_ptr)(in_hdc);
}
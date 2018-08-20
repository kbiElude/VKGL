/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "GDI32/entrypoints/set_pixel_format.h"
#include "GDI32/dll.h"

typedef BOOL (WINAPI* PFNSETPIXELFORMATPROC)(HDC, int, const PIXELFORMATDESCRIPTOR*);


BOOL WINAPI vkgl_set_pixel_format(HDC                          in_hdc,
                                  int                          in_format,
                                  CONST PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr)
{
    auto func_ptr = reinterpret_cast<PFNSETPIXELFORMATPROC>(g_cached_set_pixel_format_func_ptr);

    MessageBox(HWND_DESKTOP,
               "SetPixelFormat() intercepted.",
               "",
               MB_OK);

    return func_ptr(in_hdc,
                    in_format,
                    in_pixel_format_descriptor_ptr);
}
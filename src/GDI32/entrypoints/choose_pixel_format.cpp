/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "Common/globals.h"
#include "GDI32/globals.h"
#include "GDI32/entrypoints/choose_pixel_format.h"

int WINAPI vkgl_choose_pixel_format(HDC                          in_hdc,
                                    CONST PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr)
{
    MessageBox(HWND_DESKTOP,
               "ChoosePixelFormat() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNCHOOSEPIXELFORMATPROC>(g_cached_choose_pixel_format_func_ptr)(in_hdc,
                                                                                             in_pixel_format_descriptor_ptr);
}

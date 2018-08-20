/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "GDI32/entrypoints/choose_pixel_format.h"
#include "GDI32/dll.h"

typedef int (WINAPI *PFNCHOOSEPIXELFORMATPROCFUNC)(HDC, const PIXELFORMATDESCRIPTOR*);

int WINAPI vkgl_choose_pixel_format(HDC                          in_hdc,
                                    CONST PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr)
{
    auto func_ptr = reinterpret_cast<PFNCHOOSEPIXELFORMATPROCFUNC>(g_cached_choose_pixel_format_func_ptr);

    MessageBox(HWND_DESKTOP,
               "ChoosePixelFormat() intercepted.",
               "",
               MB_OK);

    return func_ptr(in_hdc,
                    in_pixel_format_descriptor_ptr);
}
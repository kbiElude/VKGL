/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "GDI32/entrypoints/get_pixel_format.h"
#include "GDI32/globals.h"


int WINAPI GDI32::get_pixel_format(HDC in_hdc)
{
    VKGL_TRACE("GetPixelFormat(in_hdc=[%p])",
               in_hdc);

    return reinterpret_cast<GDI32::PFNGETPIXELFORMATPROC>(GDI32::g_cached_get_pixel_format_func_ptr)(in_hdc);
}
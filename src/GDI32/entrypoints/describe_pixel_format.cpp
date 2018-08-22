/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "GDI32/globals.h"
#include "GDI32/entrypoints/describe_pixel_format.h"

int WINAPI vkgl_describe_pixel_format(HDC                     in_hdc,
                                      int                     in_n_pixel_format,
                                      UINT                    in_n_bytes,
                                      LPPIXELFORMATDESCRIPTOR in_pixel_format_descriptor_ptr)
{
    //MessageBox(HWND_DESKTOP,
    //           "DescribePixelFormat() intercepted.",
    //           "",
    //           MB_OK);

    return reinterpret_cast<PFNDESCRIBEPIXELFORMATPROC>(g_cached_describe_pixel_format_func_ptr)(in_hdc,
                                                                                                 in_n_pixel_format,
                                                                                                 in_n_bytes,
                                                                                                 in_pixel_format_descriptor_ptr);
}
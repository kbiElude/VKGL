/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "Common/macros.h"
#include "GDI32/entrypoints/set_pixel_format.h"
#include "GDI32/globals.h"
#include "GDI32/utils_trace.h"

BOOL WINAPI GDI32::set_pixel_format(HDC                          in_hdc,
                                    int                          in_format,
                                    CONST PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr)
{
    VKGL_TRACE("SetPixelFormat(\n"
               " in_hdc=[%p]\n"
               " in_format=[%d]\n"
               " in_pixel_format_descriptor_ptr=%s)",
               in_hdc,
               in_format,
               GDI32::convert_pixel_format_descriptor_to_raw_string(in_pixel_format_descriptor_ptr) );

    return reinterpret_cast<GDI32::PFNSETPIXELFORMATPROC>(GDI32::g_cached_set_pixel_format_func_ptr)(in_hdc,
                                                                                                     in_format,
                                                                                                     in_pixel_format_descriptor_ptr);
}
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "Common/globals.h"
#include "Common/macros.h"
#include "GDI32/globals.h"
#include "GDI32/entrypoints/choose_pixel_format.h"
#include "GDI32/utils_trace.h"

int WINAPI GDI32::choose_pixel_format(HDC                          in_hdc,
                                      CONST PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr)
{
    VKGL_TRACE("ChoosePixelFormat(\n"
               " in_hdc                         = [%p]\n"
               " in_pixel_format_descriptor_ptr = %s)",
               in_hdc,
               GDI32::convert_pixel_format_descriptor_to_raw_string(in_pixel_format_descriptor_ptr) );

    return reinterpret_cast<GDI32::PFNCHOOSEPIXELFORMATPROC>(GDI32::g_cached_choose_pixel_format_func_ptr)(in_hdc,
                                                                                                           in_pixel_format_descriptor_ptr);
}

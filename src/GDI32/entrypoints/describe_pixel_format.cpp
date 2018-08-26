/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "Common/macros.h"
#include "GDI32/globals.h"
#include "GDI32/entrypoints/describe_pixel_format.h"

int WINAPI GDI32::describe_pixel_format(HDC                     in_hdc,
                                        int                     in_n_pixel_format,
                                        UINT                    in_n_bytes,
                                        LPPIXELFORMATDESCRIPTOR out_pixel_format_descriptor_ptr)
{
    VKGL_TRACE("DescribePixelFormat(in_hdc=[%p], in_n_pixel_format=[%d], in_n_bytes=[%d], out_pixel_format_descriptor_ptr=[%p])",
               in_hdc,
               in_n_pixel_format,
               in_n_bytes,
               out_pixel_format_descriptor_ptr);

    return reinterpret_cast<GDI32::PFNDESCRIBEPIXELFORMATPROC>(GDI32::g_cached_describe_pixel_format_func_ptr)(in_hdc,
                                                                                                               in_n_pixel_format,
                                                                                                               in_n_bytes,
                                                                                                               out_pixel_format_descriptor_ptr);
}
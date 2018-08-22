/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include <Windows.h>
#include "GDI32/globals.h"

void* g_cached_choose_pixel_format_func_ptr   = ChoosePixelFormat;
void* g_cached_describe_pixel_format_func_ptr = DescribePixelFormat;
void* g_cached_get_pixel_format_func_ptr      = GetPixelFormat;
void* g_cached_set_pixel_format_func_ptr      = SetPixelFormat;
void* g_cached_swap_buffers_func_ptr          = SwapBuffers;

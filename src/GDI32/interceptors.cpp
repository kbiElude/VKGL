/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "GDI32/entrypoints/choose_pixel_format.h"
#include "GDI32/entrypoints/describe_pixel_format.h"
#include "GDI32/entrypoints/get_pixel_format.h"
#include "GDI32/entrypoints/set_pixel_format.h"
#include "GDI32/entrypoints/swap_buffers.h"
#include "GDI32/globals.h"
#include "GDI32/interceptors.h"

std::vector<FunctionInterceptor> get_gdi32_function_interceptors()
{
    return std::vector<FunctionInterceptor>
    {
        FunctionInterceptor(&(PVOID&)g_cached_choose_pixel_format_func_ptr,   vkgl_choose_pixel_format),
        FunctionInterceptor(&(PVOID&)g_cached_describe_pixel_format_func_ptr, vkgl_describe_pixel_format),
        FunctionInterceptor(&(PVOID&)g_cached_get_pixel_format_func_ptr,      vkgl_get_pixel_format),
        FunctionInterceptor(&(PVOID&)g_cached_set_pixel_format_func_ptr,      vkgl_set_pixel_format),
        FunctionInterceptor(&(PVOID&)g_cached_swap_buffers_func_ptr,          vkgl_swap_buffers)
    };
}
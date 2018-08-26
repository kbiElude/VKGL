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

std::vector<VKGL::FunctionInterceptor> GDI32::get_function_interceptors()
{
    return std::vector<VKGL::FunctionInterceptor>
    {
        VKGL::FunctionInterceptor(&(PVOID&)GDI32::g_cached_choose_pixel_format_func_ptr,   GDI32::choose_pixel_format),
        VKGL::FunctionInterceptor(&(PVOID&)GDI32::g_cached_describe_pixel_format_func_ptr, GDI32::describe_pixel_format),
        VKGL::FunctionInterceptor(&(PVOID&)GDI32::g_cached_get_pixel_format_func_ptr,      GDI32::get_pixel_format),
        VKGL::FunctionInterceptor(&(PVOID&)GDI32::g_cached_set_pixel_format_func_ptr,      GDI32::set_pixel_format),
        VKGL::FunctionInterceptor(&(PVOID&)GDI32::g_cached_swap_buffers_func_ptr,          GDI32::swap_buffers)
    };
}
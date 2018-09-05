/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "WGL/entrypoints/WGL_ARB_create_context/wgl_create_context_attribs_arb.h"
#include "WGL/entrypoints/wgl_copy_context.h"
#include "WGL/entrypoints/wgl_create_context.h"
#include "WGL/entrypoints/wgl_create_layer_context.h"
#include "WGL/entrypoints/wgl_delete_context.h"
#include "WGL/entrypoints/wgl_get_current_context.h"
#include "WGL/entrypoints/wgl_get_current_dc.h"
#include "WGL/entrypoints/wgl_get_proc_address.h"
#include "WGL/entrypoints/wgl_make_current.h"
#include "WGL/entrypoints/wgl_share_lists.h"
#include "WGL/entrypoints/wgl_swap_layer_buffers.h"
#include "WGL/globals.h"
#include "WGL/interceptors.h"

std::vector<VKGL::FunctionInterceptor> WGL::get_function_interceptors()
{
    return std::vector<VKGL::FunctionInterceptor>
    {
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_copy_context_func_ptr,         WGL::copy_context),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_create_context_func_ptr,       WGL::create_context),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_create_layer_context_func_ptr, WGL::create_layer_context),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_delete_context_func_ptr,       WGL::delete_context),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_get_current_context_func_ptr,  WGL::get_current_context),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_get_current_dc_func_ptr,       WGL::get_current_dc),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_get_proc_address_func_ptr,     WGL::get_proc_address),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_make_current_func_ptr,         WGL::make_current),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_share_lists_func_ptr,          WGL::share_lists),
        VKGL::FunctionInterceptor(&(PVOID&) WGL::g_cached_swap_layer_buffers_func_ptr,   WGL::swap_layer_buffers),
    };
}
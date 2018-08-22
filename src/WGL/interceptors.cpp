/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "WGL/entrypoints/WGL_ARB_create_context/wgl_create_context_attribs_arb.h"
#include "WGL/entrypoints/wgl_copy_context.h"
#include "WGL/entrypoints/wgl_create_context.h"
#include "WGL/entrypoints/wgl_create_layer_context.h"
#include "WGL/entrypoints/wgl_delete_context.h"
#include "WGL/entrypoints/wgl_describe_layer_plane.h"
#include "WGL/entrypoints/wgl_get_current_context.h"
#include "WGL/entrypoints/wgl_get_current_dc.h"
#include "WGL/entrypoints/wgl_get_proc_address.h"
#include "WGL/entrypoints/wgl_make_current.h"
#include "WGL/entrypoints/wgl_share_lists.h"
#include "WGL/entrypoints/wgl_swap_layer_buffers.h"
#include "WGL/globals.h"
#include "WGL/interceptors.h"

std::vector<FunctionInterceptor> get_wgl_function_interceptors()
{
    return std::vector<FunctionInterceptor>
    {
        FunctionInterceptor(&(PVOID&) g_cached_wgl_copy_context_func_ptr,         vkgl_wgl_copy_context),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_create_context_func_ptr,       vkgl_wgl_create_context),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_create_layer_context_func_ptr, vkgl_wgl_create_layer_context),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_delete_context_func_ptr,       vkgl_wgl_delete_context),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_describe_layer_plane_func_ptr, vkgl_wgl_describe_layer_plane),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_get_current_context_func_ptr,  vkgl_wgl_get_current_context),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_get_current_dc_func_ptr,       vkgl_wgl_get_current_dc),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_get_proc_address_func_ptr,     vkgl_wgl_get_proc_address),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_make_current_func_ptr,         vkgl_wgl_make_current),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_share_lists_func_ptr,          vkgl_wgl_share_lists),
        FunctionInterceptor(&(PVOID&) g_cached_wgl_swap_layer_buffers_func_ptr,   vkgl_wgl_swap_layer_buffers),
    };
}
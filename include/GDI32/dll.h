/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

__declspec(thread) extern void* g_cached_choose_pixel_format_func_ptr;
__declspec(thread) extern void* g_cached_describe_pixel_format_func_ptr;
__declspec(thread) extern void* g_cached_get_pixel_format_func_ptr;
__declspec(thread) extern void* g_cached_set_pixel_format_func_ptr;
__declspec(thread) extern void* g_cached_swap_buffers_func_ptr;
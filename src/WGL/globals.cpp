/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "WGL/globals.h"

void* g_cached_wgl_copy_context_func_ptr         = wglCopyContext;
void* g_cached_wgl_create_context_func_ptr       = wglCreateContext;
void* g_cached_wgl_create_layer_context_func_ptr = wglCreateLayerContext;
void* g_cached_wgl_delete_context_func_ptr       = wglDeleteContext;
void* g_cached_wgl_describe_layer_plane_func_ptr = wglDescribeLayerPlane;
void* g_cached_wgl_get_current_context_func_ptr  = wglGetCurrentContext;
void* g_cached_wgl_get_current_dc_func_ptr       = wglGetCurrentDC;
void* g_cached_wgl_get_proc_address_func_ptr     = wglGetProcAddress;
void* g_cached_wgl_make_current_func_ptr         = wglMakeCurrent;
void* g_cached_wgl_share_lists_func_ptr          = wglShareLists;
void* g_cached_wgl_swap_layer_buffers_func_ptr   = wglSwapLayerBuffers;

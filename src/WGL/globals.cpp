/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "WGL/context.h"
#include "WGL/globals.h"

void* WGL::g_cached_copy_context_func_ptr         = wglCopyContext;
void* WGL::g_cached_create_context_func_ptr       = wglCreateContext;
void* WGL::g_cached_create_layer_context_func_ptr = wglCreateLayerContext;
void* WGL::g_cached_delete_context_func_ptr       = wglDeleteContext;
void* WGL::g_cached_get_current_context_func_ptr  = wglGetCurrentContext;
void* WGL::g_cached_get_current_dc_func_ptr       = wglGetCurrentDC;
void* WGL::g_cached_get_proc_address_func_ptr     = wglGetProcAddress;
void* WGL::g_cached_make_current_func_ptr         = wglMakeCurrent;
void* WGL::g_cached_share_lists_func_ptr          = wglShareLists;
void* WGL::g_cached_swap_layer_buffers_func_ptr   = wglSwapLayerBuffers;

VKGL_THREADLOCAL WGL::Context* WGL::g_current_wgl_context_ptr = nullptr;
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_GLOBALS_H
#define WGL_GLOBALS_H

#include <windows.h>
#include "Common/globals.h"

namespace WGL
{
    /* Forward declarations */
    class Context;

    typedef BOOL  (WINAPI* PFNWGLCOPYCONTEXTPROC)            (HGLRC, HGLRC, UINT);
    typedef HGLRC (WINAPI* PFNWGLCREATECONTEXTPROC)          (HDC);
    typedef HGLRC (WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, const int*);
    typedef HGLRC (WINAPI* PFNWGLCREATELAYERCONTEXTPROC)     (HDC, int);
    typedef BOOL  (WINAPI* PFNWGLDELETECONTEXTPROC)          (HGLRC);
    typedef HGLRC (WINAPI* PFNWGLGETCURRENTCONTEXTPROC)      ();
    typedef HDC   (WINAPI* PFNWGLGETCURRENTDCPROC)           ();
    typedef PROC  (WINAPI* PFNWGLGETPROCADDRESSPROC)         (LPCSTR);
    typedef BOOL  (WINAPI* PFNWGLMAKECURRENTPROC)            (HDC, HGLRC);
    typedef BOOL  (WINAPI* PFNWGLSHARELISTSPROC)             (HGLRC, HGLRC);
    typedef BOOL  (WINAPI* PFNWGLSWAPLAYERBUFFERSPROC)       (HDC, UINT);

    extern void* g_cached_copy_context_func_ptr;
    extern void* g_cached_create_context_attribs_arb_func_ptr;
    extern void* g_cached_create_context_func_ptr;
    extern void* g_cached_create_layer_context_func_ptr;
    extern void* g_cached_delete_context_func_ptr;
    extern void* g_cached_get_current_context_func_ptr;
    extern void* g_cached_get_current_dc_func_ptr;
    extern void* g_cached_get_proc_address_func_ptr;
    extern void* g_cached_make_current_func_ptr;
    extern void* g_cached_share_lists_func_ptr;
    extern void* g_cached_swap_layer_buffers_func_ptr;

    VKGL_THREADLOCAL extern Context* g_current_wgl_context_ptr;
}

#endif /* WGL_GLOBALS_H */
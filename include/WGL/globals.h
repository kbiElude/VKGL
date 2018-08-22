/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_GLOBALS_H
#define WGL_GLOBALS_H

#include <windows.h>

typedef BOOL  (WINAPI* PFNWGLCOPYCONTEXTPROC)       (HGLRC, HGLRC, UINT);
typedef HGLRC (WINAPI* PFNWGLCREATECONTEXTPROC)     (HDC);
typedef HGLRC (WINAPI* PFNWGLCREATELAYERCONTEXTPROC)(HDC, int);
typedef BOOL  (WINAPI* PFNWGLDELETECONTEXTPROC)     (HGLRC);
typedef BOOL  (WINAPI* PFNWGLDESCRIBELAYERPLANEPROC)(HDC, int, int, UINT, LPLAYERPLANEDESCRIPTOR);
typedef HGLRC (WINAPI* PFNWGLGETCURRENTCONTEXTPROC) ();
typedef HDC   (WINAPI* PFNWGLGETCURRENTDCPROC)      ();
typedef PROC  (WINAPI* PFNWGLGETPROCADDRESSPROC)    (LPCSTR);
typedef BOOL  (WINAPI* PFNWGLMAKECURRENTPROC)       (HDC, HGLRC);
typedef BOOL  (WINAPI* PFNWGLSHARELISTSPROC)        (HGLRC, HGLRC);
typedef BOOL  (WINAPI* PFNWGLSWAPLAYERBUFFERSPROC)  (HDC, UINT);

extern void* g_cached_wgl_copy_context_func_ptr;
extern void* g_cached_wgl_create_context_func_ptr;
extern void* g_cached_wgl_create_layer_context_func_ptr;
extern void* g_cached_wgl_delete_context_func_ptr;
extern void* g_cached_wgl_describe_layer_plane_func_ptr;
extern void* g_cached_wgl_get_current_context_func_ptr;
extern void* g_cached_wgl_get_current_dc_func_ptr;
extern void* g_cached_wgl_get_proc_address_func_ptr;
extern void* g_cached_wgl_make_current_func_ptr;
extern void* g_cached_wgl_share_lists_func_ptr;
extern void* g_cached_wgl_swap_layer_buffers_func_ptr;

#endif /* WGL_GLOBALS_H */
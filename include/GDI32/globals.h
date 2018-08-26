/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef GDI32_GLOBALS_H
#define GDI32_GLOBALS_H

#include <Windows.h>

namespace GDI32
{
    typedef int  (WINAPI *PFNCHOOSEPIXELFORMATPROC)  (HDC, const PIXELFORMATDESCRIPTOR*);
    typedef int  (WINAPI *PFNDESCRIBEPIXELFORMATPROC)(HDC, int, UINT, LPPIXELFORMATDESCRIPTOR);
    typedef int  (WINAPI *PFNGETPIXELFORMATPROC)     (HDC);
    typedef BOOL (WINAPI* PFNSETPIXELFORMATPROC)     (HDC, int, const PIXELFORMATDESCRIPTOR*);
    typedef BOOL (WINAPI* PFNSWAPBUFFERSPROC)        (HDC);

    extern void* g_cached_choose_pixel_format_func_ptr;
    extern void* g_cached_describe_pixel_format_func_ptr;
    extern void* g_cached_get_pixel_format_func_ptr;
    extern void* g_cached_set_pixel_format_func_ptr;
    extern void* g_cached_swap_buffers_func_ptr;
}

#endif /* GDI32_GLOBALS_H */
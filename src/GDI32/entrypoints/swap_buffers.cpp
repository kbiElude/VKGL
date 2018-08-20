/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "GDI32/entrypoints/swap_buffers.h"
#include "GDI32/dll.h"

typedef BOOL (WINAPI* PFNSWAPBUFFERSPROC)(HDC);


BOOL WINAPI vkgl_swap_buffers(HDC in_hdc)
{
    auto func_ptr = reinterpret_cast<PFNSWAPBUFFERSPROC>(g_cached_swap_buffers_func_ptr);

    MessageBox(HWND_DESKTOP,
               "SwapBuffers() intercepted.",
               "",
               MB_OK);

    return func_ptr(in_hdc);
}
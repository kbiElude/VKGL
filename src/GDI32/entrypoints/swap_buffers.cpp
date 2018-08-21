/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "GDI32/entrypoints/swap_buffers.h"
#include "GDI32/globals.h"

BOOL WINAPI vkgl_swap_buffers(HDC in_hdc)
{
    MessageBox(HWND_DESKTOP,
               "SwapBuffers() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNSWAPBUFFERSPROC>(g_cached_swap_buffers_func_ptr)(in_hdc);
}
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_swap_layer_buffers.h"

BOOL WINAPI vkgl_wgl_swap_layer_buffers(HDC  in_hdc,
                                        UINT in_planes)
{
    MessageBox(HWND_DESKTOP,
               "wglSwapLayerBuffers() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLSWAPLAYERBUFFERSPROC>(g_cached_wgl_swap_layer_buffers_func_ptr)(in_hdc,
                                                                                                  in_planes);
}

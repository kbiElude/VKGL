/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_create_layer_context.h"

HGLRC WINAPI vkgl_wgl_create_layer_context(HDC in_hdc,
                                           int in_layer_plane_index)
{
    MessageBox(HWND_DESKTOP,
               "wglCreateLayerContext() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLCREATELAYERCONTEXTPROC>(g_cached_wgl_create_layer_context_func_ptr)(in_hdc,
                                                                                                      in_layer_plane_index);
}

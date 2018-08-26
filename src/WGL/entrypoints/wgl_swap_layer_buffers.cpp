/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_swap_layer_buffers.h"

BOOL WINAPI WGL::swap_layer_buffers(HDC  in_hdc,
                                    UINT in_planes)
{
    VKGL_TRACE("wglSwapLayerBuffers(in_hdc=[%p] in_planes=[%d])",
               in_hdc,
               in_planes);

    return reinterpret_cast<WGL::PFNWGLSWAPLAYERBUFFERSPROC>(WGL::g_cached_swap_layer_buffers_func_ptr)(in_hdc,
                                                                                                        in_planes);
}

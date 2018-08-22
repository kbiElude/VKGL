/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_SWAP_LAYER_BUFFERS_H
#define WGL_SWAP_LAYER_BUFFERS_H

#include <windows.h>

BOOL WINAPI vkgl_wgl_swap_layer_buffers(HDC  in_hdc,
                                        UINT in_planes);

#endif /* WGL_SHARE_LISTS_H */
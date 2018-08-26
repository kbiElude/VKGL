/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_SWAP_BUFFERS_H
#define VKGL_SWAP_BUFFERS_H

#include <Windows.h>

namespace GDI32
{
    BOOL WINAPI swap_buffers(HDC in_hdc);
}

#endif /* VKGL_SWAP_BUFFERS_H */
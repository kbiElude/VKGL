/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_GET_SWAP_INTERVAL_EXT_H
#define WGL_GET_SWAP_INTERVAL_EXT_H

#include <windows.h>

namespace WGL
{
    int WINAPI get_swap_interval_ext();
}

#endif /* WGL_GET_SWAP_INTERVAL_EXT_H */
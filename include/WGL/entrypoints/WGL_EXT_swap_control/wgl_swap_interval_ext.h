/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_SWAP_INTERVAL_EXT_H
#define WGL_SWAP_INTERVAL_EXT_H

#include <windows.h>

namespace WGL
{
    BOOL WINAPI swap_interval_ext(int in_interval);
}

#endif /* WGL_SWAP_INTERVAL_EXT_H */
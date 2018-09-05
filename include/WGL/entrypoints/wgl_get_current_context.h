/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_GET_CURRENT_CONTEXT_H
#define WGL_GET_CURRENT_CONTEXT_H

#include <windows.h>

namespace WGL
{
    HGLRC WINAPI get_current_context();
}

#endif /* WGL_GET_CURRENT_CONTEXT_H */
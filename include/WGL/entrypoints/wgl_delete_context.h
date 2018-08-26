/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_DELETE_CONTEXT_H
#define WGL_DELETE_CONTEXT_H

#include <windows.h>

namespace WGL
{
    BOOL WINAPI delete_context(HGLRC in_hglrc);
}

#endif /* WGL_DELETE_CONTEXT_H */
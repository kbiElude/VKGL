/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_GET_EXTENSIONS_STRING_ARB_H
#define WGL_GET_EXTENSIONS_STRING_ARB_H

#include <windows.h>

namespace WGL
{
    const char* WINAPI get_extensions_string_arb(HDC in_hdc);
}

#endif /* WGL_CREATE_CONTEXT_ATTRIBS_ARB_H */
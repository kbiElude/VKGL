/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_MAKE_CURRENT_H
#define WGL_MAKE_CURRENT_H

#include <windows.h>

BOOL WINAPI vkgl_wgl_make_current(HDC   in_hdc,
                                  HGLRC in_hglrc);

#endif /* WGL_MAKE_CURRENT_H */
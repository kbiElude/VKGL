/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_SHARE_LISTS_H
#define WGL_SHARE_LISTS_H

#include <windows.h>

BOOL WINAPI vkgl_wgl_share_lists(HGLRC in_hglrc1,
                                 HGLRC in_hglrc2);

#endif /* WGL_SHARE_LISTS_H */
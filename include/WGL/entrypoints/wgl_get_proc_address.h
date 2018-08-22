/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_GET_PROC_ADDRESS_H
#define WGL_GET_PROC_ADDRESS_H

#include <windows.h>

PROC WINAPI vkgl_wgl_get_proc_address(LPCSTR in_name);

#endif /* WGL_GET_PROC_ADDRESS_H */
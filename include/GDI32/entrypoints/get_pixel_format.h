/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GET_PIXEL_FORMAT_H
#define VKGL_GET_PIXEL_FORMAT_H

#include <Windows.h>

typedef int (WINAPI *PFNGETPIXELFORMATPROC)(HDC);

int WINAPI vkgl_get_pixel_format(HDC in_hdc);

#endif /* VKGL_GET_PIXEL_FORMAT_H */
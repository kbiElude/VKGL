/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_SET_PIXEL_FORMAT_H
#define VKGL_SET_PIXEL_FORMAT_H

#include <Windows.h>

BOOL WINAPI vkgl_set_pixel_format(HDC                          in_hdc,
                                  int                          in_format,
                                  CONST PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr);

#endif /* VKGL_SET_PIXEL_FORMAT_H */
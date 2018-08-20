/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_DESCRIBE_PIXEL_FORMAT_H
#define VKGL_DESCRIBE_PIXEL_FORMAT_H

#include <windows.h>

int WINAPI vkgl_describe_pixel_format(HDC                     in_hdc,
                                      int                     in_n_pixel_format,
                                      UINT                    in_n_bytes,
                                      LPPIXELFORMATDESCRIPTOR in_pixel_format_descriptor_ptr);

#endif /* VKGL_DESCRIBE_PIXEL_FORMAT_H */
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_DESCRIBE_LAYER_PLANE_H
#define WGL_DESCRIBE_LAYER_PLANE_H

#include <windows.h>

BOOL WINAPI vkgl_wgl_describe_layer_plane(HDC                    in_hdc,
                                          int                    in_pixel_format_index,
                                          int                    in_layer_plane_index,
                                          UINT                   in_n_bytes,
                                          LPLAYERPLANEDESCRIPTOR in_layer_plane_descriptor_ptr);

#endif /* WGL_DELETE_CONTEXT_H */
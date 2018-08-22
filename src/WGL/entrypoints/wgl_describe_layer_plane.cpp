/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_describe_layer_plane.h"

BOOL WINAPI vkgl_wgl_describe_layer_plane(HDC                    in_hdc,
                                          int                    in_pixel_format_index,
                                          int                    in_layer_plane_index,
                                          UINT                   in_n_bytes,
                                          LPLAYERPLANEDESCRIPTOR in_layer_plane_descriptor_ptr)
{
    MessageBox(HWND_DESKTOP,
               "wglDescribeLayerPlane() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLDESCRIBELAYERPLANEPROC>(g_cached_wgl_describe_layer_plane_func_ptr)(in_hdc,
                                                                                                      in_pixel_format_index,
                                                                                                      in_layer_plane_index,
                                                                                                      in_n_bytes,
                                                                                                      in_layer_plane_descriptor_ptr);
}

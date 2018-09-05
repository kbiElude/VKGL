/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "Khronos/GL/glcorearb.h"
#include "Khronos/GL/wglext.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_create_layer_context.h"

HGLRC WINAPI WGL::create_layer_context(HDC in_hdc,
                                       int in_layer_plane_index)
{
    VKGL_TRACE("wglCreateLayerContext(in_hdc=[%p] in_layer_plane_index=[%d])",
               in_hdc,
               in_layer_plane_index);

    const int attribute_list[] =
    {
        WGL_CONTEXT_LAYER_PLANE_ARB, in_layer_plane_index,
        0
    };
    auto      result_ptr       = WGL::Context::create(in_hdc,
                                                      nullptr, /* in_opt_share_context_ptr */
                                                      attribute_list);

    vkgl_assert(result_ptr != nullptr);
    return reinterpret_cast<HGLRC>(result_ptr);
}

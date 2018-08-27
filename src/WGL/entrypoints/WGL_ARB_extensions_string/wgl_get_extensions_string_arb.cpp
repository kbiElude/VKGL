/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/entrypoints/WGL_ARB_extensions_string/wgl_get_extensions_string_arb.h"
#include "WGL/globals.h"
#include "WGL/utils_trace.h"

const char* WINAPI WGL::get_extensions_string_arb(HDC in_hdc)
{
    static const char* result = "WGL_ARB_create_context"         " "
                                "WGL_ARB_create_context_profile" " "
                                "WGL_ARB_extensions_string"      " "
                                "WGL_ARB_framebuffer_sRGB"       " "
                                "WGL_EXT_swap_control";

    VKGL_TRACE("wglGetExtensionsStringARB(in_hdc = [%p])\n",
               in_hdc);

    return result;
}

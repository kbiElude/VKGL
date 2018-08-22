/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/WGL_ARB_create_context/wgl_create_context_attribs_arb.h"

HGLRC WINAPI vkgl_wgl_create_context_attribs_arb(HDC        in_hdc,
                                                 HGLRC      in_share_context_handle,
                                                 const int* in_attrib_list_ptr)
{
    MessageBox(HWND_DESKTOP,
               "wglCreateContextAttribsARB() intercepted - NOT IMPLEMENTED YET",
               "",
               MB_OK);

    return nullptr;
}

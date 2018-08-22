/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_share_lists.h"

BOOL WINAPI vkgl_wgl_share_lists(HGLRC in_hglrc1,
                                 HGLRC in_hglrc2)
{
    MessageBox(HWND_DESKTOP,
               "wglShareLists() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLSHARELISTSPROC>(g_cached_wgl_share_lists_func_ptr)(in_hglrc1,
                                                                                     in_hglrc2);
}

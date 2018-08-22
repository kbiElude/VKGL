/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_copy_context.h"

BOOL WINAPI vkgl_wgl_copy_context(HGLRC in_hglrc_source,
                                  HGLRC in_hglrc_destination,
                                  UINT  in_mask)
{
    MessageBox(HWND_DESKTOP,
               "wglCopyContext() intercepted.",
               "",
               MB_OK);

    return reinterpret_cast<PFNWGLCOPYCONTEXTPROC>(g_cached_wgl_copy_context_func_ptr)(in_hglrc_source,
                                                                                       in_hglrc_destination,
                                                                                       in_mask);
}

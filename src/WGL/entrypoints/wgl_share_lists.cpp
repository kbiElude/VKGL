/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_share_lists.h"

BOOL WINAPI WGL::share_lists(HGLRC in_hglrc1,
                             HGLRC in_hglrc2)
{
    VKGL_TRACE("wglShareLists(in_hglrc1=[%p] in_hglrc2=[%p])",
               in_hglrc1,
               in_hglrc2);

    return reinterpret_cast<WGL::PFNWGLSHARELISTSPROC>(WGL::g_cached_share_lists_func_ptr)(in_hglrc1,
                                                                                           in_hglrc2);
}

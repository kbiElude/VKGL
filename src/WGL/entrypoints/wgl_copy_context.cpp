/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_copy_context.h"

BOOL WINAPI WGL::copy_context(HGLRC in_hglrc_source,
                              HGLRC in_hglrc_destination,
                              UINT  in_mask)
{
    VKGL_TRACE("wglCopyContext(in_hglrc_source=[%p] in_hglrc_destination=[%p] in_mask=[%d])",
               in_hglrc_source,
               in_hglrc_destination,
               in_mask);

    return reinterpret_cast<WGL::PFNWGLCOPYCONTEXTPROC>(WGL::g_cached_copy_context_func_ptr)(in_hglrc_source,
                                                                                             in_hglrc_destination,
                                                                                             in_mask);
}

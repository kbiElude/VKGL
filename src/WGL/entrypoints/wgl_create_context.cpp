/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_create_context.h"

HGLRC WINAPI WGL::create_context(HDC in_hdc)
{
    VKGL_TRACE("wglCreateContext(in_hdc=[%p])",
               in_hdc);

    return reinterpret_cast<WGL::PFNWGLCREATECONTEXTPROC>(WGL::g_cached_create_context_func_ptr)(in_hdc);
}

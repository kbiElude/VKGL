/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/entrypoints/wgl_delete_context.h"
#include "WGL/context.h"
#include "WGL/globals.h"

BOOL WINAPI WGL::delete_context(HGLRC in_hglrc)
{
    VKGL_TRACE("wglDeleteContext(in_hglrc=[%p])",
               in_hglrc);

    delete reinterpret_cast<WGL::Context*>(in_hglrc);
    return TRUE;
}

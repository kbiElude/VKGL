/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_get_current_dc.h"

HDC WINAPI WGL::get_current_dc()
{
    VKGL_TRACE("wglGetCurrentDC()");

    if (WGL::g_current_wgl_context_ptr == nullptr)
    {
        return nullptr;
    }
    else
    {
        return WGL::g_current_wgl_context_ptr->get_current_hdc();
    }
}

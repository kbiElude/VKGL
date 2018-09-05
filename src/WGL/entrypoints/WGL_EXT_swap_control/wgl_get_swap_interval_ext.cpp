/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/entrypoints/WGL_EXT_swap_control/wgl_get_swap_interval_ext.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/utils_trace.h"

int WINAPI WGL::get_swap_interval_ext()
{
    VKGL_TRACE("wglGetSwapIntervalEXT()\n");

    vkgl_assert(WGL::g_current_wgl_context_ptr != nullptr);
    return WGL::g_current_wgl_context_ptr->get_swap_interval();
}

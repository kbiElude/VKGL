/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/entrypoints/WGL_EXT_swap_control/wgl_swap_interval_ext.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/utils_trace.h"

BOOL WINAPI WGL::swap_interval_ext(int in_interval)
{
    VKGL_TRACE("wglGetSwapIntervalEXT(in_interval=[%d])\n",
               in_interval);

    vkgl_assert(WGL::g_current_wgl_context_ptr != nullptr);

    WGL::g_current_wgl_context_ptr->set_swap_interval(in_interval);
    return TRUE;
}

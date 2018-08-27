/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/entrypoints/WGL_EXT_swap_control/wgl_swap_interval_ext.h"
#include "WGL/globals.h"
#include "WGL/utils_trace.h"

BOOL WINAPI WGL::swap_interval_ext(int in_interval)
{
    /* TODO: Needs to be associated with per-thread WGL context. */
    /* TODO: Needs to actually do something! */

    VKGL_TRACE("wglGetSwapIntervalEXT(in_interval=[%d])\n",
               in_interval);

    return TRUE;
}

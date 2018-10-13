/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_swapchain_manager.h"
#include "WGL/entrypoints/WGL_EXT_swap_control/wgl_swap_interval_ext.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/utils_trace.h"

BOOL WINAPI WGL::swap_interval_ext(int in_interval)
{
    VKGL_TRACE("wglSwapIntervalEXT(in_interval=[%d])\n",
               in_interval);

    vkgl_assert(WGL::g_current_wgl_context_ptr != nullptr);

    WGL::g_current_wgl_context_ptr->set_swap_interval                                                   (in_interval);
    WGL::g_current_wgl_context_ptr->get_vk_backend_ptr()->get_swapchain_manager_ptr()->set_swap_interval(in_interval);

    return TRUE;
}

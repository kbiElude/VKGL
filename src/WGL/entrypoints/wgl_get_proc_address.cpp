/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "vkgl_config.h"
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/WGL_ARB_create_context/wgl_create_context_attribs_arb.h"
#include "WGL/entrypoints/wgl_get_proc_address.h"
#include <unordered_map>

PROC WINAPI vkgl_wgl_get_proc_address(LPCSTR in_name)
{
    /* TODO: Cache the func ptr data in HGLRC context */

    todo;

#if defined(INCLUDE_OPENGL)
    const std::unordered_map<std::string, void*> opengl_func_ptrs = opengl32_get_func_name_to_func_ptr_map();
#endif

    static const std::unordered_map<std::string, void*> wgl_func_ptrs =
    {
        /* WGL_ARB_create_context */
        {"wglCreateContextAttribsARB", vkgl_wgl_create_context_attribs_arb},
    };

    const std::unordered_map<std::string, void*> func_ptr_data[] =
    {
#if defined(INCLUDE_OPENGL)
        opengl_func_ptrs,
#endif
        wgl_func_ptrs,
    };

    for (const auto& current_func_map : func_ptr_data)
    {
    }
    return reinterpret_cast<PFNWGLGETPROCADDRESSPROC>(g_cached_wgl_get_proc_address_func_ptr)(in_name);
}

/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "vkgl_config.h"
#include "Common/globals.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/WGL_ARB_create_context/wgl_create_context_attribs_arb.h"
#include "WGL/entrypoints/WGL_ARB_extensions_string/wgl_get_extensions_string_arb.h"
#include "WGL/entrypoints/WGL_EXT_swap_control/wgl_get_swap_interval_ext.h"
#include "WGL/entrypoints/WGL_EXT_swap_control/wgl_swap_interval_ext.h"
#include "WGL/entrypoints/wgl_get_proc_address.h"
#include <unordered_map>

#if defined(VKGL_INCLUDE_OPENGL)
    #include "OpenGL/interceptors.h"
#endif

PROC WINAPI WGL::get_proc_address(LPCSTR in_name)
{
    VKGL_TRACE("wglGetProcAddress(in_name=[%s])",
               in_name);

    /* TODO: Cache the func ptr data in HGLRC context */

    PROC result = nullptr;

#if defined(VKGL_INCLUDE_OPENGL)
    const auto opengl_func_ptrs = OpenGL::get_func_name_to_func_ptr_map();
#endif

    static const std::unordered_map<std::string, void*> wgl_func_ptrs =
    {
        /* WGL_ARB_create_context */
        {"wglCreateContextAttribsARB", WGL::create_context_attribs_arb},

        /* WGL_ARB_extensions_string */
        {"wglGetExtensionsStringARB", WGL::get_extensions_string_arb},

        /* WGL_EXT_swap_control */
        {"wglGetSwapIntervalEXT", WGL::get_swap_interval_ext},
        {"wglSwapIntervalEXT",    WGL::swap_interval_ext},
    };

    const std::unordered_map<std::string, void*> func_ptr_data[] =
    {
#if defined(VKGL_INCLUDE_OPENGL)
        opengl_func_ptrs,
#endif
        wgl_func_ptrs,
    };

    for (const auto& current_func_map : func_ptr_data)
    {
        auto iterator = current_func_map.find(in_name);

        if (iterator != current_func_map.end() )
        {
            result = reinterpret_cast<PROC>(iterator->second);

            break;
        }
    }

    return result;
}

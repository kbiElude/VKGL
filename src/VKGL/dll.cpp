/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "vkgl_config.h"
#include <Windows.h>
#include <vector>
#include "../deps/Detours/src/detours.h"

#if defined(VKGL_INCLUDE_GDI32)
    #include "GDI32/interceptors.h"
#endif

#if defined(VKGL_INCLUDE_WGL)
    #include "WGL/interceptors.h"
#endif

const std::vector<VKGL::FunctionInterceptor> g_function_interceptors[] =
{
#if defined(VKGL_INCLUDE_GDI32)
    GDI32::get_function_interceptors(),
#endif
#if defined(VKGL_INCLUDE_WGL)
    WGL::get_function_interceptors(),
#endif
};


__declspec(dllexport) void dummy()
{
    /* Dummy function which has to be associated with ordinal 1 for Detours to work correctly. */
}

void handle_attach_detach_event(const bool& in_is_attach_event)
{
    const auto current_thread_handle = ::GetCurrentThread();

    if (in_is_attach_event)
    {
        ::DetourRestoreAfterWith();
    }

    for (auto& current_func_set : g_function_interceptors)
    {
        for (auto& current_func_data : current_func_set)
        {
            ::DetourTransactionBegin();
            ::DetourUpdateThread    (current_thread_handle);

            if (in_is_attach_event)
            {
                ::DetourAttach(current_func_data.pfn_func_to_intercept_ptr_ptr,
                               current_func_data.pfn_interceptor_func_ptr);
            }
            else
            {
                ::DetourDetach(current_func_data.pfn_func_to_intercept_ptr_ptr,
                               current_func_data.pfn_interceptor_func_ptr);
            }

            if (::DetourTransactionCommit() != NO_ERROR)
            {
                MessageBox(HWND_DESKTOP,
                           "DetourTransactionCommit() failed",
                           "Error",
                           MB_OK | MB_ICONERROR);
            }
        }
    }
}

INT APIENTRY DllMain(HMODULE in_module_handle,
                     DWORD   in_reason,
                     LPVOID  in_unused)
{
    if (DetourIsHelperProcess() )
    {
        return TRUE;
    }

    switch(in_reason)
    {
        case DLL_PROCESS_ATTACH:
        {
            handle_attach_detach_event(true); /* in_is_attach_event */

            break;
        }

        case DLL_PROCESS_DETACH:
        {
            handle_attach_detach_event(false); /* in_is_attach_event */

            break;
        }

        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        {
            break;
        }
    }

    return TRUE;
}

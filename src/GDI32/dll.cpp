/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "GDI32/dll.h"
#include <Windows.h>

#include "GDI32/entrypoints/choose_pixel_format.h"
#include "GDI32/entrypoints/describe_pixel_format.h"
#include "GDI32/entrypoints/get_pixel_format.h"
#include "GDI32/entrypoints/set_pixel_format.h"
#include "GDI32/entrypoints/swap_buffers.h"

#include "../deps/Detours/src/detours.h"


const void* g_cached_choose_pixel_format_func_ptr   = ChoosePixelFormat;
const void* g_cached_describe_pixel_format_func_ptr = DescribePixelFormat;
const void* g_cached_get_pixel_format_func_ptr      = GetPixelFormat;
const void* g_cached_set_pixel_format_func_ptr      = SetPixelFormat;
const void* g_cached_swap_buffers_func_ptr          = SwapBuffers;

__declspec(dllexport) void dummy_function()
{
    /* Dummy function which has to be associated with ordinal 1 for Detours to work correctly. */
}

void handle_attach_detach_event(const bool& in_is_attach_event)
{
    const auto current_thread_handle = ::GetCurrentThread();

    struct
    {
        PVOID* detoured_func_ptr;
        void*  new_func_ptr;
    } funcs_to_detour[] =
    {
        {&(PVOID&)g_cached_choose_pixel_format_func_ptr,   vkgl_choose_pixel_format},
        {&(PVOID&)g_cached_describe_pixel_format_func_ptr, vkgl_describe_pixel_format},
        {&(PVOID&)g_cached_get_pixel_format_func_ptr,      vkgl_get_pixel_format},
        {&(PVOID&)g_cached_set_pixel_format_func_ptr,      vkgl_set_pixel_format},
        {&(PVOID&)g_cached_swap_buffers_func_ptr,          vkgl_swap_buffers}
    };

    if (in_is_attach_event)
    {
        ::DetourRestoreAfterWith();
    }

    for (auto& current_func_data : funcs_to_detour)
    {
        ::DetourTransactionBegin();
        ::DetourUpdateThread    (current_thread_handle);

        if (in_is_attach_event)
        {
            ::DetourAttach(current_func_data.detoured_func_ptr,
                           current_func_data.new_func_ptr);
        }
        else
        {
            ::DetourDetach(current_func_data.detoured_func_ptr,
                           current_func_data.new_func_ptr);
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

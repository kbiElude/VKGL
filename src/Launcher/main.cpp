/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include <Windows.h>
#include "Detours/src/detours.h"

int main()
{
    char*               path_to_gdi32_proxy = "./gdi32_proxy.dll";
    char*               path_to_executable  = "TestApp.exe";
    PROCESS_INFORMATION process_info;
    STARTUPINFO         startup_info;

    memset(&process_info,
           0,
           sizeof(process_info) );
    memset(&startup_info,
           0,
           sizeof(startup_info) );

    startup_info.cb = sizeof(startup_info);

    if (::DetourCreateProcessWithDllA(nullptr, /* lpApplicationName */
                                      static_cast<LPSTR>(path_to_executable),
                                      nullptr, /* lpProcessAttributes */
                                      nullptr, /* lpThreadAttributes  */
                                      FALSE,   /* bInheritHandles     */
                                      CREATE_DEFAULT_ERROR_MODE,
                                      nullptr, /* lpEnvironment      */
                                      nullptr, /* lpCurrentDirectory */
                                      &startup_info,
                                      &process_info,
                                      path_to_gdi32_proxy,
                                      nullptr) != TRUE) /* pfCreateProcessA */
    {
        ::MessageBox(HWND_DESKTOP,
                     "Error spawning test app process",
                     "Error",
                     MB_OK | MB_ICONERROR);
    }

    return EXIT_SUCCESS;
}
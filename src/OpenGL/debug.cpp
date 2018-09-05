/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/debug.h"
#include <assert.h>
#include <stdio.h>

#if defined(_WIN32)
    #include <Windows.h>
#endif

void VKGL::Debug::assert_failed(const char*  in_filename,
                                unsigned int in_line,
                                const char*  in_message)
{
    /* todo: make me more useful */
    fprintf(stderr,
            "[!] %s:%d:[%s]\n",
            in_filename,
            in_line,
            in_message);

    #if defined(_WIN32) && defined(_DEBUG)
    {
        if (::IsDebuggerPresent() )
        {
            __debugbreak();
        }
    }
    #endif

    assert(false);
}
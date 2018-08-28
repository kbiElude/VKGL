/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/debug.h"
#include "Common/logger.h"

void VKGL::Debug::assert_failed(const char*  in_filename,
                                unsigned int in_line,
                                const char*  in_message)
{
    VKGL_LOG(VKGL::LogLevel::Error,
             "[!] Assertion failure in %s at %d: [%s]",
            in_filename,
            in_line,
            in_message);

    #if defined(_DEBUG)
    {
        #if defined(_WIN32)
        {
            _CrtDbgBreak();
        }
        #else
        {
            #error TODO
        }
        #endif
    }
    #endif
}
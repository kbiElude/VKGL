/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_LOGGER_H
#define VKGL_LOGGER_H

#include "vkgl_config.h"


namespace VKGL
{
    enum class LogLevel
    {
        APIDump,
        Error,
        Info,
        Warning,

        Unknown
    };

    class Logger
    {
    public:
         Logger();
        ~Logger();

        void log(const LogLevel& in_log_level,
                 const char*     in_message_template,
                 ...);
    };

    extern Logger* g_logger_ptr;
}

#define VKGL_LOG(level, message_template, ...) \
    VKGL::g_logger_ptr->log(level, message_template, __VA_ARGS__)

#if defined(VKGL_DUMP_API_CALLS)
    #define VKGL_TRACE(message_template, ...) \
        VKGL::g_logger_ptr->log(VKGL::LogLevel::APIDump, message_template, __VA_ARGS__)
#else
    #define VKGL_TRACE(message_template, ...)
#endif

#endif /* VKGL_LOGGER_H */
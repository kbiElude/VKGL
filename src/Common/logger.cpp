/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/io.h"
#include "Common/globals.h"
#include "Common/logger.h"
#include "Common/macros.h"

#define LOG_FILE_NAME "VKGL_log.txt"


/* TODO: Writes must be flushed asynchronously, every once in a while. Right now,
 *       cached trace data is only written at dll detach time!
 */
VKGL::Logger* VKGL::g_logger_ptr = nullptr;


VKGL::Logger::Logger()
{
    Anvil::IO::delete_file(LOG_FILE_NAME);
}

VKGL::Logger::~Logger()
{
    Anvil::IO::write_text_file(LOG_FILE_NAME,
                               g_logger_ptr->m_log_data_sstream.str() );
}

void VKGL::Logger::deinit()
{
    vkgl_assert(g_logger_ptr != nullptr);

    if (g_logger_ptr != nullptr)
    {
        delete g_logger_ptr;
        g_logger_ptr = nullptr;
    }
}

void VKGL::Logger::init()
{
    vkgl_assert(g_logger_ptr == nullptr);

    g_logger_ptr = new VKGL::Logger();

    vkgl_assert(g_logger_ptr != nullptr);
}

void VKGL::Logger::log(const LogLevel& in_log_level,
                       const char*     in_message_template,
                       ...)
{
    va_list args;
    char    temp[MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE];

    va_start(args,
             in_message_template);
    {
        vsprintf_s<sizeof(temp)>(temp,
                                 in_message_template,
                                 args);
    }
    va_end(args);

    m_log_data_sstream << temp
                       << "\n";

    /* TODO: Writes should be async and triggered every now and then, only if needed!
     *
     * This mechanism is only needed for initial VKGL bring-up. Remove as soon as no longer
     * required.
     */
    {
        Anvil::IO::write_text_file(LOG_FILE_NAME,
                                   g_logger_ptr->m_log_data_sstream.str(),
                                   true); /* in_should_append */

        g_logger_ptr->m_log_data_sstream = std::stringstream();
    }
}


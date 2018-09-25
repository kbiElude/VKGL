/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_scheduler.h"
#include "Common/logger.h"

#define N_MAX_SCHEDULED_COMMANDS_LOG_2 (16)
#define WAIT_PERIOD_MS                 (1000)

OpenGL::VKScheduler::VKScheduler()
    :m_terminating(false)
{
}

OpenGL::VKScheduler::~VKScheduler()
{
    /* Set a terminate flag and wait for the scheduler thread to quit */
    if (m_scheduler_thread_ptr != nullptr)
    {
        m_terminating.exchange(true);

        m_scheduler_thread_ptr->join();
    }

    /* Only after the thread dies, can we release the ring buffer instance. */
    m_command_ring_buffer_ptr.reset();
}

OpenGL::VKSchedulerUniquePtr OpenGL::VKScheduler::create()
{
    OpenGL::VKSchedulerUniquePtr result_ptr;

    result_ptr.reset(
        new OpenGL::VKScheduler()
    );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

bool OpenGL::VKScheduler::init()
{
    bool result = false;

    /* 1. Instantiate the ring buffer. */
    m_command_ring_buffer_ptr.reset(
        new VKGL::RingBuffer<CommandBaseUniquePtr>(N_MAX_SCHEDULED_COMMANDS_LOG_2)
    );

    if (m_command_ring_buffer_ptr == nullptr)
    {
        vkgl_assert(m_command_ring_buffer_ptr != nullptr);

        goto end;
    }

    /* 2. Spawn the scheduler's main thread.. */
    m_scheduler_thread_ptr.reset(
        new std::thread(
            std::bind(&OpenGL::VKScheduler::main_thread_entrypoint,
                      this)
        )
    );

    if (m_scheduler_thread_ptr == nullptr)
    {
        vkgl_assert(m_scheduler_thread_ptr != nullptr);

        goto end;
    }

    /* Done! */
    result = true;
end:
    return result;
}

void OpenGL::VKScheduler::main_thread_entrypoint()
{
    /* NOTE: This entrypoint lives in its own dedicated thread */
    VKGL::g_logger_ptr->log(VKGL::LogLevel::Info,
                            "VK scheduler thread started.");

    do
    {
        OpenGL::CommandBaseUniquePtr command_ptr;

        if (!m_command_ring_buffer_ptr->grab_with_timeout(std::chrono::milliseconds(WAIT_PERIOD_MS),
                                                         &command_ptr) )
        {
            /* Time-out occurred, no commands have been submitted throughout the duration of the wait period..
             *
             * Check if the scheduler is winding up. If so, close the thread. Otherwise, keep on trying to
             * obtain a new command to process.
             */
            if (m_terminating.load() )
            {
                break;
            }

            continue;
        }

        process_command(std::move(command_ptr) );
    }
    while (true);

    VKGL::g_logger_ptr->log(VKGL::LogLevel::Info,
                            "VK scheduler thread quitting now.");
}

void OpenGL::VKScheduler::process_command(OpenGL::CommandBaseUniquePtr in_command_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKScheduler::submit(OpenGL::CommandBaseUniquePtr in_command_ptr)
{
    /* NOTE: This entrypoint is called from application thread. */
    vkgl_assert(m_command_ring_buffer_ptr != nullptr);

    m_command_ring_buffer_ptr->stash(std::move(in_command_ptr) );
}
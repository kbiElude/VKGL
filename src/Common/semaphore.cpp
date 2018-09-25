/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common\semaphore.h"

/* NOTE: Shamelessly based on https://stackoverflow.com/questions/4792449/c0x-has-no-semaphores-how-to-synchronize-threads */


VKGL::Semaphore::Semaphore(const uint32_t& in_start_count)
    :m_count(in_start_count)
{
    /* Stub */
}

VKGL::Semaphore::~Semaphore()
{
    /* Stub */
}

void VKGL::Semaphore::signal()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    ++m_count;

    m_condition.notify_one();
}

void VKGL::Semaphore::wait()
{
     std::unique_lock<std::mutex> lock(m_mutex);

     /* Handle spurious wake-ups. */
     while (m_count == 0)
     {
         m_condition.wait(lock);
     }

     --m_count;
}

bool VKGL::Semaphore::wait_with_timeout(std::chrono::milliseconds in_timeout)
{
    std::unique_lock<std::mutex> lock      (m_mutex);
    bool                         result    (false);
    const auto                   time_start(std::chrono::system_clock::now() );

     /* Handle spurious wake-ups. */
     while (m_count == 0)
     {
         /* TODO: In case of a spurious wake-up, we should adjust the timeout used for subsequent attempt. */
         if (m_condition.wait_for(lock,
                                  in_timeout) == std::cv_status::timeout)
         {
             goto end;
         }
     }

     --m_count;

     result = true;
 end:
     return result;
}
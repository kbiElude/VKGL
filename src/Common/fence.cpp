/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common\fence.h"


VKGL::Fence::Fence()
    :m_flag(false)
{
    /* Stub */
}

VKGL::Fence::~Fence()
{
    /* Stub */
}

void VKGL::Fence::signal()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_flag = true;

    m_condition.notify_one();
}

void VKGL::Fence::wait()
{
     std::unique_lock<std::mutex> lock(m_mutex);

     /* Handle spurious wake-ups. */
     while (!m_flag)
     {
         m_condition.wait(lock);
     }
}

bool VKGL::Fence::wait_with_timeout(std::chrono::milliseconds in_timeout)
{
    std::unique_lock<std::mutex> lock      (m_mutex);
    bool                         result    (false);
    const auto                   time_start(std::chrono::system_clock::now() );

     /* Handle spurious wake-ups. */
     while (!m_flag)
     {
         /* TODO: In case of a spurious wake-up, we should adjust the timeout used for subsequent attempt. */
         if (m_condition.wait_for(lock,
                                  in_timeout) == std::cv_status::timeout)
         {
             goto end;
         }
     }

     result = true;
 end:
     return result;
}
/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_COMMON_SEMAPHORE_H
#define VKGL_COMMON_SEMAPHORE_H

#include <chrono>
#include <condition_variable>
#include <mutex>

/* NOTE: Shamelessly based on https://stackoverflow.com/questions/4792449/c0x-has-no-semaphores-how-to-synchronize-threads */
namespace VKGL
{
    class Semaphore
    {
    public:
        /* Public functions */
         Semaphore(const uint32_t& in_start_count = 0);
        ~Semaphore();

        void signal           ();
        void wait             ();
        bool wait_with_timeout(std::chrono::milliseconds in_timeout);

    private:
        /* Private variables */
        std::condition_variable m_condition;
        uint32_t                m_count;
        std::mutex              m_mutex;

        /* Private functions */

        Semaphore           (const Semaphore&);
        Semaphore& operator=(const Semaphore&);
    };
};

#endif /* VKGL_COMMON_SHARED_MUTEX_H */